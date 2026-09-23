#include "tama_save.h"
#include "tama.h"
#include <furi.h>
#include <storage/storage.h>
#include <toolbox/saved_struct.h>

static bool tama_app_save_ensure_dir(void) {
    Storage* storage = furi_record_open(RECORD_STORAGE);
    bool ok = storage_simply_mkdir(storage, TAMA_SAVE_DIR);
    furi_record_close(RECORD_STORAGE);
    return ok;
}

bool tama_app_save_read(const char* path) {
    state_t* state = tamalib_get_state();

    if(furi_mutex_acquire(g_state_mutex, FuriWaitForever) != FuriStatusOk) return false;
    bool ok = saved_struct_load(
        path, state->memory, MEM_BUFFER_SIZE, TAMA_SAVE_MAGIC_BYTE, TAMA_SAVE_VERSION);
    furi_mutex_release(g_state_mutex);
    return ok;
}

bool tama_app_save_write(const char* path) {
    if(!tama_app_save_ensure_dir()) {
        FURI_LOG_E(TAG, "Failed to create save dir %s", TAMA_SAVE_DIR);
        return false;
    }

    state_t* state = tamalib_get_state();

    if(furi_mutex_acquire(g_state_mutex, FuriWaitForever) != FuriStatusOk) return false;
    bool ok = saved_struct_save(
        path, state->memory, MEM_BUFFER_SIZE, TAMA_SAVE_MAGIC_BYTE, TAMA_SAVE_VERSION);
    furi_mutex_release(g_state_mutex);
    return ok;
}
