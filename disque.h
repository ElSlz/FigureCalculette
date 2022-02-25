#ifndef DISQUE_H
#define DISQUE_H

#include "figure.h"

class Disque : public Figure
{
public:
    Disque();

    // figure interface
public:
    static double calculate_area(int rayon);
    static double calculate_perimeter(int rayon);
    std::map<std::string, std::string> get_required_parameters();
    void set_parameters(std::map<std::string, double> parameters);
private:
    double calculate_area();
    double calculate_perimeter();
private:
    double m_radius;
    double m_inner_radius;
};

#endif // DISQUE_H
