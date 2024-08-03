#include <ms/file.h>

namespace ms {

ErrorOr<std::string> ReadFile(const std::string &path) {
  FILE *file = fopen(path.c_str(), "r");
  if (file) {
    std::string contents;
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    contents.resize(size);
    fread(&contents[0], 1, size, file);
    fclose(file);
    return contents;
  }
  return Error("Failed to read file: " + path, ErrorCode::NOT_FOUND);
}

} // namespace ms