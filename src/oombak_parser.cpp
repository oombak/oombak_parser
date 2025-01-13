#include "oombak_parser.h"

#include "slang/ast/Compilation.h"
#include <cstdlib>
#include <string_view>

using slang::ast::Compilation;

std::vector<std::string_view>
from_colon_separated_paths(const char *colon_separated_paths);

class OombakParser {
public:
  OombakParser();
  Instance *get_instance_tree(const std::vector<std::string_view> &source_paths,
                              std::string_view top_module_name);

private:
  Instance root_instance;
};

static OombakParser *parser = new OombakParser();

OOMBAK_PARSER_EXPORT OombakCtx oombak_parser_get_ctx() {
  return new OombakParser();
}

OOMBAK_PARSER_EXPORT void oombak_parser_free_ctx(OombakCtx ctx) {
  auto parser = (OombakParser *)ctx;
  delete parser;
}

OOMBAK_PARSER_EXPORT Instance *
oombak_parser_parse(const char *source_paths, const char *top_module_name) {
  std::vector<std::string_view> source_paths_vec =
      from_colon_separated_paths(source_paths);
  return parser->get_instance_tree(source_paths_vec, top_module_name);
}

OOMBAK_PARSER_EXPORT Instance *
oombak_parser_parse(OombakCtx ctx, const char *source_paths,
                    const char *top_module_name) {
  auto parser = (OombakParser *)ctx;
  std::vector<std::string_view> source_paths_vec =
      from_colon_separated_paths(source_paths);
  return parser->get_instance_tree(source_paths_vec, top_module_name);
}

OombakParser::OombakParser() {}

Instance *OombakParser::get_instance_tree(
    const std::vector<std::string_view> &source_paths,
    std::string_view top_module_name) {
  return NULL;
}

std::vector<std::string_view>
from_colon_separated_paths(const char *colon_separated_paths) {
  std::vector<std::string_view> result;
  uint64_t input_length = strlen(colon_separated_paths);
  uint64_t last_idx = -1;
  for (int i = 0; i <= input_length; i++) {
    if (i == input_length || colon_separated_paths[i] == ':') {
      result.push_back(std::basic_string_view(
          &colon_separated_paths[last_idx + 1], &colon_separated_paths[i]));
      last_idx = i;
    }
  }
  return result;
}
