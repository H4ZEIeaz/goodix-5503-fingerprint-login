#!/usr/bin/env python3
"""Interactive test of the fpd daemon: sends AUTH and prompts when to touch.

  python3 fp_try.py [user]
"""
import os
import sys
import time
import socket

target = os.environ.get("PAM_USER") or (sys.argv[1] if len(sys.argv) > 1 else "")
if target:
    import pwd
    try:
        uid = pwd.getpwnam(target).pw_uid
    except KeyError:
        sys.exit(f"no such user: {target}")
else:
    uid = os.getuid()
sock_path = f"/run/user/{uid}/fpd.sock"
if not os.path.exists(sock_path):
    sys.exit(f"no daemon socket at {sock_path}, is fpd running?")

print("\n=== Goodix fingerprint daemon test ===")
print("1. Make sure the sensor is EMPTY.")
try:
    input("   Press Enter when the sensor is clear... ")
except EOFError:
    pass

s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
s.settimeout(80)
s.connect(sock_path)
s.sendall(b"AUTH 10 3\n")

print("2. Capturing empty-sensor baseline, keep it CLEAR.")
time.sleep(1.5)
print("\n   TOUCH AND HOLD your finger NOW. If it fails, lift and touch")
print("   again, up to 3 tries, then it replies.\n")

try:
    data = s.recv(64).decode(errors="replace").strip()
except socket.timeout:
    data = "timeout, no reply"
s.close()

print("   daemon says:", data)
if data.startswith("ACCEPT"):
    print("\n   MATCH, fingerprint accepted")
    sys.exit(0)
else:
    print("\n   no match, REJECT or no finger")
    sys.exit(1)
