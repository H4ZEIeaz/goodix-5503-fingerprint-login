[English](README.md) | [Русский](README.ru.md)

# goodix-5503-fingerprint-login

Fingerprint login on Linux for the Goodix `27c6:5503` sensor.

## Status

A working prototype. `sudo` and screen unlock work by fingerprint. The first login
at the display manager does not, and the password is always available as a
fallback, so a failed read or a stopped daemon cannot lock anyone out.

| Scenario | Works | Why |
|---|---|---|
| `sudo` in a terminal | yes | the user session and the daemon are already running |
| Screen unlock through PAM, for example hyprlock | yes | the session is active and the daemon holds the device |
| First login at the display manager greeter | no, password | the daemon starts after login, so no user session exists at the greeter yet |

Measured on a small test set: FAR about zero, impostor touches produced zero
correspondences. This is a result on that set, not a general accuracy claim.

## Important: bring your own DLL

`GoodixEngineAdapter.dll` is Goodix's proprietary algorithm library. It is not in
this repository. Obtain it from an installed Windows Goodix fingerprint driver for
your laptop, then copy it to:

```
re/GoodixEngineAdapter.dll
```

## How it works

```
USB and TLS-PSK capture, Python
      -> fpsvc under Wine, loads GoodixEngineAdapter.dll
      -> correspondence count, read via an INT3 software breakpoint
      -> fpd daemon, Python, your user
      -> fp_pam.py, root helper
      -> PAM
```

The vendor export `identifyImage` always returns a negative score of -100 unless
its full adaptive enrollment and maturity lifecycle is reproduced, which is
impractical to call directly. The discrimination, however, is computed earlier:
the number of matched feature correspondences at the `cmp $0x4,%edi` in
`FUN_18009f4a0`. A genuine touch produces many correspondences, an impostor
produces zero, before the scoring and maturity gates. The daemon reads that count
with a software breakpoint and uses it directly as the match decision. Details and
the decompiled references are in [re/research/](re/research/).

## Requirements

- The Goodix `27c6:5503` sensor, with write access to its USB device node through
  a udev rule or a group.
- Python 3.11+ and the dependencies from requirements.txt: pyusb, numpy, scipy, pillow.
- Wine, tested on 11.x, to run the matcher.
- mingw-w64, the `x86_64-w64-mingw32-gcc` compiler, to build `fpsvc.exe` and the stub DLL.
- Your own `GoodixEngineAdapter.dll`.
- Ghidra and pyghidra are needed only for the research scripts.

## Installation

### 1. Clone

```bash
git clone https://github.com/H4ZEIeaz/goodix-5503-fingerprint-login.git
cd goodix-5503-fingerprint-login
```

### 2. Python environment

```bash
python3 -m venv .venv
. .venv/bin/activate
pip install -r requirements.txt
```

### 3. Add the DLL

Copy your own `GoodixEngineAdapter.dll` into `re/`, as described above.

### 4. Build the matcher and the stub DLL

```bash
cd re
x86_64-w64-mingw32-gcc -shared stub.c stub.def -o api-ms-win-core-debug-minidump-l1-1-0.dll
x86_64-w64-mingw32-gcc fpsvc.c -o fpsvc.exe
cd ..
```

### 5. Calibrate

Keep the sensor empty. This produces `re/frames/base.raw` and `re/frames/calidata.blob`.

```bash
./.venv/bin/python calibrate.py
```

### 6. Enroll a finger

About 15 touches, covering the whole pad.

```bash
./.venv/bin/python fp_enroll.py thumb
```

### 7. Verify

```bash
./.venv/bin/python fp_verify.py thumb
```

## Daemon

The daemon holds the device and the matcher, so each verify is one touch instead
of about 5 s of Wine startup. Install it as a user service. If the repository is
not at `~/goodix-5503-fingerprint-login`, edit the two paths in `fpd.service` first.
The unit runs the `thumb` template with threshold 3. For a different template name,
edit `ExecStart`.

```bash
mkdir -p ~/.config/systemd/user
cp fpd.service ~/.config/systemd/user/
systemctl --user daemon-reload
systemctl --user enable --now fpd.service
```

Health check:

```bash
python3 -c "import socket,os; s=socket.socket(socket.AF_UNIX); s.connect(os.path.expandvars('$XDG_RUNTIME_DIR/fpd.sock')); s.send(b'PING\n'); print(s.recv(16))"
```

### Socket protocol

The daemon listens on `$XDG_RUNTIME_DIR/fpd.sock`, one request per connection:

| Request | Reply |
|---|---|
| `PING` | `OK` |
| `AUTH` | `ACCEPT corr=N`, `REJECT ...`, or `ERR ...` |
| `AUTH <timeout> <retries>` | as above, timeout 1 to 30 s, retries 1 to 5 |

## PAM

Edit PAM carefully. Keep a root shell open and a backup, for example
`cp /etc/pam.d/sudo /etc/pam.d/sudo.bak`, and know how to reach a text console with
Ctrl+Alt+F2. The `sufficient` plus password layout cannot lock the user out, but a
malformed line in the `auth` stack can, so test in a second terminal.

