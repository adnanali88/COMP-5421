// test_driver_6789.cpp
// To facilitate marking, Please:
// include appropriate header files
// include prototypes of all functions called in this unit
// include the implementation of all the functions in this file;
// include other types, functors, or function facilitators of your choice in this file
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cassert>
#include <set>
using std::cout;

bool is_alphabetic(char c) {
    return !isalpha(c);
}

bool is_palindrome(const std::string &str)
{
    std::string temp;
    // first remove all non-alphabets and create temp string
    std::remove_copy_if(str.begin(), str.end(), std::inserter(temp, temp.begin()), is_alphabetic);
    // transfer temp to all lower case
    std::transform(temp.begin(), temp.end(), 
                    temp.begin(), 
                    [&] (char ch) { return std::tolower(ch); } );
    // check if left half is same as right half
    return std::equal(temp.begin(), temp.begin() + temp.size()/2, temp.rbegin());
}

void test_is_palindrome()
{
    std::string cat_i_saw = std::string("was it a car or A Cat I saW?");
    assert(is_palindrome(cat_i_saw) == true);
    cout << "the phrase \"" + cat_i_saw + "\" is a palindrome\n";

    std::string cat_u_saw = std::string("was it A Car or a cat U saW?");
    assert(is_palindrome(cat_u_saw) == false);
    cout << "the phrase \"" + cat_u_saw + "\" is not a palindrome\n";
}

template <class Iterator> // template header
std::pair<Iterator,bool> // function template return type;
second_max(Iterator start, Iterator finish) // function signature
{
    if (start == finish) {
        return std::make_pair(finish, false);
    }
    // max is largest, second_max is smallest
    Iterator max = start;
    Iterator second_max = finish;
    for (Iterator it = start; it != finish; it++) {
        // if greater than max, update max and move max to second_max
        if (*it > *max) {
            second_max = max;
            max = it;
        } else if (*it < *max) {
            // if between max and second max or second max is still not initialized, update second_max
            if (second_max == finish || *it > *second_max) {
                second_max = it;
            }
        }
    }
    // if second_max not found, there are no two distinct elements
    if (second_max == finish) {
        return std::make_pair(start, false);
    }
    return std::make_pair(second_max, true);

}

void test_second_max(std::vector<int> vec)
{
    // note: auto in the following statement is deduced as
    // std::pair<std::vector<int>::iterator, bool>
    auto retval = second_max(vec.begin(), vec.end());
    if (retval.second)
    {
        cout << "The second largest element in vec is "
            << *retval.first << std::endl;
    }
    else
    {
        if (retval.first == vec.end())
            cout << "List empty, no elements\n";
        else
            cout << "Container's elements are all equal to "
                << *retval.first << std::endl;
    }
}

int count_using_lambda (const std::vector<std::string>& vec, int n)
{
    auto Lambda = [n] (const std::string str) { return n == str.size(); };
    return count_if(vec.begin(), vec.end(), Lambda);
}

bool FreeFun(const std::string str, int n) {
    return n == str.size();
}

int count_using_Free_Func(const std::vector<std::string>& vec, int n) {
    auto bound_fn = std::bind(FreeFun, std::placeholders::_1, n);
    return count_if(vec.begin(), vec.end(), bound_fn);
} 

class countFunctor
{
private:
    int n;
public:
    countFunctor(int n) : n(n) {  }
    bool operator () (const std::string str) const {
        return n == str.size();
    }
};

int count_using_Functor(const std::vector<std::string>& vec, int n) {
    return count_if(vec.begin(), vec.end(), countFunctor(n));
}

void task_8_test_driver()
{
    std::vector<std::string> vecstr
    { "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
        "range", "[first", "last)", "for", "which", "pred", "is", "true."
    };
    cout << count_using_lambda(vecstr, 5) << std::endl;
    cout << count_using_Free_Func(vecstr, 5) << std::endl;
    cout << count_using_Functor(vecstr, 5) << std::endl;
    cout << "\n";
}

void multisetUsingMyComparator()
{
    // create a lambda operator that sorts the strings in groups by length
    // and then lexicographically
    auto myComparator = [](std::string s1, std::string s2) {
        if (s1.size() < s2.size()) { 
            return true;
        } else { 
            // check alphateical order only when length is same
            if (s1.size() == s2.size()) {
                if (s1.compare(s2) <= 0) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } 
    };
    // multiset with custom comparator
    std::multiset<std::string, decltype(myComparator)> strSet(myComparator); // an empty set
    // a set that uses the default std::less<int> to sort the set elements
    std::vector<std::string> vec {"C", "BB", "A", "CC", "A", "B",
                                    "BB", "A", "D", "CC", "DDD", "AAA" };

    // copy the vector elements to our set.
    // We must use a general (as oppsed to a front or back) inserter.
    // (set does not have push_front or push_back members,
    // so we can't use a front or back inserter)

    std::copy(vec.begin(), vec.end(), // source start and finish
                std::inserter(strSet, strSet.begin())); // destination start with
    // a general inserter

    // create an ostream_iterator for writing to cout,
    // using a space " " as a separator
    std::ostream_iterator<std::string> out(cout, " ");

    // output the set elements to cout separating them with a space
    std::copy(strSet.begin(), strSet.end(), out);
}

int main()
{
    // Task 6:
    test_is_palindrome();
    cout << "\n";
    
    // Task 7:
    std::vector<int> v1{ 1 }; // one element
    test_second_max(v1);
    std::vector<int> v2{ 1, 1 }; // all elements equal
    test_second_max(v2);
    std::vector<int> v3{ 1, 1, 3, 3, 7, 7 }; // at least with two distict elements
    test_second_max(v3);
    cout << "\n";
    
    // Task 8:
    task_8_test_driver();
    // Task 9:
    multisetUsingMyComparator();
    cout << "\n";
    return 0;
}
