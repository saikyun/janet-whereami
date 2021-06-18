#include <janet.h>
#include "whereami/src/whereami.h"

static Janet cfun_getExecutablePath(int32_t argc, Janet *argv) {
  (void) argv;
  janet_fixarity(argc, 0);
  int length = wai_getExecutablePath(NULL, 0, NULL);
  uint8_t *path = janet_string_begin(length);
  wai_getExecutablePath((char *)path, length, NULL);

  return janet_wrap_string(janet_string_end(path));
}

// I included this for completion
// I think it might always give the path to the .so-file
// compiled from this c-file (e.g. JANET_PATH/whereami.so or similar)
// but at least you could copy this function
// into some other c-file, and it might make more sense
static Janet cfun_getModulePath(int32_t argc, Janet *argv) {
  (void) argv;
  janet_fixarity(argc, 0);
  int length = wai_getModulePath(NULL, 0, NULL);
  uint8_t *path = janet_string_begin(length);
  wai_getModulePath((char *)path, length, NULL);

  return janet_wrap_string(janet_string_end(path));
}

static const JanetReg cfuns[] = {
  {"get-executable-path", cfun_getExecutablePath, "(get-executable-path)"},
  {"get-module-path", cfun_getModulePath, "(get-module-path)"},
  {NULL, NULL, NULL}
};

JANET_MODULE_ENTRY(JanetTable *env) {
  janet_cfuns (env, "whereami", cfuns);
}
