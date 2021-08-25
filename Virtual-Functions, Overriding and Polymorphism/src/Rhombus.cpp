
#include "Rhombus.h"


Rhombus::Rhombus(unsigned diagonal, char penChar, const std::string &name)
        : Shape(diagonal, diagonal, penChar, name) {
    if (diagonal % 2 == 0)
        _height = _width = diagonal + 1;

    _id = Shape::_universalID + 1;
    Shape::_universalID++;
}

void Rhombus::setName(const std::string &name) {
    _name = name;
}

std::string Rhombus::getName() const {
    return _name;
}

unsigned Rhombus::getID() const {
    return _id;
}

char Rhombus::getPen() const {
    return _penChar;
}

unsigned Rhombus::getHeight() const {
    return _height;
}

unsigned Rhombus::getWidth() const {
    return _width;
}

std::string Rhombus::toString() const {
    std::stringstream ss;
    ss << std::left
       << "Shape Information"
       << std::endl << "-----------------"
       << std::endl << std::setw(25) << "id:" << _id
       << std::endl << std::setw(25) << "Shape name:" << _name
       << std::endl << std::setw(25) << "Pen character:" << _penChar
       << std::endl << std::setw(25) << "Height:" << _height
       << std::endl << std::setw(25) << "Width:" << _width
       << std::endl << std::setw(25) << "Textual area:" << getTextualArea()
       << std::endl << std::setw(25) << "Geometric area:" << getArea()
       << std::endl << std::setw(25) << "Textual perimeter:" << getTextualPerimeter()
       << std::endl << std::setw(25) << "Geometric perimeter:" << getPerimeter()
       << std::endl << std::setw(25) << "Static type:" << typeid(this).name()
       << std::endl << std::setw(25) << "Dynamic type:" << typeid(*this).name()
       << std::endl;

    return ss.str();
}

void Rhombus::setPen(char penChar) {
    _penChar = penChar;
}

void Rhombus::setHeight(unsigned height) {
    _height = height;
}

void Rhombus::setWidth(unsigned width) {
    _width = width;
}

double Rhombus::getPerimeter() const {
    return 2 * sqrt(2) * _height;
}

double Rhombus::getArea() const {
    return _height * _width * (0.5);
}

double Rhombus::getTextualPerimeter() const {
    return 2 * (_height + _width) - 4;
}

double Rhombus::getTextualArea() const {
    double n = floor(_height / 2);
    return 2 * n * (n + 1) + 1;
}

Canvas Rhombus::draw() const {
    Canvas can{getHeight(), getWidth()};
    unsigned r = (_height) / 2 + 1;

    for (int i = 0; i <= r; i++) {
        for (int j = 1; j <= 2 * i - 1; j++)
            can.put(i, j, _penChar);
    }
    for (int i = r - 1; i >= 1; i--) {
        for (int j = 1; j <= 2 * i - 1; j++)
            can.put(i, j, _penChar);
    }

    return can;
}
