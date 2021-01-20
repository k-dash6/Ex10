// Copyright 2021 dash
#include <iostream>
#include <string>

#include "postfix.h"

//postfix = "2 6 3 * 4 2 - / +"
int main() {
    std::string infix = "2 + 6 * 3 / (4 - 2)";
    std::string postfix = infix2postfix(infix);
    std::cout << postfix << std::endl;
  return 0;
}
