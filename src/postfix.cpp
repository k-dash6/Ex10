// Copyright 2021 dash
#include "MyStack.h"
#include "postfix.h"


std::string infix2postfix(std::string infix) {
    std::string postfix;
    int counter = 0;
    int len = infix.length();
    MyStack<char> sign_stack(len);
    for (counter = 0; counter < len; counter++) {
        if (infix[counter] != ' ') {
            if (infix[counter] == '(') {
                sign_stack.push(infix[counter]);
            } else if (infix[counter] == ')') {
                while (sign_stack.get() != '(') {
                    postfix += sign_stack.pop();
                    postfix += ' ';
                }
                sign_stack.pop();
            } else if (infix[counter] == '+' || infix[counter] == '-') {
                while (sign_stack.get() == '+'
                    || sign_stack.get() == '-'
                    || sign_stack.get() == '*' 
                    || sign_stack.get() == '/') {
                    postfix += sign_stack.pop();
                    postfix += ' ';
                }
                sign_stack.push(infix[counter]);
            } else if (infix[counter] == '*' || infix[counter] == '/') {
                while (sign_stack.get() == '*' || sign_stack.get() == '/') {
                    postfix += sign_stack.pop();
                    postfix += ' ';
                }
                sign_stack.push(infix[counter]);
            } else if (infix[counter] >= '0' && infix[counter] <= '9') {
                while (counter < len &&
                    infix[counter] != ')' &&
                    infix[counter] != ' ') {
                    postfix += infix[counter];
                    counter = counter + 1;
                }
                counter = counter - 1;
                postfix += ' ';
            }
        }
    }
    while (!sign_stack.isEmpty()) {
        postfix += ' ';
        postfix += sign_stack.pop();
    }
    return postfix;
}


