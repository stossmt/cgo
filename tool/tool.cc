#include <cstdio>

#include <fmt/core.h>

namespace cgo {

void DoTool() { fmt::print("Hello, {}!\n", "other"); }

} // namespace cgo