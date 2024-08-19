#include "PmergeMe.hpp"


int main(int argc, char **argv) {

    if (argc < 2) {std::cerr << "Error in number of arguments\n"; return 1;}
    PmergeMe m;
    for (int i = 1; i < argc; i++) {
        char* endptr;
        long num = strtol(argv[i], &endptr, 10);
        if (endptr == argv[i]) 
            {std::cerr << "Error: invalid number."; return 1;}
        if (num > INT_MAX || num < 0) {std::cerr << "Error: invalid number."; return 1;}
        m.vector.push_back(num);
        m.deque.push_back(num);
    }
    std::cout << "Before: ";
    std::vector<int>::iterator it = m.vector.begin();
    int i = 0;
    while (it != m.vector.end() && i < 5) {
        std::cout << *it++ << " "; i++;}
    if (m.vector.size() >= 5)
        std::cout << "[...]\n";
    std::cout << std::endl;

    std::clock_t v_time = clock();
    m.recursive(m.vector, 0, m.vector.size() -1);
    v_time = clock() - v_time;

    std::cout << std::endl << "After: ";
    it = m.vector.begin();
    i = 0;
    while (it != m.vector.end() && i < 5) {
        std::cout << *it++ << " "; i++;}
    if (m.vector.size() >= 5)
        std::cout << "[...]\n";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << m.vector.size() << " elements with std::vector" <<  " : " << v_time << "s" << std::endl;

    std::clock_t d_time = clock();
    m.recursive(m.deque, 0, m.deque.size() -1);
    d_time = clock() - d_time;

    std::cout << "Time to process a range of " << m.deque.size() << " elements with std::deque" <<  " : " << d_time << "s" << std::endl;
}

