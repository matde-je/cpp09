#include "PmergeMe.hpp"


int main(int argc, char **argv) {

    if (argc < 2) {std::cerr << "Error in number of arguments\n"; return 1;}
   
    bool isCommand = false;
    PmergeMe m;
    for (int i = 1; i < argc; i++) {
        char* endptr;
        long num = strtol(argv[i], &endptr, 10);
        if (endptr == argv[i]) {
            isCommand = true;
            break;
        }
        if (num > INT_MAX || num < 0) {std::cerr << "Error: invalid number."; return 1;}
        m.vector.push_back(num);
        m.deque.push_back(num);
    }
    if (isCommand) {
        std::string command = argv[1];
        if (argc > 2 || argv[1][strlen(argv[1]) - 1] != '\"') {std::cerr << "Error in arguments\n"; return 1;}
        FILE* pipe = popen(command.c_str(), "r");  //execute command
        if (!pipe) {std::cerr << "Error: Failed to execute command."; return 1;}
        char buffer[128];
        std::string output;
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) 
            output += buffer;
        pclose(pipe);
        std::stringstream ss(output); //creating an std::stringstream object named ss and initializing it with the contents of the output string.
        std::string str;
        int nb;
        while (std::getline(ss, str, ' ')) {
            if (!str.empty()) {
                if (str.length() > 10 || (str.length() == 10 && str > "2147483647")) {std::cerr << "Error: overflow."; return 1;}
                if (str.find_first_not_of("0123456789") != std::string::npos) {std::cerr << "Error: non digit."; return 1;}
                std::istringstream(str) >> nb;
                m.vector.push_back(nb);
                m.deque.push_back(nb);
        }}}

    std::cout << "Before: ";
    std::vector<int>::iterator it = m.vector.begin();
    int i = 0;
    while ((it != m.vector.end() && !isCommand) || (isCommand && i < 5)) {
        std::cout << *it++ << " "; i++;}
    if (isCommand && m.vector.size() >= 5)
        std::cout << "[...]\n";
    std::cout << std::endl;

    std::clock_t v_time = clock();
    m.recursive(m.vector, 0, m.vector.size() -1);
    v_time = clock() - v_time;

    std::cout << std::endl << "After: ";
    it = m.vector.begin();
    i = 0;
    while ((it != m.vector.end() && !isCommand) || (isCommand && i < 5)) {
        std::cout << *it++ << " "; i++;}
    if (isCommand && m.vector.size() >= 5)
        std::cout << "[...]\n";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << m.vector.size() << " elements with std::vector" <<  " : " << v_time << "s" << std::endl;

    std::clock_t d_time = clock();
    m.recursive(m.deque, 0, m.deque.size() -1);
    d_time = clock() - d_time;

    std::cout << "Time to process a range of " << m.deque.size() << " elements with std::deque" <<  " : " << d_time << "s" << std::endl;
}

