#include "rectangle.h"

Rectangle::Rectangle():Figure()
{
}


double Rectangle::calculate_area()
{
    return m_height * m_width;
}

double Rectangle::calculate_perimeter()
{
    return 2*(m_height + m_width);
}

std::map<std::string, std::string> Rectangle::get_required_parameters()
{
    std::map<std::string, std::string> parameters;
    parameters.insert({"height", "The length of the rectangle"});
    parameters.insert({"width", "The width of the rectangle"});
    return parameters;
}

void Rectangle::set_parameters(std::map<std::string, double> t_parameters)
{
    m_parameters = t_parameters;
    m_width = m_parameters["width"];
    m_height = m_parameters["height"];
}

