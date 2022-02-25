#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure
{
public:
    Triangle();

    // figure interface
public:
    std::map<std::string, std::string> get_required_parameters();
    void set_parameters(std::map<std::string, double> parameters);
private:
    double calculate_area();
    double calculate_perimeter();

private:
    double m_side;
    double m_third_side;

protected:
    double m_height;
    double m_base;
};

#endif // TRIANGLE_H
