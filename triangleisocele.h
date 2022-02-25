#ifndef TRIANGLEISOCELE_H
#define TRIANGLEISOCELE_H

#include "triangle.h"

class TriangleIsocele : public Triangle
{
public:
    TriangleIsocele();

    // figure interface
public:
    std::map<std::string, std::string> get_required_parameters();
    void set_parameters(std::map<std::string, double> parameters);
private:
    double calculate_perimeter();
};

#endif // TRIANGLEISOCELE_H
