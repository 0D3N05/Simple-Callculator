#include <iostream>

using namespace std;

float Addition(float a, float b) {
    return a + b;
}
float Subtraction(float a, float b) {
    return a - b;
}
float Multiplication(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        cerr << "Error: Division by zero!" << endl;
        return 0; // or handle the error as appropriate
    }
}


int main() {
    
}