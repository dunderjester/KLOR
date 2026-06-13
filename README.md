# KLOR Keyboard Firmware

Firmware sources and pre-compiled binaries for the KLOR split keyboard.

## Firmware

This repo contains the following firmware:

- **QMK (RP2040)** — Wired, Vial-compatible
  - `FIRMWARE/qmk_rp2040/electronlab/klor/`
  - Keymaps: `default/`, `vial/`
  - Pre-compiled: `FIRMWARE/Ready-to-flash/qmk-RP2040/`

- **ZMK (Nice!Nano V2)** — Wireless BLE
  - `FIRMWARE/zmk/`
  - Pre-compiled: `FIRMWARE/Ready-to-flash/zmk-NiceNanoV2/`

## Build

See [FIRMWARE.md](FIRMWARE.md) for flashing instructions and build commands.

## CI

GitHub Actions automatically compiles both `default` and `vial` QMK keymaps on every push to `FIRMWARE/**`.

## License

See [LICENSE.md](LICENSE.md).
