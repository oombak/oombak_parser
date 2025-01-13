#pragma once

#include <cstdint>

#ifdef _WIN32
#define OOMBAK_PARSER_EXPORT __declspec(dllexport)
#else
#define OOMBAK_PARSER_EXPORT
#endif

enum SignalType {
  Input,
  Output,
  Local,
};

struct Signal {
  const char *name;
  SignalType type;
  uint64_t width;
};

struct Instance {
  const char *name;
  const char *module_name;
  Instance *parent_instance;
  Instance **child_instances;
  uint64_t child_instances_len;
  Signal *signals;
  uint64_t signals_len;
};

typedef void *OombakCtx;

OOMBAK_PARSER_EXPORT OombakCtx oombak_parser_get_ctx();

OOMBAK_PARSER_EXPORT Instance *oombak_parser_parse(const char *source_paths,
                                                   const char *top_module_name);

OOMBAK_PARSER_EXPORT Instance *oombak_parser_parse(OombakCtx ctx,
                                                   const char *source_paths,
                                                   const char *top_module_name);

OOMBAK_PARSER_EXPORT bool oombak_parser_free_ctx(OombakCtx context);
