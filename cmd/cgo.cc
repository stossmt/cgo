#include "compiler/runner.h"

int main() {
  cgo::RunProgram("testing/main.go");
  return 0;
}