#pragma once

#include "ms/error.h"
#include <string>

namespace cgo {

ms::Error RunProgram(const std::string &path);

}