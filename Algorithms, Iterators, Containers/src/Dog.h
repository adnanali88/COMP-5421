// Dog.h
#ifndef DOG_H
#define DOG_H
#include <iostream>
#include <string>
using std::string;

class Dog {
    string name;
    string breed;
    string age;
    string gender;
public:
    Dog() = default;
    virtual ~Dog() = default;
    Dog(const Dog&) = default;
    Dog(Dog&&) = default;
    Dog& operator=(const Dog&) = default;
    Dog& operator=(Dog&&) = default;

    Dog(string n, string b, string a, string g) : name(n), breed(b), age(a), gender(g) { }

    // accessors
    string getBreed() const { return breed; }
    string getName() const { return name; }
    string getAge() const { return age; }
    string getGender() const { return gender; }
    // mutators
    void setBreed(string breed) { this->breed = breed; }
    void setName(string name) { this->name = name; }
    void setAge(string age) { this->age = age; }
    void setGender(string gender){ this->gender = gender; }

    friend std::ostream& operator<<(std::ostream&, const Dog&); // done
    friend std::istream& operator>>(std::istream&, Dog&); // done
};
void trim(string& str); // on your to-do list
#endif /* DOG_H */