#include "PmergeMe.hpp"


int main(int argc, char **argv){

    if (argc < 2) {
        std::cerr << "Error in number of arguments\n"; return 1;}

    PmergeMe m;
    int i = 0;
    while (argv[++i]) {
        if (strtol(argv[i]) >= 0 && strtol(argv[i]) < 2147483648)
            vector.push_back(atoi(argv[i]));
            deque.push_back(atoi(argv[i]));
    }
    m.mergeSort();
    
    std::clock_t v_time = clock();



    v_time = clock() - v_time;

    std::clock_t d_time = clock();

    m.mergeSort();


    d_time = clock() - d_time;
}

