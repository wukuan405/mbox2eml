#include <iostream>
#include <cstring>
#include <fstream>

const std::string FILENAME_PREFIX = "mbox2eml-out-";
const std::string FILENAME_EXTENSION = ".eml";

int main(int argc, char** argv) {
  std::string line;
  std::string from;

  std::fstream file;
  std::string filename;
  int index = 0;

  filename = FILENAME_PREFIX + std::to_string(index) + FILENAME_EXTENSION;
  file.open(filename, std::ios::out);

  if (! file) { std::cerr << "[E] Can not open file" << std::endl; return 1; }

  while (std::cin.good()) {
    std::getline(std::cin, line);
    from = line.substr(0, 5);
    if (from.compare("From ") == 0) {
      file.close();
      ++index;
      filename = FILENAME_PREFIX + std::to_string(index) + FILENAME_EXTENSION;
      file.open(filename, std::ios::out);
      if (! file) { std::cerr << "[E] Can not open file" << std::endl; return 1; }
      file << line << std::endl;
    }
    else {
      file << line << std::endl;
    }
  }

  file.close();

  return 0;
}