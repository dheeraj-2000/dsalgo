#include <iostream>
#include <cmath>
#include <functional>

double newtonsMethod(std::function<double(double)> f, std::function<double(double)> df, double initialGuess, double tol=1e-5, int max_iter=100) {
    double x = initialGuess;
    double old_x = initialGuess;
    for(int i = 0; i < max_iter; i++) {
        x -= f(old_x) / df(old_x);
        if(std::abs(x - old_x) < tol) {
            return x;
        }
        old_x = x;
    }
    return x;
}

double nthRoot(double x, int n) {
    return newtonsMethod([=](double t){return std::pow(t, n) - x;}, [=](double t){return n * std::pow(t, n - 1);}, 2 * x);
}

int main() {
    double x, n;
    std::cin >> x >> n;
    std::cout << nthRoot(x, n) << std::endl;
    return 0;
}