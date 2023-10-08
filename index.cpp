#include <iostream>
#include <cmath>

double ln_approximation(double x, int n) {
    if (x <= 0) {
        // ln(x) is undefined for x <= 0
        return -1.0; // You can return an error code or handle this case as needed.
    }

    double result = 0.0;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            result += (1.0 / i) * pow((x - 1) / (x + 1), i);
        }
    }

    return 2 * result;
}

int main() {
    double x = 2.0; // Replace with the desired value of x
    int n = 10;     // Number of terms in the approximation

    double approximated_ln = ln_approximation(x, n);

    if (approximated_ln == -1.0) {
        std::cout << "Error: ln(x) is undefined for x <= 0" << std::endl;
    } else {
        std::cout << "Approximation of ln(" << x << ") with " << n << " terms: " << approximated_ln << std::endl;
    }

    return 0;
}
