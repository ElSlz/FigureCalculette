#include "trianglerectangle.h"
#include <cmath>

TriangleRectangle::TriangleRectangle()
{

}

double TriangleRectangle::calculate_perimeter()
{
    float side = sqrt(pow(m_base,2) + pow(m_height,2));
    return side + m_base + m_height;
}

std::map<std::string, std::string> TriangleRectangle::get_required_parameters()
{
    std::map<std::string, std::string> parameters;
    parameters.insert({"height", "The height of the triangle"});
    parameters.insert({"base", "The base of the triangle"});
    return parameters;
}
