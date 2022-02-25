#include "disque.h"
#include <cmath>

Disque::Disque()
{
}

double Disque::calculate_area()
{
    return pow(m_radius, 2) * M_PI;
}

double Disque::calculate_perimeter()
{
    return m_radius * 2 * M_PI;
}

double Disque::calculate_area(int t_rayon)
{
    return pow(t_rayon, 2) * M_PI;
}
double Disque::calculate_perimeter(int t_rayon)
{
    return t_rayon * 2 * M_PI;
}

std::map<std::string, std::string> Disque::get_required_parameters()
{
    std::map<std::string, std::string> parameters;
    parameters.insert({"radius", "The radius of the disc"});
    return parameters;
}

void Disque::set_parameters(std::map<std::string, double> t_parameters)
{
    m_parameters = t_parameters;
    m_radius = m_parameters["radius"];
}

