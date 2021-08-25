
#ifndef SHAPE_H
#define SHAPE_H



#include "Canvas.h"

class Shape {
protected:
    std::string _name{};
    unsigned _id{};
    char _penChar{};
    unsigned _height{};
    unsigned _width{};

    static unsigned _universalID;

public:
    Shape(unsigned, unsigned, char, std::string);

    virtual void setName(const std::string &) = 0;

    virtual void setPen(char) = 0;

    virtual std::string getName() const = 0;

    virtual unsigned getID() const = 0;

    virtual char getPen() const = 0;

    virtual unsigned getHeight() const = 0;

    virtual unsigned getWidth() const = 0;

    virtual std::string toString() const = 0;

    virtual Canvas draw() const = 0;

    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    virtual double getTextualArea() const = 0;

    virtual double getTextualPerimeter() const = 0;

    friend std::ostream &operator<<(std::ostream &, const Shape &);
};


#endif //SHAPE_H
