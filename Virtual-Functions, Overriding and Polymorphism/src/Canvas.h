
#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <sstream>
#include <cmath>

class Canvas {
public:
    // all special members are defaulted because ’grid’,
    // the only data member, is self-sufficient and efficient; that is,
    // it is equipped to handle the corresponding operations efficiently
    Canvas() = default;

    virtual ~Canvas() = default;

    Canvas(const Canvas &) = default;

    Canvas(Canvas &&) = default;

    Canvas &operator=(const Canvas &) = default;

    Canvas &operator=(Canvas &&) = default;


protected:
    std::vector<std::vector<char>> grid{};     // the only data member

    bool check(int r, int c) const;     // validates row r and column c

    void resize(size_t rows, size_t cols);     // resizes this Canvas’s dimensions


public:
    // creates this canvas’s (rows x columns) grid filled with blank characters
    Canvas(unsigned rows, unsigned columns, char fillChar = ' ');

    int getRows() const;

    int getColumns() const;

    Canvas flip_horizontal() const;

    Canvas flip_vertical() const;

    void print(std::ostream &) const;

    char get(int r, int c) const;

    void put(int r, int c, char ch);

    // draws text starting at row r and col c on the canvas
    void drawString(int r, int c, const std::string& text);

// copies the non-blank characters of "can" onto the invoking canvas;
// maps can’s origin to row r and column c on the invoking canvas
    void overlap(const Canvas &can, size_t r, size_t c);


};

std::ostream &operator<<(std::ostream &out, const Canvas &f);


#endif //CANVAS_H
