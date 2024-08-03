#include "compiler/runner.h"
#include "fmt/core.h"

int main() {
  ms::Error result = cgo::RunProgram("testing/main.go");
  if (!result.ok()) {
    fmt::println("Error: {}", result.message());
    return 1;
  }
  return 0;
}