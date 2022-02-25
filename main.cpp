#include <iostream>
#include <map>
#include <memory>
#include "figure.h"
#include "disque.h"
#include "couronne.h"
#include "triangle.h"
#include "triangleisocele.h"
#include "trianglerectangle.h"
#include "rectangle.h"
#include "carre.h"

template<typename T, typename U>
void display_map(std::map<T, U> t_map)
{
    for (auto it = t_map.begin(); it != t_map.end(); it++)
        std::cout << "[" << it->first << ": " << it->second<< "] ";
    std::cout << std::endl;
}

std::shared_ptr<Figure> construct_figure(int t_figurenb)
{
    switch (t_figurenb)
    {
    case EnumScop::TypeFigure::Rectangle:
        return std::static_pointer_cast<Figure>(std::make_shared<Rectangle>());
    case EnumScop::TypeFigure::Disc:
        return std::static_pointer_cast<Figure>(std::make_shared<Disque>());
    case EnumScop::TypeFigure::Square:
        return std::static_pointer_cast<Figure>(std::make_shared<Carre>());
    case EnumScop::TypeFigure::Ring:
        return std::static_pointer_cast<Figure>(std::make_shared<Couronne>());
    case EnumScop::TypeFigure::Triangle:
        return std::static_pointer_cast<Figure>(std::make_shared<Triangle>());
    case EnumScop::TypeFigure::TriangleRectangle:
        return std::static_pointer_cast<Figure>(std::make_shared<TriangleRectangle>());
    case EnumScop::TypeFigure::TriangleIsocele:
        return std::static_pointer_cast<Figure>(std::make_shared<TriangleIsocele>());
    default:
        throw std::invalid_argument( "Figure value not recognized");
    };
}

std::string find_option_value(int t_argc, char* t_argv[], const std::string& t_option)
{
    std::string value= "";
    for( int i = 0; i < t_argc; ++i)
    {
        std::string arg = t_argv[i];
        if(0 == arg.find(t_option))
        {
            if(i+1 < t_argc)
                value = t_argv[i+1];
            else
                value= "";
        }
    }
    return value;
}

using Stringmap = std::map<std::string, std::string>;
using Intmap = std::map<int, std::string>;
int main(int argc, char *argv[])
{
    std::shared_ptr<Figure> pfigureimp = nullptr;
    int ifigurenb;
    int icalc;

    Intmap figuredescs;
    figuredescs.insert(Intmap::value_type(EnumScop::TypeFigure::Disc, "disque"));
    figuredescs.insert(Intmap::value_type(EnumScop::TypeFigure::Rectangle, "rectangle"));
    figuredescs.insert(Intmap::value_type(EnumScop::TypeFigure::Square, "carre"));
    figuredescs.insert(Intmap::value_type(EnumScop::TypeFigure::Triangle, "triangle"));
    figuredescs.insert(Intmap::value_type(EnumScop::TypeFigure::TriangleIsocele, "triangleisocele"));
    figuredescs.insert(Intmap::value_type(EnumScop::TypeFigure::TriangleRectangle, "trianglerectangle"));
    figuredescs.insert(Intmap::value_type(EnumScop::TypeFigure::Ring, "couronne"));

    Intmap opdescs;
    opdescs.insert(Intmap::value_type(EnumScop::Calcul::Area, "aire"));
    opdescs.insert(Intmap::value_type(EnumScop::Calcul::Perimeter, "perimetre"));

    if(argc>3)
    {
        Stringmap argdescs;
        argdescs.insert(Stringmap::value_type("?", "help"));
        argdescs.insert(Stringmap::value_type("-c", "side3"));
        argdescs.insert(Stringmap::value_type("-a", "side"));
        argdescs.insert(Stringmap::value_type("-b", "base"));
        argdescs.insert(Stringmap::value_type("-r", "innerRadius"));
        argdescs.insert(Stringmap::value_type("-R", "radius"));
        argdescs.insert(Stringmap::value_type("-h", "height"));
        argdescs.insert(Stringmap::value_type("-w", "width"));
        argdescs.insert(Stringmap::value_type("-o", "operation"));
        argdescs.insert(Stringmap::value_type("-s", "shape"));

        std::map<std::string, double> parameters;

        try {
            for (auto it = argdescs.begin(); it != argdescs.end(); it++)
            {
                std::string c = it->first;
                std::string value = find_option_value(argc, argv, c);
                if(value.empty())
                    continue;

                if(c == "-o")
                    icalc = stoi(value);
                else if(c == "-s")
                    ifigurenb = stoi(value);
                else if(c == "-R")
                    parameters.insert({"radius", stod(value)});
                else if(c == "-r")
                    parameters.insert({"innerradius", stod(value)});
                else if(c == "-w")
                    parameters.insert({"width", stod(value)});
                else if(c == "-a")
                    parameters.insert({"side", stod(value)});
                else if(c == "-c")
                    parameters.insert({"side3", stod(value)});
                else if(c == "-h")
                    parameters.insert({"height", stod(value)});
                else if(c == "-b")
                    parameters.insert({"base", stod(value)});
                else if(c == "?")
                    display_map(argdescs);
            }

            pfigureimp = construct_figure(ifigurenb);

            if(pfigureimp != nullptr)
            {
                pfigureimp->set_parameters(parameters);
                std::cout << "Figure type: " <<figuredescs.at(ifigurenb) << std::endl;
                std::cout << "Operation type: " <<opdescs.at(icalc) << std::endl;
                std::cout << "Parameters: ";
                display_map(parameters);
                float result = pfigureimp->select_operation(icalc);
                std::cout << "Result is: " << result << std::endl;
            }
        }
        catch(std::exception &e)
        {
            std::cerr << "An exception occured: " << e.what() << std::endl;
        }
    }
    else if(argc==1)
    {
        bool bcontinue = true;
        std::string cin_buffer;
        std::cout << "Figure items: ";
        display_map(figuredescs);
        std::cout << std::endl << "Caculuation items: ";
        display_map(opdescs);

        while(bcontinue)
        {
            std::cout << "Enter the figure: ";
            std::cin >> cin_buffer;

            try {
                ifigurenb = stoi(cin_buffer);
                std::cout << "Enter the operation type: ";
                std::cin >> cin_buffer;
                icalc = stoi(cin_buffer);

                pfigureimp = construct_figure(ifigurenb);
                if(pfigureimp != nullptr)
                {
                    std::map<std::string, std::string> parameters = pfigureimp->get_required_parameters();
                    std::map<std::string, double> resultparameters;
                    double value;
                    for (auto it = parameters.begin(); it != parameters.end(); it++)
                    {
                        std::cout << "Select " << it->first << " (" << it-> second << ")" << ": " ;
                        std::cin >> cin_buffer;
                        value = stod(cin_buffer);
                        resultparameters.insert({it->first, value});
                    }
                    pfigureimp->set_parameters(resultparameters);
                    double result = pfigureimp->select_operation(icalc);
                    std::cout << "Result is: " << result << std::endl;
                }
            }
            catch(std::exception &e)
            {
                std::cerr << "An exception occured: " << e.what() << std::endl;
            }

            std::cout << "Continue(Y/N): ";
            std::cin >> cin_buffer;
            bcontinue = cin_buffer == "Y";
        }
    }

    return 1;
}

