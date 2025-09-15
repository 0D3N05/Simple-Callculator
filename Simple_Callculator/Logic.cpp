#include <stack>
#include <string>
#include "Logic.h"


using namespace std;


// Function to apply an operator to two numbers
double applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return 0;
}

// Function to define operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Main evaluation function
double evaluate(const string& expr) {
    stack<double> values;   // numbers
    stack<char> ops;        // operators

    for (size_t i = 0; i < expr.length(); i++) {
        // Skip spaces
        if (isspace(expr[i])) continue;

        // If number, read the full number (handles multi-digit)
        if (isdigit(expr[i])) {
            double val = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            values.push(val);
            i--; // step back because for loop will increment
        }
        // If operator
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expr[i]);
        }
    }

    // Apply remaining operators
    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}
