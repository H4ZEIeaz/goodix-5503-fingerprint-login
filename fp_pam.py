#!/usr/bin/env python3
"""PAM fingerprint helper: asks the fpd daemon over its socket, runs as root.

  python3 fp_pam.py [--timeout S] [--retries N] [user]
"""
import os
import sys
import pwd
import socket


def pop_opt(args, name, lo, hi, cast):
    """Pull "--name V" out of args, clamped to [lo,hi], else None."""
    if name not in args:
        return None
    i = args.index(name)
    val = None
    try:
        val = max(lo, min(hi, cast(args[i + 1])))
    except (IndexError, ValueError):
        val = None
    del args[i:i + 2]
    return val


DEFAULT_RETRIES = 3

args = sys.argv[1:]
timeout = pop_opt(args, "--timeout", 1.0, 30.0, float)
retries = pop_opt(args, "--retries", 1, 5, int) or DEFAULT_RETRIES

user = os.environ.get("PAM_USER") or (args[0] if args else "")
if not user:
    sys.exit(1)
try:
    uid = pwd.getpwnam(user).pw_uid
except KeyError:
    sys.exit(1)

sock_path = f"/run/user/{uid}/fpd.sock"
if not os.path.exists(sock_path):
    sys.exit(1)

to = timeout if timeout is not None else 10.0
req = f"AUTH {to:g} {retries}\n".encode()

try:
    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    s.settimeout(to * retries * 2 + 10)
    s.connect(sock_path)
    s.sendall(req)
    data = s.recv(64)
    s.close()
except Exception:
    sys.exit(1)

sys.exit(0 if data.startswith(b"ACCEPT") else 1)
