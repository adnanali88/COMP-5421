
#include "Canvas.h"

bool Canvas::check(int r, int c) const {
    return (r < grid.size() && c < grid.back().size());

}

void Canvas::resize(size_t rows, size_t cols) {
    grid.resize(rows);
    for (auto &col : grid)
        col.resize(cols);

}

Canvas::Canvas(unsigned rows, unsigned columns, char fillChar) {
    grid = std::vector<std::vector<char>>(rows, std::vector<char>(columns, fillChar));
}

int Canvas::getRows() const {
    return grid.size();
}

int Canvas::getColumns() const {
    return grid.back().size();
}

Canvas Canvas::flip_horizontal() const {
    Canvas flipped = *this;
    for (auto &row : flipped.grid)
        for (int i = 0; i < row.size() / 2; ++i)
            std::swap(row[i], row[row.size() - 1 - i]);

    return flipped;
}

Canvas Canvas::flip_vertical() const {

    Canvas flipped = *this;
    for (int i = 0; i < flipped.grid.size() / 2; ++i)
        std::swap(flipped.grid[i], flipped.grid[flipped.grid.size() - 1 - i]);

    return flipped;
}

void Canvas::print(std::ostream &out) const {
    for (const auto &row : grid) {
        for (const auto &col : row)
            out << col;
        out << std::endl;
    }
}

char Canvas::get(int r, int c) const {
    return (check(r, c) ? grid[r][c] : '0');
}

void Canvas::put(int r, int c, char ch) {
    if (check(r, c))
        grid[r][c] = ch;
}

void Canvas::drawString(int r, int c, const std::string &text) {
    if (check(r, c) && (c + text.size() < getColumns()))
        for (int i = 0; i < text.size(); ++i)
            grid[r][c + i] = text[i];

}

void Canvas::overlap(const Canvas &can, size_t r, size_t c) {
    if (check(r, c) && (r + can.getRows()) < getRows() && (c + can.getColumns()) < getColumns())
        for (int i = 0; i < can.getRows(); ++i)
            for (int j = 0; j < can.getColumns(); ++j)
                if (can.get(i, j) != ' ')
                    grid[r + i][c + j] = can.get(i, j);
}

std::ostream &operator<<(std::ostream &out, const Canvas &f) {
    f.print(out);
    return out;
}

