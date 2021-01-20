// Copyright 2021 dash
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class T>
class MyStack {
 private:
     T* stack;
     int size, p;

 public:
     explicit MyStack(int n_size) {
         size = n_size;
         stack = new T[size];
     }
     MyStack(const MyStack& c) {
         size = c.size;
         p = c.p;
         stack = new T[size];
         for (int i = 0; i < p; ++i) {
             stack[i] = c.stack[i];
         }
     }
     ~MyStack() {
         delete[] stack;
     }
     T get() const {
         if (p <= 0) {
             return 0;
         } else {
             return stack[p - 1];
         }
     }
     T pop() {
         if (p <= 0) {
             return 0;
         } else {
             p--;
             return stack[p];
         }
     }
     void push(T n) {
         if (p < size) {
             stack[p] = n;
             p = p + 1;
         }
     }
     bool isFull() const {
         if (p != size) {
             return false;
         } else {
             return true;
         }
     }
     bool isEmpty() const {
         return (p == 0);
     }
};

#endif  // INCLUDE_MYSTACK_H_
