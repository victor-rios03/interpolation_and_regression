//
// Created by 03vic on 12/2/2022.
//

#include "headers.h"
#include <Eigen/Dense> // Libreria para resolver sistemas de ecuaciones, se espera que el usuario la agregue

using Eigen::MatrixXd;
using Eigen::Matrix2d;
using Eigen::Vector2d;
using Eigen::VectorXd;

const char separator = ' ';
const int numWidth = 12;

double x_summatory(int k, const vector<Points>& points, int m) {
    double sum = 0;

    for(int i=0; i<m; i++)
        sum += pow(points[i].x, k);

    return sum;
}

double y_summatory(int k, const vector<Points>& points, int m) {
    double sum = 0;

    for(int i=0; i<m; i++)
        sum += points[i].y * pow(points[i].x, k);

    return sum;
}

void polynomial_regression(const vector<Points>& points, double user_x) {
    int m = (int) points.size(); // numero de puntos
    int n;

    cout << "Grado del polinomio: " << endl;
    cin >> n;

    MatrixXd A(n, n);
    VectorXd b(n);

    for (int i=0; i<n; i++) { // recorre los puntos
        for (int j=0; j<n; j++) { // recorre el grado del polinomio
            A(i,j) = x_summatory(i+j, points, m); // Define los coeficientes del sistema
        }
        b[i]= y_summatory(i, points, m); // Define los terminos independientes del sistema
    }

    VectorXd x = A.colPivHouseholderQr().solve(b);

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
    int m = (int) points.size(); // numero de puntos
    vector<Points> exp_points = points;
    Matrix2d A;
    Vector2d b;
    double X;

    for(auto & exp_point : exp_points)  // cambio de variable y = ln(y)
        exp_point.y = log(exp_point.y);

    for (int i=0; i<2; i++) { // recorre los puntos
        for (int j=0; j<2; j++) { // recorre el grado del polinomio
            A(i,j) = x_summatory(i+j, exp_points, m); // Define los coeficientes del sistema
        }
        b(i) = y_summatory(i, exp_points, m); // Define los terminos independientes del sistema
    }

    Vector2d x = A.colPivHouseholderQr().solve(b); // Resuelve el sistema

    cout << "y = " << x[0] << '(' << x[1] << ')' << "^x" << endl;
    X = x[0] * pow(x[1],user_x); // Devuelve el cambio de variable
    cout << "Evaluado en x = " << user_x << ',' << endl;
    cout << "y(" << user_x << ") = " << X << endl;

}
