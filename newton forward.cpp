#include <iostream>
using namespace std;
int main() {
    int n;
cout<<"Enter the size : ";
cin>>n;
    double x[n], y[n];
cout<<"Enter the x values:  ";
    for (int i = 0; i< n; i++) {
cin>>x[i];
    }
cout<<"Enter the corresponding y values:  ";
    for (int i = 0; i< n; i++) {
cin>>y[i];
    }
    double h = x[1] - x[0];
    double f[n][n];

    for (int i = 0; i< n; i++) {
        f[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i< n - j; i++) {
            f[i][j] = (f[i+1][j-1] - f[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    double xinterp;
cout<<"Enter the value of x for interpolation:  ";
cin>>xinterp;
    double result = f[0][0];
    double term = 1.0;
    for (int i = 0; i< n; i++) {
        term *= (xinterp - x[i]);
        result += f[0][i+1] * term;
    }
cout<<result;
    return 0;
}
