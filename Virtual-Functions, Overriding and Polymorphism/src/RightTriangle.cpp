
#include "RightTriangle.h"

RightTriangle::RightTriangle(unsigned base, char penChar, const std::string& name)
        : Triangle(base, base, penChar, name) {
    _id = Shape::_universalID + 1;
    Shape::_universalID++;
}

void RightTriangle::setName(const std::string &name) {
    _name = name;
}

std::string RightTriangle::getName() const {
    return _name;
}

unsigned RightTriangle::getID() const {
    return _id;
}

char RightTriangle::getPen() const {
    return _penChar;
}

unsigned RightTriangle::getHeight() const {
    return _height;
}

unsigned RightTriangle::getWidth() const {
    return _width;
}

std::string RightTriangle::toString() const {
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

void RightTriangle::setPen(char penChar) {
    _penChar = penChar;
}

void RightTriangle::setHeight(unsigned height) {
    _height = height;
}

void RightTriangle::setWidth(unsigned width) {
    _width = width;
}

double RightTriangle::getPerimeter() const {
    return (2 + sqrt(2)) * _height;
}

double RightTriangle::getArea() const {
    return _height * _width * (0.5);
}

double RightTriangle::getTextualPerimeter() const {
    return 3 * (_height - 1);
}

double RightTriangle::getTextualArea() const {
    return _height * (_height + 1) * (0.5);
}

Canvas RightTriangle::draw() const {
    Canvas can{getHeight(), getWidth()};

    for (unsigned i = 0; i < _height; ++i)
        for (unsigned j = 0; j < i + 1; ++j)
            can.put(i, j, _penChar);

    return can;

}

