#include "Token.hpp"
#include <cassert>
#include <cctype>
#include <iostream>
#include <vector>

int main(int Argc, const char **Argv) {

  assert(Argc == 2 && "invalid number of arguments\n");

  std::vector<std::string> Args(Argv, Argv + Argc);

  // 生成token树
  auto Tok = tokenize(Args[1]);

  // 输出汇编的前缀
  auto Prefix = "  ";

  std::cout << Prefix << ".globl main\n"
            << "main:\n"
            // 输出第一个数字，初始化a0
            << Prefix << "add a0, x0, " << Tok->getValue() << "\n";
  Tok = Tok->getNext();

  while (Tok->getKind() != TK_EOF) {
    // 解析   （punct, num)  的结构
    if (Tok->isPunct('+') || Tok->isPunct('-')) {
      std::cout << Prefix << "add a0, a0, " << (Tok->isPunct('-') ? "-" : "");
      Tok = Tok->getNext();
      std::cout << Tok->getValue() << "\n";
      Tok = Tok->getNext();
      continue;
    }
  }

  std::cout << Prefix << "ret" << std::endl;

  return 0;
}
