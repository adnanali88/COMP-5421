
#include "Rectangle.h"

Rectangle::Rectangle(unsigned height, unsigned width, char penChar, const std::string &name)
        : Shape(height, width, penChar, name) {
    _id = Shape::_universalID + 1;
    Shape::_universalID++;
}

void Rectangle::setName(const std::string &name) {
    _name = name;
}

std::string Rectangle::getName() const {
    return _name;
}

unsigned Rectangle::getID() const {
    return _id;
}

char Rectangle::getPen() const {
    return _penChar;
}

unsigned Rectangle::getHeight() const {
    return _height;
}

unsigned Rectangle::getWidth() const {
    return _width;
}

std::string Rectangle::toString() const {

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

void Rectangle::setPen(char penChar) {
    _penChar = penChar;
}

void Rectangle::setHeight(unsigned height) {
    _height = height;
}

void Rectangle::setWidth(unsigned width) {
    _width = width;
}

double Rectangle::getPerimeter() const {
    return 2 * (_height + _width);
}

double Rectangle::getArea() const {
    return _height * _width;
}

double Rectangle::getTextualPerimeter() const {
    return 2 * (_height + _width) - 4;
}

double Rectangle::getTextualArea() const {
    return _height * _width;
}

Canvas Rectangle::draw() const {
    Canvas can{getHeight(), getWidth()};
    for (unsigned i = 0; i < _height; ++i) {
        for (unsigned j = 0; j < _width; ++j)
            can.put(i, j, _penChar);
    }
    return can;
}


