#include <iostream>
#include <string>
#include <unordered_map>

extern "C" {
char *cpp_test(char *);
}

char *cpp_test(char *key) {
  static const std::unordered_map<std::string, char *> mp{{"1", "one"},
                                                          {"2", "two"}};
  std::cout << "test from c++ called\n";
  if (mp.contains(key)) {
    return mp.find(key)->second;
  }
  return nullptr;
}
