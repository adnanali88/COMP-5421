
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(unsigned, unsigned, char, const std::string&);

    void setHeight(unsigned);

    void setWidth(unsigned);

    double getPerimeter() const override;

    double getArea() const override;

    double getTextualPerimeter() const override;

    double getTextualArea() const override;

    Canvas draw() const override;

    void setName(const std::string &) override;

    void setPen(char) override;

    std::string getName() const override;

    unsigned getID() const override;

    char getPen() const override;

    unsigned getHeight() const override;

    unsigned getWidth() const  override;

    std::string toString() const override;


};


#endif //RECTANGLE_H
