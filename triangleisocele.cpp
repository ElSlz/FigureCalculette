#include "triangleisocele.h"
#include <cmath>

TriangleIsocele::TriangleIsocele()
{

}

double TriangleIsocele::calculate_perimeter()
{    
    float side = sqrt(pow(m_base/2,2) + pow(m_height,2));
    return (side*2) + m_base;
}

std::map<std::string, std::string> TriangleIsocele::get_required_parameters()
{
    std::map<std::string, std::string> parameters;
    parameters.insert({"height", "The height of the triangle"});
    parameters.insert({"base", "The base of the triangle"});
    return parameters;
}

void TriangleIsocele::set_parameters(std::map<std::string, double> t_parameters)
{
    m_parameters = t_parameters;
    m_height = m_parameters["height"];
    m_base = m_parameters["base"];
}

