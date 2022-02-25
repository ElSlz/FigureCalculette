#ifndef COURONNE_H
#define COURONNE_H

#include "figure.h"

class Couronne : public Figure
{
public:
    Couronne();

    // figure interface
public:
    std::map<std::string, std::string> get_required_parameters();
    void set_parameters(std::map<std::string, double> parameters);
private:
    double calculate_area();
    double calculate_perimeter();

private:
    double m_radius;
    double m_inner_radius;
};

#endif // COURONNE_H
