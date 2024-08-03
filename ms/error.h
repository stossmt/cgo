// This header contains the Error type and utilities for working with it,
// since this codebase tries to not use exceptions.
#pragma once

#include <string>

#include "fmt/core.h"

// Macro to unwrap an ErrorOr and return the error if it's not OK.
#define TRY(error_or)                                                          \
  ({                                                                           \
    auto _error_or = (error_or);                                               \
    if (!_error_or.ok()) {                                                     \
      return _error_or.error();                                                \
    }                                                                          \
    _error_or.value();                                                         \
  })

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

class [[nodiscard]] Error {
public:
  Error(const std::string &message, ErrorCode code)
      : message_(message), code_(code) {}

  static Error Ok() { return Error("", ErrorCode::OK); }

#define DEFINE_ERROR_FUNCTION(name, code)                                      \
  template <typename... Args>                                                  \
  static Error name(fmt::format_string<Args...> format_str, Args &&...args) {  \
    return Error(fmt::format(format_str, std::forward<Args>(args)...), code);  \
  }

  DEFINE_ERROR_FUNCTION(Cancelled, ErrorCode::CANCELLED)
  DEFINE_ERROR_FUNCTION(Unknown, ErrorCode::UNKNOWN)
  DEFINE_ERROR_FUNCTION(InvalidArgument, ErrorCode::INVALID_ARGUMENT)
  DEFINE_ERROR_FUNCTION(DeadlineExceeded, ErrorCode::DEADLINE_EXCEEDED)
  DEFINE_ERROR_FUNCTION(NotFound, ErrorCode::NOT_FOUND)
  DEFINE_ERROR_FUNCTION(AlreadyExists, ErrorCode::ALREADY_EXISTS)
  DEFINE_ERROR_FUNCTION(PermissionDenied, ErrorCode::PERMISSION_DENIED)
  DEFINE_ERROR_FUNCTION(ResourceExhausted, ErrorCode::RESOURCE_EXHAUSTED)
  DEFINE_ERROR_FUNCTION(FailedPrecondition, ErrorCode::FAILED_PRECONDITION)
  DEFINE_ERROR_FUNCTION(Aborted, ErrorCode::ABORTED)
  DEFINE_ERROR_FUNCTION(OutOfRange, ErrorCode::OUT_OF_RANGE)
  DEFINE_ERROR_FUNCTION(Unimplemented, ErrorCode::UNIMPLEMENTED)
  DEFINE_ERROR_FUNCTION(Internal, ErrorCode::INTERNAL)
  DEFINE_ERROR_FUNCTION(Unavailable, ErrorCode::UNAVAILABLE)
  DEFINE_ERROR_FUNCTION(DataLoss, ErrorCode::DATA_LOSS)

  bool ok() const { return code_ == ErrorCode::OK; }
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

  bool ok() const { return error_.ok(); }
  const T &value() const { return value_; }

private:
  Error error_;
  T value_;
};

} // namespace ms