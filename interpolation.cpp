//
// Created by 03vic on 11/30/2022.
//

#include "headers.h"


void linear_interpolation(const vector<Points>& points, double x) {
    double y;
    double m;

    for (int i=0; i<points.size()-1; i++) {
        if (x > points[i].x && x < points[i+1].x ){
            cout << "El punto esta entre, (";
            cout << points[i].x << ", " << points[i+1].x << ')' << endl;
            m = (points[i+1].y - points[i].y) /  (points[i+1].x - points[i].x);
            y = points[i].y + (x - points[i].x) * m;
            cout << "Usando interpolacion lineal el punto: " << x << ", esta en :"<< y << endl;
            return;
        }
    }

    cout << "No se puede usar interpolacion lineal con los datos dados" << endl;
}

void lagrange_interpolation(const vector<Points>& points, double x) {
    double L=0;
    double L_temp;

    for (int i=0; i<points.size(); i++) {
        L_temp = points[i].y;
        for (int j=0; j<points.size(); j++) {
            if (j != i) {
                L_temp *= (x - points[j].x) / (points[i].x - points[j].x);
            }
        }
        cout << "L_(" << i << ") = " << L_temp << endl;
        L += L_temp;
    }
    cout << "Usando interpolacion de lagrange el punto: " << x << ", esta en :"<< L << endl;
}
