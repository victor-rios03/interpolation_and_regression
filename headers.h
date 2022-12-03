//
// Created by 03vic on 12/2/2022.
//

#ifndef INTERPOLATION_AND_REGRESSION_HEADERS_H
#define INTERPOLATION_AND_REGRESSION_HEADERS_H

#endif //INTERPOLATION_AND_REGRESSION_HEADERS_H

#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Points {    // points' coordinates given by points.dat
    double x;
    double y;
};




void linear_interpolation(const vector<Points>&, double);

void lagrange_interpolation(const vector<Points>&, double);

void polynomial_regression(const vector<Points>&, double);
void exponential_regression(const vector<Points>&, double);
