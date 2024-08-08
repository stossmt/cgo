#include <string>

#include "compiler/runner.h"
#include "compiler/scanner.h"
#include "fmt/core.h"
#include "ms/error.h"
#include "ms/file.h"
#include "ms/vector.h"

namespace cgo {

using ::ms::Error;
using ::ms::ErrorCode;
using ::ms::ErrorOr;
using ::ms::ReadFile;
using ::ms::Vector;

Error RunProgram(const std::string &path) {
  std::string contents = TRY(ReadFile(path));
  fmt::println("Contents: {}", contents);

  Vector<char> vec("hello world!");
  for (const auto &ch : vec) {
    fmt::println("{}", ch);
  }

  Scan();

  return Error::Ok();
}

} // namespace cgo