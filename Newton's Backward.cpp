#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    double x[n], y[n];
    cout << "Enter the x values: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << "Enter the y values: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double h = x[1] - x[0];
    double f[n][n] = {0};


    for (int i = 0; i < n; i++) {
        f[i][0] = y[i];
    }


    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            f[i][j] = f[i][j - 1] - f[i - 1][j - 1];
        }
    }

    double xinterp;
    cout << "Enter the value of x for interpolation: ";
    cin >> xinterp;


    double result = f[n - 1][0];
    double term = 1.0;
    double u = (xinterp - x[n - 1]) / h;

    for (int i = 1; i < n; i++) {
        term *= (u + i - 1) / i;
        result += term * f[n - 1][i];
    }

    cout << "Interpolated value at x = " << xinterp << " is " << result << endl;

    return 0;
}

