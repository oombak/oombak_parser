#include "oombak_parser.h"
#include <cstddef>

OOMBAK_PARSER_EXPORT OombakCtx oombak_parser_get_ctx() { return NULL; }

OOMBAK_PARSER_EXPORT bool oombak_parser_free_ctx(OombakCtx context) {
  return false;
}

OOMBAK_PARSER_EXPORT Instance *
oombak_parser_parse(const char **source_paths, const char *top_module_name) {
  return NULL;
}

OOMBAK_PARSER_EXPORT Instance *
oombak_parser_parse(OombakCtx ctx, const char **source_paths,
                    const char *top_module_name) {
  return NULL;
}
