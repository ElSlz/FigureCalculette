#ifndef FIGURE_H
#define FIGURE_H
#include <map>
#include <string>

namespace EnumScop
{
enum Calcul
{
    Area=1,
    Perimeter
};

enum TypeFigure
{
    Disc=1,
    Rectangle,
    Square,
    Triangle,
    TriangleIsocele,
    TriangleRectangle,
    Ring
};
}

class Figure
{
public:
    Figure();
    virtual ~Figure();
    double select_operation(int op);
    virtual double calculate_area() = 0;
    virtual double calculate_perimeter()= 0;
    virtual void set_parameters(std::map<std::string, double> parameters);
    virtual std::map<std::string, std::string> get_required_parameters()=0;
protected:
    std::map<std::string, double> m_parameters;
};

#endif // FIGURE_H
