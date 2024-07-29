#include "ReadFile.hpp"

int main() {
  try {
    ReadFile a("test.txt");
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  
}