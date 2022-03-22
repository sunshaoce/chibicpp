#include <memory>
#include <string>

#ifndef TOKEN_HPP
#define TOKEN_HPP

enum TokenKind : unsigned {
  TK_INVALID, // 默认
  TK_PUNCT,   // 操作符
  TK_NUM,     // 数字
  TK_EOF,     // 文件结尾
};

class Token {
  std::shared_ptr<Token> Next;          //下一个Token
  TokenKind Kind;                       // Token类型
  int Value;                            // 值
  std::string::const_iterator Location; // 位置
  std::string::size_type Length;        // 长度
public:
  Token() = default;
  Token(TokenKind K, std::string::const_iterator B,
        std::string::const_iterator E)
      : Token(K, B, E, 0) {}
  Token(TokenKind K, std::string::const_iterator B,
        std::string::const_iterator E, int V)
      : Kind(K), Location(B), Length(E - B), Value(V) {}

  void setNext(std::shared_ptr<Token> N) { Next = N; }

  std::shared_ptr<Token> getNext() const { return Next; }
  TokenKind getKind() const { return Kind; }
  int getValue() const { return Value; }

  bool isPunct(char P) { return *Location == P; }
};

std::shared_ptr<Token> tokenize(std::string Str);

#endif // !TOKEN_HPP
