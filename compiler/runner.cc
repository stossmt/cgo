#include <string>

#include "compiler/runner.h"
#include "compiler/scanner.h"
#include "fmt/core.h"
#include "ms/file.h"

namespace cgo {

void RunProgram(const std::string &path) {
  std::string contents = ms::ReadFile(path);
  fmt::print("Running program: {}\n", contents);
  Scan();
}

} // namespace cgo