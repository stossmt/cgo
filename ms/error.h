// This header contains the Error type and utilities for working with it,
// since this codebase tries to not use exceptions.
#pragma once

#include <string>

#include "fmt/core.h"

namespace ms {

enum class ErrorCode {
  OK = 0,
  CANCELLED = 1,
  UNKNOWN = 2,
  INVALID_ARGUMENT = 3,
  DEADLINE_EXCEEDED = 4,
  NOT_FOUND = 5,
  ALREADY_EXISTS = 6,
  PERMISSION_DENIED = 7,
  UNAUTHENTICATED = 16,
  RESOURCE_EXHAUSTED = 8,
  FAILED_PRECONDITION = 9,
  ABORTED = 10,
  OUT_OF_RANGE = 11,
  UNIMPLEMENTED = 12,
  INTERNAL = 13,
  UNAVAILABLE = 14,
  DATA_LOSS = 15,
  DO_NOT_USE = 999,
};

class Error {
public:
  Error(const std::string &message, ErrorCode code)
      : message_(message), code_(code) {}

  const std::string &message() const { return message_; }
  ErrorCode code() const { return code_; }

private:
  std::string message_;
  ErrorCode code_;
};

template <typename T> class ErrorOr {
public:
  ErrorOr(const Error &error) : error_(error) {}
  ErrorOr(const T &value) : error_("", ErrorCode::OK), value_(value) {}

  const Error &error() const { return error_; }

  bool ok() const { return error_.code() == ErrorCode::OK; }
  const T &value() const { return value_; }

private:
  Error error_;
  T value_;
};

} // namespace ms