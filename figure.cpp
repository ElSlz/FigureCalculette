#include "figure.h"
#include <stdexcept>

Figure::Figure()
{
}

Figure::~Figure()
{
    m_parameters.clear();
}

double Figure::select_operation(int t_op)
{
    switch (t_op)
    {
    case EnumScop::Calcul::Area:
    {
        return this->calculate_area();
    }
    case EnumScop::Calcul::Perimeter:
    {
        return this->calculate_perimeter();
    }
    default:
    {
        throw std::invalid_argument( "Operation value not recognized");
    }
    };
}

void Figure::set_parameters(std::map<std::string, double> t_parameters)
{
    m_parameters = t_parameters;
}
