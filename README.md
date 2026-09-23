Tamagotchi P1 Emulator for Flipper Zero
=======================================

This is a Tamagotchi P1 Emulator app for Flipper Zero, based on [TamaLIB](https://github.com/jcrona/tamalib/).

Changelog
---------
### Unreleased
- **Save / load**: pet life state (age, hunger, happiness, weight, discipline,
  generation, etc.) is now persisted to `apps_data/tamagotchi_p1/pet.save` on
  the SD card when you exit the app, and restored when you relaunch. The
  emulator resumes your pet at the same life stage it was at when you closed
  the app. Built on `saved_struct` from the firmware toolbox (magic + version
  + checksum).
- **Build fixes for current SDK**: replaced deprecated `m-string` with
  `FuriString` in `hal.c`; adapted input/timer callbacks to the current SDK's
  `void*` context signatures; `hal_log` is now allocation-free (stack buffer
  + `vsnprintf`).

How to play
-----------
Create a `tama_p1` folder in your microSD card, and put the ROM as `rom.bin`.
Left button is A, OK is B, and right button is C. Hold the back button to exit.
Your tamagotchi's life state is saved automatically on exit and restored on
next launch.

Implemented
-----------
- Basic emulation
- Input
- Sound
- Saving / loading (single slot, auto-saved on exit)

To-do
-----
- Multiple save slots
- In-game reset
- Test mode?
- Volume adjustment
