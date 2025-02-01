#include <iostream>
using namespace std;

// Function to calculate factorial
int fact(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

// Function for Newton's Forward Interpolation
float newtonForwardInterpolation(float x[], float y[][20], int n, float value) {
    float sum = y[0][0];
    float u = (value - x[0]) / (x[1] - x[0]);
    float u_product = 1;

    for (int i = 1; i < n; i++) {
        u_product *= (u - (i - 1));
        sum += (u_product * y[0][i]) / fact(i);
    }
    return sum;
}

// Function for Newton's Backward Interpolation
float newtonBackwardInterpolation(float x[], float y[][20], int n, float value) {
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    float u_product = 1;

    for (int i = 1; i < n; i++) {
        u_product *= (u + (i - 1));
        sum += (u_product * y[n - 1][i]) / fact(i);
    }
    return sum;
}

int main() {
    cout << "Enter the size of data: ";
    int n;
    cin >> n;
    int i, j;
    float x[20], y[20][20];

    cout << "Enter the elements of the dataset:\n";
    for (i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i][0];
    }

    // Constructing the forward difference table
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    cout << "\nForward Difference Table:\n";
    for (i = 0; i < n; i++) {
        cout << x[i];
        for (j = 0; j < n - i; j++) {
            cout << "\t" << y[i][j];
        }
        cout << endl;
    }

    // Constructing the backward difference table
    for (i = 1; i < n; i++) {
        for (j = n - 1; j > i - 1; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    cout << "\nBackward Difference Table:\n";
    for (i = 0; i < n; i++) {
        cout << x[i];
        for (j = 0; j < n - i; j++) {
            cout << "\t" << y[i][j];
        }
        cout << endl;
    }

    // Interpolation input
    float value;
    cout << "\nEnter the value to interpolate: ";
    cin >> value;

    // Calculate interpolation using both methods
    float forwardResult = newtonForwardInterpolation(x, y, n, value);
    float backwardResult = newtonBackwardInterpolation(x, y, n, value);

    cout << "\nNewton Forward Interpolation Result: " << forwardResult << endl;
    cout << "Newton Backward Interpolation Result: " << backwardResult << endl;

    return 0;
}

