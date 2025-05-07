// Auto Genrated C++ file by aura CLI
// None
#include <iostream>
#include <design-patternsconfig.h>
#include <print>
#include <sstream>
#include <vector>
#include <string>
class Splitter
{
  std::string _input{};

public:
  explicit Splitter(const std::string &input) : _input(input) {};
  Splitter() = default;
  void setInput(const std::string &str) { _input = str; };
  inline std::string &input() { return _input; };
  void operator()()
  {
    process();
  }
  operator std::vector<std::string>()
  {
    std::vector<std::string> vec;
    std::istringstream ss(_input);
    std::string word{};
    while (std::getline(ss, word, ' '))
      vec.emplace_back(word);
    return vec;
  };

private:
  void process()
  {
    std::istringstream ss(_input);
    std::string word{};
    int index = 0;
    while (++index, std::getline(ss, word, ' '))
      std::print("[{}] : {}\n", index, word);
  };
};
int main(int argc, char *argv[])
{
  Splitter words;
  auto &input{words.input()};
  input = "lol ou th";
  words();
  words.setInput("well there are so many things that i don't know so what can i do about it");
  for (const auto &word : static_cast<std::vector<std::string>>(words))
    std::print("[{}] ", word);
  return 0;
}
