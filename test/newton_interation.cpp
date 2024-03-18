#include <iostream>
#include <cmath>

// 定义方程及其导数
double f(double x) {
    return pow(x, 3) + 2 * pow(x, 2) + 3 * x + 4;
}

double fDerivative(double x) {
    return 3 * pow(x, 2) + 4 * x + 3;
}

// 牛顿迭代函数
double newtonRaphson(double x0, double epsilon) {
    double x = x0;
    double delta;
    do 
    {
        delta = f(x) / fDerivative(x);
        x = x - delta;
    } 
    while (fabs(delta) >= epsilon);

    return x;
}

int main() {
    double initialGuess = 1.0; // 初始猜测值
    double epsilon = 0.0001; // 精度

    double root = newtonRaphson(initialGuess, epsilon);
    
    std::cout << "Approximate root: " << root << std::endl;

    return 0;
}
