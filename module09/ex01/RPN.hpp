#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstdlib>

typedef int (*Operation)(int, int);

int Add(int a, int b);
int Subtract(int a, int b);
int Multiply(int a, int b);
int Divide(int a, int b);

bool isArgValid(char **argv);
bool isOperator(char c);
bool isBadChar(char c);
int negatives(char *argv);
int resultProcess(int stackTop, char operation, int temp, Operation operations[]);

#endif
