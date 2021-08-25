
#include "Shape.h"

#include <utility>

unsigned Shape::_universalID = 0;

Shape::Shape(unsigned height, unsigned width, char pen_char, std::string name)
        : _height(height),
          _width(width),
          _penChar(pen_char),
          _name(std::move(name)) {}

std::ostream &operator<<(std::ostream &out, const Shape& shp) {
    out << shp.toString();
    return out;
}
