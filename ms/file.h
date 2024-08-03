// This header contains APIs for manipulating files and directories.
#pragma once

#include <string>

#include "ms/error.h"

namespace ms {

// @return The contents of the file.
ErrorOr<std::string> ReadFile(const std::string &path);

} // namespace ms