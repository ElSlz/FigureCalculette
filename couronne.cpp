#include "couronne.h"
#include "disque.h"

Couronne::Couronne()
{
}

double Couronne::calculate_area()
{
    return Disque::calculate_area(m_radius - Disque::calculate_area(m_inner_radius));
}

double Couronne::calculate_perimeter()
{
    return Disque::calculate_perimeter(m_radius + Disque::calculate_perimeter(m_inner_radius));
}

std::map<std::string, std::string> Couronne::get_required_parameters()
{
    std::map<std::string, std::string> parameters;
    parameters.insert({"radius", "The outer radius of the ring"});
    parameters.insert({"innerradius", "The inner radius of the ring"});
    return parameters;
}

void Couronne::set_parameters(std::map<std::string, double> t_parameters)
{
    m_parameters = t_parameters;
    m_radius = m_parameters["radius"];
    m_inner_radius = m_parameters["innerradius"];
}

