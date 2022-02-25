#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle();

    // figure interface
public:
    std::map<std::string, std::string> get_required_parameters();
    void set_parameters(std::map<std::string, double> parameters);
private:
    double calculate_area();
    double calculate_perimeter();

protected:
    double m_height;
    double m_width;
};

#endif // RECTANGLE_H
