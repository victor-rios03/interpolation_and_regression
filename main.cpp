#include "headers.h"


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

basic_ifstream<char> read_file()
{
    string iname;

    iname = R"(C:\Users\03vic\CLionProjects\interpolation_and_regression\points.dat)";  // absolute path of points text file
    ifstream ist {iname};
    if (!ist) error("can't open input file ");

    return ist;
}

void print_vector(const vector<Points>& points)
{
    for (auto & point : points)
        cout << point.x << ' ' << point.y << endl;
}


int main()
{
    vector<Points> points;
    double x;
    double y;
    double user_x;
    char option;

    ifstream ist = read_file();

    while (ist >> x >> y) {
        points.push_back(Points{x, y});
    }
    sort(points.begin(), points.end(), compare);


    cout << "Punto donde se quieren evaluar los datos" << endl;
    cin >> user_x;

    cout << "Prueba interpolacion lineal" << endl;
    linear_interpolation(points, user_x);

    cout << "Prueba interpolacion con polinomio de Lagrange" << endl;
    lagrange_interpolation(points, user_x);

    cout << "Prueba regresion polinomial" << endl;
    polynomial_regression(points,user_x);

    cout << "Prueba regresion exponencial" << endl;
    exponential_regression(points,user_x);



    return 0;
}
