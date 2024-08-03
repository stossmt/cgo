#include <string>

#include "compiler/runner.h"
#include "compiler/scanner.h"
#include "fmt/core.h"
#include "ms/file.h"

namespace cgo {

using ::ms::ErrorOr;
using ::ms::ReadFile;

void RunProgram(const std::string &path) {
  ErrorOr<std::string> contents = ReadFile(path);
  if (contents.ok()) {
    fmt::println("Successfully read file: {}", contents.value());
  } else {
    fmt::println("{}", contents.error().message());
  }

  Scan();
}

} // namespace cgo