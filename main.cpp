#include <fstream>
#include <algorithm>
#include "interpolation.h"

void error(const string& s)
{
    throw runtime_error(s);
}

bool compare(Points const& s1, Points const& s2) //modified answer from  https://stackoverflow.com/a/37037905
{
    // If the values of the first column are not equal,
    // just use them to order s1 and s2.
    if ( s1.x != s2.x ) {
        return s1.x < s2.x;
    }

    // If the values of the first column are equal,
    // use the values of the second column to order s1 and s2.
    return s1.x < s2.x;
}


int main() {
    string iname;
    iname = R"(C:\Users\03vic\CLionProjects\interpolation_and_regression\points.dat)";  // absolute path of points text file
    ifstream ist {iname};
    if (!ist) error("can't open input file ");

    vector<Points> points;
    double x;
    double y;
    double user_x;

    while (ist >> x >> y) {
        points.push_back(Points{x, y});
    }

    sort(points.begin(), points.end(), compare);

    cin >> user_x;

    linear_interpolation(points, user_x);

    lagrange_interpolation(points, user_x);

    return 0;
}
