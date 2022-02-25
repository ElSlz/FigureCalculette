cmake_minimum_required(VERSION 3.5)

project(calculette LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(calculette main.cpp disque.cpp rectangle.cpp carre.cpp triangle.cpp triangleisocele.cpp trianglerectangle.cpp couronne.cpp figure.cpp)
