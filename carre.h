#ifndef CARRE_H
#define CARRE_H

#include "rectangle.h"

class Carre : public Rectangle
{
public:
    Carre();

    // figure interface
public:
    std::map<std::string, std::string> get_required_parameters();
    void set_parameters(std::map<std::string, double> parameters);
};

#endif // CARRE_H
