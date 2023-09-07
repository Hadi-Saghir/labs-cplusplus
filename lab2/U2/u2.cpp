#include <iostream>

void substitute_str (std::string& iostring, const std::string& before, const std::string& after){
    size_t pos = 0;
    //find: Find content in string (public member function)
    while ((pos = iostring.find(before, pos)) != std::string::npos) {
        iostring.replace(pos, before.length(), after);
        pos += after.length();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "argument needed" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    substitute_str(input, argv[2], argv[3]);


    std::cout << input << "\nDone" << std::endl;

    return 0;
}
