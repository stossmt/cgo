// This header contains APIs for manipulating files and directories.
#pragma once

#include <string>

namespace ms {

// @return The contents of the file.
std::string ReadFile(const std::string &path);

} // namespace ms