#include "carre.h"

Carre::Carre()
{
}

std::map<std::string, std::string> Carre::get_required_parameters()
{
    std::map<std::string, std::string> parameters;
    parameters.insert({"side", "The side of the square"});
    return parameters;
}

void Carre::set_parameters(std::map<std::string, double> t_parameters)
{
    m_parameters = t_parameters;
    m_width = m_parameters["side"];
    m_height = m_width;
}


