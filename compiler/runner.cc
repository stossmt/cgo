#include <string>

#include "compiler/runner.h"
#include "compiler/scanner.h"
#include "fmt/core.h"
#include "ms/error.h"
#include "ms/file.h"

namespace cgo {

using ::ms::Error;
using ::ms::ErrorCode;
using ::ms::ErrorOr;
using ::ms::ReadFile;

Error RunProgram(const std::string &path) {
  std::string contents = TRY(ReadFile(path));
  fmt::println("Contents: {}", contents);

  Scan();

  return Error::Ok();
}

} // namespace cgo