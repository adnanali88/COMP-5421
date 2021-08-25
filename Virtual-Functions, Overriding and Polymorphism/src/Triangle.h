
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"


class Triangle : public Shape {
public:
    Triangle(unsigned, unsigned, char, const std::string &);

    virtual void setHeight(unsigned) = 0;

    virtual void setWidth(unsigned) = 0;

    virtual double getPerimeter() const = 0;

    double getArea() const override = 0;

    virtual double getTextualPerimeter() const = 0;

    virtual double getTextualArea() const = 0;

    virtual Canvas draw() const = 0;

    virtual void setName(const std::string &) = 0;

    virtual void setPen(char) = 0;

    virtual std::string getName() const = 0;

    virtual unsigned getID() const = 0;

    virtual char getPen() const = 0;

    virtual unsigned getHeight() const = 0;

    virtual unsigned getWidth() const = 0;

    virtual std::string toString() const = 0;

};


#endif //TRIANGLE_H
