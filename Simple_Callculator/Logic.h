

#ifndef LOGIC_H
#define LOGIC_H
#include <string>

using namespace std;

double applyOp(double a, double b, char op);
int precedence(char op);
double evaluate(const string& expr);

#endif // LOGIC_H
