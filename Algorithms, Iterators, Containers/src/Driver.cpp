#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>

#include "Dog.h"
using DogMap = std::multimap<std::string, Dog>;

DogMap findBreedRange(const DogMap& source, std::string key_breed)
{
    trim(key_breed);
    // fill in the blank
    DogMap res{};
    std::pair <DogMap::const_iterator, DogMap::const_iterator> it = source.equal_range(key_breed);
    for (DogMap::const_iterator t = it.first; t != it.second; t++) {
        res.emplace(std::make_pair((*t).first, (*t).second));
    }
    return res;
}

void load_DogMap_Using_Transform(DogMap& dog_map, std::string cvsfilename)
{
    std::ifstream input_file_stream(cvsfilename); // Create an input file stream
    if (!input_file_stream.is_open()) {
        std::cout << "Could not open file " + cvsfilename << std::endl;
        throw std::runtime_error("Could not open file " + cvsfilename);
    }

    // Get input stream and end of stream iterators
    std::istream_iterator<Dog> input_stream_begin{ input_file_stream };
    std::istream_iterator<Dog> input_stream_end{};

    // Copy Dog elements from [input_stream_begin, input_stream_end)
    // to dog_map using for_each function
    std::transform(input_stream_begin, input_stream_end, 
                    std::inserter(dog_map, dog_map.begin()), 
                    [&] (Dog d) { return std::make_pair(d.getBreed(), d); });

    input_file_stream.close(); // close the file stream
}

void load_DogMap_Using_For_Each(DogMap& dog_map, std::string cvsfilename)
{
    std::ifstream input_file_stream(cvsfilename); // Create an input file stream
    if (!input_file_stream.is_open()) {
        std::cout << "Could not open file " + cvsfilename << std::endl;
        throw std::runtime_error("Could not open file " + cvsfilename);
    }

    // Get input stream and end of stream iterators
    std::istream_iterator<Dog> input_stream_begin{ input_file_stream };
    std::istream_iterator<Dog> input_stream_end{};

    // Copy Dog elements from [input_stream_begin, input_stream_end)
    // to dog_map using for_each function
    std::for_each(input_stream_begin, input_stream_end, 
                    [&dog_map] (Dog d) { dog_map.emplace(std::make_pair(d.getBreed(), d));});

    input_file_stream.close(); // close the file stream
}

void load_DogMap(DogMap& dog_map, std::string cvsfilename)
{
    std::ifstream my_file_stream(cvsfilename); // Create an input file stream
    if (!my_file_stream.is_open()) {
        std::cout << "Could not open file " + cvsfilename << std::endl;
        throw std::runtime_error("Could not open file " + cvsfilename);
    }

    std::string line;
    while (std::getline(my_file_stream, line)) { // read a line
        std::stringstream my_line_stream(line); // turn the line into a string stream
        Dog dog{}; // create a Dog object, and
        my_line_stream >> dog; // initialize it using Dog’s extraction operator>>
        dog_map.emplace(dog.getBreed(), dog); // insert dog into dog_map
    }
    my_file_stream.close(); // close the file stream
}

std::ostream& operator<<(std::ostream& out, const DogMap& dogMap) {
    for (DogMap::const_iterator it = dogMap.begin(); it != dogMap.end(); it++) {
        out << std::setw(26) << (*it).first << " --> " << (*it).second << std::endl;
    }
    return out;
}

int main()
{
    std::multimap<std::string, Dog> dogMap{};
    std::string filename{ "dogDB2.csv" }; // adjust file path according
    // to your file directory
    load_DogMap(dogMap, filename);
    //cout << dogMap << "==========" << endl;
    DogMap brMap1 = findBreedRange(dogMap, std::string("Greyhound"));
    std::cout << brMap1 << "----------" << std::endl;
    DogMap brMap2 = findBreedRange(dogMap, std::string("Lakeland Terrier"));
    std::cout << brMap2 << "----------" << std::endl;
    DogMap brMap3 = findBreedRange(dogMap, std::string("Pug"));
    std::cout << brMap3 << "----------" << std::endl;
    DogMap brMap4 = findBreedRange(dogMap, std::string("Xyz"));
    std::cout << brMap4 << "----------" << std::endl;
    return 0;
}