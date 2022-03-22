#include "Token.hpp"

#include <iostream>

void errorAt(const std::string &Str, std::string::const_iterator Ptr,
             std::string Message) {
  std::cerr << Str << "\n"
            << std::string(Ptr - Str.cbegin(), ' ') << "^\n"
            << Message << std::endl;
  exit(1); // 强制退出
}

std::shared_ptr<Token> tokenize(std::string Str) {
  auto Cur = std::make_shared<Token>();
  auto Head = Cur; // 存储最开始token的位置

  auto Ptr = Str.cbegin();
  while (Ptr != Str.cend()) {
    // 跳过所有空白
    if (isspace(*Ptr)) {
      ++Ptr;
      continue;
    }

    // 解析数字
    if (isdigit(*Ptr)) {
      auto B = Ptr;
      while (isdigit(*++Ptr))
        ; // 空语句
      auto Num = std::stoul(std::string(B, Ptr));
      // 直接存在Next里面，方便理解
      Cur->setNext(std::make_shared<Token>(TK_NUM, B, Ptr, Num));
      Cur = Cur->getNext();
      continue;
    }

    // 解析 + —
    if (*Ptr == '+' || *Ptr == '-') {
      Cur->setNext(std::make_shared<Token>(TK_PUNCT, Ptr, Ptr + 1));
      Cur = Cur->getNext();
      ++Ptr;
      continue;
    }

    errorAt(Str, Ptr, "ERROR: Invalid Token!");
  }

  // 终结符 EOF
  Cur->setNext(std::make_shared<Token>(TK_EOF, Ptr, Ptr));
  // Head是空的，直接返回Next就行了
  return Head->getNext();
}
