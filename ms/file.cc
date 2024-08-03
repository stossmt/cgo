#include <ms/file.h>

namespace ms {

std::string ReadFile(const std::string &path) {
  std::string contents;
  FILE *file = fopen(path.c_str(), "r");
  if (file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    contents.resize(size);
    fread(&contents[0], 1, size, file);
    fclose(file);
  }
  return contents;
}

} // namespace ms