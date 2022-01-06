#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main(int Argc, const char **Argv) {

  assert(Argc == 2 && "invalid number of arguments\n");

  std::vector<std::string> Args(Argv, Argv + Argc);

  // clang-format off
  std::cout << "  .globl main\n"
            << "main:\n"
            << "  li a0, " << Args[1] << "\n"
            << "  ret\n";
  // clang-format on

  return 0;
}
