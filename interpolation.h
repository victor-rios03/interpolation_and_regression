//
// Created by 03vic on 11/30/2022.
//

#ifndef INTERPOLATION_AND_REGRESSION_INTERPOLATION_H
#define INTERPOLATION_AND_REGRESSION_INTERPOLATION_H

#endif //INTERPOLATION_AND_REGRESSION_INTERPOLATION_H

#include <vector>
#include <iostream>

using namespace std;

struct Points {    // points coordinates given by points.dat
    double x;
    double y;
};

void linear_interpolation(const vector<Points>&, double);

void lagrange_interpolation(const vector<Points>&, double);