`fp_pam.py` is a small stdlib-only root helper. It asks the daemon over the socket
and exits 0 to accept or 1 to fall through to the password. Add this line as the
very first auth line, above every other auth and include line, in
`/etc/pam.d/sudo` and, if wanted, in `/etc/pam.d/hyprlock`:

```
auth sufficient pam_exec.so quiet /ABSOLUTE/PATH/TO/fp_pam.py
```

Placed first as `sufficient`, a fingerprint match is enough, and any failure falls
through to the password modules below. Then test in a second terminal:

```bash
sudo -k; sudo echo ok
```

### Options

| Option | Meaning |
|---|---|
| `--timeout S` | seconds the daemon waits for a finger per attempt |
| `--retries N` | finger attempts before falling back to the password, default 3 |
| exit 0 | fingerprint accepted |
| exit 1 | rejected or unavailable, the password prompt follows |

The target account comes from `$PAM_USER`.

## Security and privacy

- Enrolled templates, captured frames and the DLL are never committed. They are
  listed in `.gitignore`. A template is biometric data.
- Calibration is device-specific and contains an empty-sensor reference, no
  fingerprint. It is generated by `calibrate.py` and is git-ignored.
- Dual boot: booting Windows makes its Goodix driver re-provision the device PSK,
  so Linux capture then fails until the community PSK is restored. The capture code
  does this automatically with one write to device NVM, which is reversible. If the
  device already has the community PSK, nothing is written. Otherwise the same
  community PSK is written in white-box form.
- The PSK constants in `capture_bio_5503.py` are the public community PSK, not secrets.

## Reference

Environment variables:

| Variable | Default | Effect |
|---|---|---|
| `FP_THRESHOLD` | 3 | minimum correspondence count to accept |
| `FP_TEMPLATE` | template.bin | template path, relative to `re/` |
| `GOODIX_CLEAR_ONLY` | unset | stop after the calibration frames, no finger |
| `GOODIX_BG_FRAMES` | 10 | empty-sensor baseline frames |
| `GOODIX_FP_FRAMES` | 12 | finger frames in a burst |

Finger detection uses a threshold of 150 per pixel and requires 1500 differing pixels.

`fpsvc.exe` commands, run from `re/` under Wine:

| Command | Action |
|---|---|
| `fpsvc enroll <dir>` | enroll every `<dir>/*.raw` into the template |
| `fpsvc verify <probe.raw>` | match a probe against the template |
| `fpsvc serve` | persistent mode, reads raw frames from stdin |

Output lines have the form `RESULT corr=N verdict=ACCEPT` or `verdict=REJECT`.

## Repository layout

```
capture_bio_5503.py   USB and in-process TLS-PSK capture, never erases or reflashes
capture_multi.py      sensor setup and averaged press capture
goodix.py             vendored protocol library, MIT, see NOTICE
protocol.py           vendored protocol library, MIT, see NOTICE
tool.py               vendored protocol library, MIT, see NOTICE
driver_5503.py        upstream reference, not used at runtime
calibrate.py          capture an empty frame, build base.raw and calidata.blob
fp_enroll.py          enroll a finger into a template
fp_verify.py          interactive verify
fp_auth.py            standalone verify without the daemon
fp_try.py             interactive daemon test
fpd.py                auth daemon, holds the device and matcher, Unix socket
fp_pam.py             root PAM helper, stdlib only
fpd.service           systemd user unit, edit the paths
re/fpsvc.c            the Wine-side matcher, enroll, verify and serve
re/stub.c re/stub.def minidump stub for a missing Wine import
re/build_calidata.py  calibration blob builder, with a byte-exact self-test
re/research/          reverse-engineering provenance, harnesses and decompilations
```

## Limitations

- The proprietary vendor DLL is required at runtime through Wine. This is a bridge,
  not a clean driver.
- No fingerprint at the display manager greeter. The daemon is per user and starts
  after login. `sudo` and screen unlock work.
- Prototype-level testing. The password fallback is the safety net.

## Roadmap

The reusable parts are the correspondence-count insight and a byte-exact oracle for
the 5503, since the Wine harness reproduces the DLL byte for byte. That is what
[goodix53x5-libfprint](https://github.com/seaweeduk/goodix53x5-libfprint) used to
build a native Milan port for other Goodix sensors. A native 5503 port, with no DLL
at runtime and integrated with libfprint, is the clean goal. This repository is the
foothold, see [re/research/](re/research/).

## Credits and license

This project is MIT, author H4ZEIeaz, see [LICENSE](LICENSE). The vendored protocol
code is from goodix-fp-linux-dev/goodix-fp-dump under MIT, see [NOTICE](NOTICE).
Algorithm context is from seaweeduk/aitorcalero goodix53x5-libfprint.

The reverse engineering here is for interoperability with hardware you own. No
Goodix binaries are distributed. Respect your Windows driver's license when
extracting the DLL for your own use.
