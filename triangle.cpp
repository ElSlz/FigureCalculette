#include "triangle.h"

Triangle::Triangle()
{
}

double Triangle::calculate_area()
{
    return (m_base * m_height)/2;
}

double Triangle::calculate_perimeter()
{
    return m_base + m_side + m_third_side;
}

std::map<std::string, std::string> Triangle::get_required_parameters()
{
    std::map<std::string, std::string> parameters;
    parameters.insert({"height", "The height of the triangle"});
    parameters.insert({"base", "The base of the triangle"});
    parameters.insert({"side", "The second side of the triangle"});
    parameters.insert({"side2", "The third side of the triangle"});
    return parameters;
}

void Triangle::set_parameters(std::map<std::string, double> t_parameters)
{
    m_parameters = t_parameters;
    m_height = m_parameters["height"];
    m_base = m_parameters["base"];
    m_side = m_parameters["side"];
    m_third_side = m_parameters["side3"];
}

