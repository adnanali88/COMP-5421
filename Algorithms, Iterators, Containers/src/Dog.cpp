// Dog.cpp
#include "Dog.h"
#include <algorithm>

std::ostream &operator<<(std::ostream &sout, const Dog &dog) {
    sout << dog.name << ", " << dog.breed << ", "
        << dog.age << ", " << dog.gender;
    return sout;
}

std::istream& operator>>(std::istream& sin, Dog& d) {
    bool ok = false;
    if (std::getline(sin, d.name, ',')) {
        trim(d.name);
        if (std::getline(sin, d.breed, ',')) {
            trim(d.breed);
            if (std::getline(sin, d.age, ',')) {
                trim(d.age);
                if (std::getline(sin, d.gender)) {
                    trim(d.gender);
                    ok = true;
                }
            }
        }
    }
    if (!ok && !sin.eof()) {
        throw std::runtime_error("Invalid input line ");
    }
    return sin;
}

void trim( std::string& str) {
    // trim leading and trailing whitespaces in str
    std::string whitespaces(" \t\f\v\n\r");
    // trim leading whitespaces first
    size_t start = str.find_first_not_of(whitespaces);
    if (start == std::string::npos) {
        str = "";
    } else {
        str = str.substr(start);
    }
    // trim trailing whitespaces
    size_t end = str.find_last_not_of(whitespaces);
    if (end == std::string::npos) {
        str = "";
    } else {
        str = str.substr(0, end+1);
    }
    return;
}