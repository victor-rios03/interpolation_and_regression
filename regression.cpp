//
// Created by 03vic on 12/2/2022.
//

#include "headers.h"

int n;
int m;
const char separator = ' ';
const int numWidth = 12;

double x_summatory(int k, const vector<Points>& points) {
    double sum = 0;

    for(int i=0; i<m; i++) {
        cout << points[i].x << endl;
        sum += pow(points[i].x, k);
    }

    return sum;
}

double y_summatory(int k, const vector<Points>& points) {
    double sum = 0;

    for(int i=0; i<m; i++)
        sum += points[i].y * pow(points[i].x, k);

    return sum;
}

void polynomial_regression(const vector<Points>& points, double user_x) {
    m = (int) points.size(); // numero de puntos
    double temp_val;
    double x[n];

    cout << "Grado del polinomio: " << endl;
    cin >> n;
    double a[n][n+1];

    for (int i=0; i<n; i++) { // recorre los puntos
        for (int j=0; j<n; j++) { // recorre el grado del polinomio
            a[i][j] = x_summatory(i+j, points);
        }
        a[i][n] = y_summatory(i, points);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << left << setw(numWidth) << setfill(separator) << a[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            temp_val = a[j][i] / a[i][i];
            for (int k = 0; k < n+1; k++) {
                a[j][k] = a[j][k] - (temp_val * a[i][k]);
            }
        }
    }

    for (int i = n ; i >= 1; i--) {
        x[i - 1] = a[i - 1][n];
        for (int j = i + 1; j <= n; j++) {
            x[i - 1] = x[i - 1] - a[i-1][j-1] * x[j-1];
        }
        x[i-1] = x[i - 1] / a[i-1][i-1];
    }

    cout << "Polinomio que mas se acerca a los puntos: ";
    cout << "y(x) = ";

    for (int i=0; i<n; i++)
            cout << x[i] << 'x' << '^' << i << ' ' << '+' << ' ';

    cout << endl;
    double X=0;

    for (int i=0; i<n; i++)
        X+=x[i] * pow(user_x,i);

    cout << "Evaluado en x = " << user_x << ',' << endl;
    cout << "y(" << user_x << ") = " << X << endl;

}

void exponential_regression(const vector<Points>& points, double user_x) {
    m = (int) points.size(); // numero de puntos
    vector<Points> exp_points;
    exp_points = points;
    double a[2][3];
    double x[2];

    for(auto & exp_point : exp_points)
        exp_point.y = log(exp_point.y);
/*
    for (auto & point : exp_points)
        cout << point.x << ' ' << point.y << endl;
*/
    for (int i=0; i<2; i++) { // recorre los puntos
        for (int j=0; j<2; j++) { // recorre el grado del polinomio
            a[i][j] = x_summatory(i+j, exp_points);
        }
        a[i][2] = y_summatory(i, exp_points);
    }

 /*
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << left << setw(numWidth) << setfill(separator) << a[i][j];
        }
        cout << endl;
    }
    */

    double det;
    double a_det;
    double b_det;

    det = a[0][0] * a[1][1] - (a[1][0] * a[0][1]);
    a_det = a[0][2] * a[1][1] - (a[1][2] * a[0][1]);
    b_det = a[0][0] * a[1][2] - (a[1][0] * a[0][2]);

    x[0] = exp(a_det/det);
    x[1] = exp(b_det/det);

    cout << "y = " << x[0] << '(' << x[1] << ')' << "^x" << endl;
}
