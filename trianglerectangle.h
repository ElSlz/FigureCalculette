#ifndef TRIANGLERECTANGLE_H
#define TRIANGLERECTANGLE_H

#include "triangle.h"

class TriangleRectangle : public Triangle
{
public:
    TriangleRectangle();

    // figure interface
public:
    std::map<std::string, std::string> get_required_parameters();
private:
    double calculate_perimeter();
};

#endif // TRIANGLERECTANGLE_H
