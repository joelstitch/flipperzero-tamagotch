#pragma once

#include <tamalib.h>

// "T" — picked because it's the first letter of the app id.
#define TAMA_SAVE_MAGIC_BYTE 0x54
#define TAMA_SAVE_VERSION     1

#define TAMA_SAVE_DIR  EXT_PATH("apps_data/tamagotchi_p1")
#define TAMA_SAVE_PATH TAMA_SAVE_DIR "/pet.save"

// Persist the live emulator memory buffer to `path`. Callers must ensure the
// worker thread has stopped and `g_state_mutex` is uncontested.
bool tama_app_save_write(const char* path);

// Restore the emulator memory buffer from `path`. No-op (returns false) when
// the file is missing or invalid — the emulator keeps its freshly-initialized
// memory buffer. Callers must invoke before the worker thread is started.
bool tama_app_save_read(const char* path);
