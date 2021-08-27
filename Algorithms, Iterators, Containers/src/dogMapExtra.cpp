#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>

#include "Dog.h"
using DogMapReversed = std::multimap<std::string, Dog, std::greater<std::string>>;

void load_DogMap_Using_Transform(DogMapReversed& dog_map, std::string cvsfilename)
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

std::ostream& operator<<(std::ostream& out, const DogMapReversed& dogMap) {
    for (DogMapReversed::const_iterator it = dogMap.begin(); it != dogMap.end(); it++) {
        out << std::setw(26) << (*it).first << " --> " << (*it).second << std::endl;
    }
    return out;
}

int main()
{
    DogMapReversed dogMap{};
    std::string filename{ "./dogDB.csv"}; // adjust file path according
    // to your file directory
    load_DogMap_Using_Transform(dogMap, filename);
    std::cout << dogMap << "==========" << std::endl;
    return 0;
}
