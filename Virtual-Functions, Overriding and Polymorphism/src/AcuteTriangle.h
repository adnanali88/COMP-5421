

#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H

#include "Triangle.h"

class AcuteTriangle : public Triangle {
public:
    explicit AcuteTriangle(unsigned, char, const std::string&);

    void setHeight(unsigned) override;

    void setWidth(unsigned) override;

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

    unsigned getWidth() const override;

    std::string toString() const override;
};


#endif //ACUTETRIANGLE_H
