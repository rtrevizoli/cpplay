#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

/*
# Distance Between Two Points
Read the four values corresponding to the x and y axes of two points in the plane, p1 (x1, y1) and p2 (x2, y2) and calculate the distance between them, showing four decimal places after the comma, according to the formula:

Distance = ((x2-x1)^2 + (y2-y1)^2)^1/2

## Input
The input file contains two lines of data. The first one contains two double values: x1 y1 and the second one also contains two double values with one digit after the decimal point: x2 y2.

## Output
Calculate and print the distance value using the provided formula, with 4 digits after the decimal point.
*/

double calculate_d_between_a_and_b(std::pair<double, double> a, std::pair<double, double> b)
{
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

std::string read_line()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

std::pair<double, double> convert_to_point(std::string str, char delim)
{
    std::istringstream iss(str);
    std::vector<double> axes;
    std::string axis;

    while(std::getline(iss, axis, delim))
        axes.push_back(std::stod(axis));
    
    return std::pair{axes[0], axes[1]};
}

int main()
{
    std::pair<double, double> a,b;

    a = convert_to_point(read_line(), ' ');
    b = convert_to_point(read_line(), ' ');

    double distance_between_a_and_b = calculate_d_between_a_and_b(a, b);

    std::cout << std::fixed << std::setprecision(4) << distance_between_a_and_b << std::endl;

    return 0;
}
