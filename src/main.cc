#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main(int Argc, const char **Argv) {

  assert(Argc == 2 && "invalid number of arguments\n");

  std::vector<std::string> Args(Argv, Argv + Argc);

  std::cout << "  .globl main\n"
            << "main:\n"
            << "  addi a0, zero, ";
  for (auto Ch : Args[1]) {
    if ('0' <= Ch && Ch <= '9')
      std::cout << Ch;
    if (Ch == '+')
      std::cout << "\n  addi a0, a0, ";
    if (Ch == '-')
      std::cout << "\n  addi a0, a0, -";
  }
  std::cout << "\n  ret" << std::endl;

  return 0;
}
