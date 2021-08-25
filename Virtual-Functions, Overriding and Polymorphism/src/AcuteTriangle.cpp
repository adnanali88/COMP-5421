
#include "AcuteTriangle.h"


AcuteTriangle::AcuteTriangle(unsigned base, char penChar, const std::string &name)
        : Triangle((base + 1) / 2, base, penChar, name) {
    _id = Shape::_universalID + 1;
    Shape::_universalID++;
}

void AcuteTriangle::setName(const std::string &name) {
    _name = name;
}

std::string AcuteTriangle::getName() const {
    return _name;
}

unsigned AcuteTriangle::getID() const {
    return _id;
}

char AcuteTriangle::getPen() const {
    return _penChar;
}

unsigned AcuteTriangle::getHeight() const {
    return _height;
}

unsigned AcuteTriangle::getWidth() const {
    return _width;
}

std::string AcuteTriangle::toString() const {
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

void AcuteTriangle::setPen(char penChar) {
    _penChar = penChar;
}

void AcuteTriangle::setHeight(unsigned height) {
    _height = height;
}

void AcuteTriangle::setWidth(unsigned width) {
    _width = width;
}

double AcuteTriangle::getPerimeter() const {
    return _width + sqrt(pow(_width, 2) + 4 * pow(_height, 2));
}

double AcuteTriangle::getArea() const {
    return _height * _width * (0.5);
}

double AcuteTriangle::getTextualPerimeter() const {
    return 4 * (_height - 1);
}

double AcuteTriangle::getTextualArea() const {
    return _height * _height;
}

Canvas AcuteTriangle::draw() const {
    Canvas can{getHeight(), getWidth()};

    for (int i = 1, k = 0; i <= _height; ++i) {
        while (k != 2 * i - 1) {
            can.put(i, k, _penChar);
            ++k;
        }
        k = 0;
    }
    return can;
}

