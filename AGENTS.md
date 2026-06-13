# AGENTS.md — KLOR Keyboard Repo

## What this repo is
Firmware (QMK/Vial, ZMK) for the KLOR split keyboard.
The main deliverables are compiled firmware `.uf2` files.

## Repo layout
```
FIRMWARE/         All firmware sources
  qmk_rp2040/       QMK for RP2040 (wired, Vial-compatible)
  zmk/              ZMK for Nice!Nano V2 (wireless BLE)
  Ready-to-flash/   Pre-compiled .uf2 files
```

## Firmware — QMK (RP2040)
Location: `FIRMWARE/qmk_rp2040/electronlab/klor/`
- **Keyboard JSON**: `keyboard.json` is the single source of truth for matrix, pins, features, layouts. Do not duplicate pin defs in `config.h` unless necessary.
- **Keymaps**: Two keymaps exist:
  - `default/` — basic QMK keymap
  - `vial/` — Vial-enabled keymap (runtime configuration via web app)
- **Vial config**: `keymaps/vial/vial.json` defines the Vial UI layout. `klor.vil` is the default keymap layer state exported from Vial.
- **OLED**: Custom OLED code with `klor_face` bitmap. OLED font is `./lib/glcdfont.c`.
- **Development board**: `elite_pi` in `keyboard.json`. MCU is RP2040.
- **Serial**: Half duplex by default (`GP1`). See `config.h` for full duplex options.

## Firmware — ZMK (Nice!Nano V2)
Location: `FIRMWARE/zmk/`
- Wireless BLE firmware. Wireless build is separate; see `build.yaml` for ZMK build config.
- ZMK has its own GitHub Actions repo at `Lefuneste83/zmk-config-klor`.

## Build commands
QMK (requires `qmk` CLI):
```bash
# Default keymap — produces separate left/right files
qmk compile -kb electronlab/klor -km default -c -e OPT_DEFS+=-DINIT_EE_HANDS_LEFT
qmk compile -kb electronlab/klor -km default -c -e OPT_DEFS+=-DINIT_EE_HANDS_RIGHT

# Vial keymap — produces separate left/right files (requires vial-qmk fork)
qmk compile -kb electronlab/klor -km vial -c -e OPT_DEFS+=-DINIT_EE_HANDS_LEFT
qmk compile -kb electronlab/klor -km vial -c -e OPT_DEFS+=-DINIT_EE_HANDS_RIGHT
```

Flashing (split keyboard, flash each side separately):
```bash
# Left side
qmk flash -kb electronlab/klor -km default -c -bl uf2-split-left
# Right side
qmk flash -kb electronlab/klor -km default -c -bl uf2-split-right
# Vial variants use -km vial instead
```

## CI
- GitHub Actions: `.github/workflows/build.yml`
- Triggered only on changes to `FIRMWARE/**`
- Uses `qmk setup -y -b vial vial-kb/vial-qmk` (the VIAL-QMK fork is required for the Vial keymap)

## Architecture notes
- **Split keyboard**: 8 rows × 6 cols matrix. Left half = rows 0-3, right half = rows 4-7.
- **Handedness**: Firmware-based (`EE_HANDS` in `config.h`). Each half knows its side via EEPROM.
- **Encoders**: Two encoders (left on GP28/GP29, right with swapped pins). Defined in `keyboard.json`.
- **OLED**: 128x64 SSD1306, rotated 180°. `SPLIT_OLED_ENABLE` syncs OLED state across halves.
- **Features currently disabled in this fork**: RGB matrix, audio, haptics. The hardware supports them but they are stripped from the firmware to reduce size and complexity. Do not re-enable without checking RP2040 flash/RAM constraints.

## Important constraints
- **Do not use `WS2812_DRIVER` or `AUDIO_DRIVER` in `rules.mk`** — these features are disabled globally.
- **QMK `keyboard.json` is the canonical source** for matrix pins, features, and layouts. `config.h` should only override things JSON cannot express.
- **Vial keymap must not use hardcoded layer names** in `keymap.c` — the layer names are for OLED display only; actual layers are configured via Vial web app.
- **COMBO_COUNT**: Must match the actual number of combos defined in `keymap.c` (currently 5 in `default/`).
- **TAPPING_TERM**: 300ms in both keymaps. `TAPPING_FORCE_HOLD` is enabled.
- **OLED bitmap `klor_face`**: Massive PROGMEM byte array (≈430 bytes). If editing `keymap.c`, be careful with special characters — use Python or sed for automated edits, not direct string replacement through JSON.

## Pre-commit sanity check
Before committing firmware changes:
1. Verify `keyboard.json` parses as valid JSON
2. Check brace matching in `keymap.c` (especially after editing the `klor_face` array)
3. Ensure `COMBO_COUNT` matches actual combo definitions
4. Confirm `VIAL_KEYBOARD_UID` in `config.h` is unchanged (it must match `vial.json`)

## References
- `FIRMWARE.md` — detailed flash commands and serial config options
