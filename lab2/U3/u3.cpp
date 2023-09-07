#include <iostream>

// https://en.cppreference.com/w/c/string/byte/strncmp
// https://cplusplus.com/reference/cstring/

char* substitute_str(const char* input, const char* before, const char* after) {
    size_t input_length = strlen(input);
    size_t before_length = strlen(before);
    size_t after_length = strlen(after);
    size_t result_length = input_length;

    // count required size
    for (size_t i = 0; i < input_length; i++) {
        //strncmp:  Compare characters of two strings
        if (strncmp(input + i, before, before_length) == 0) {
            result_length += after_length - before_length;
            i += before_length - 1;
        }
    }

    // create result with required size
    char* result = new char[result_length + 1];

    size_t result_pos = 0;

    // U2 but with cstring functions instead of string functions.
    for (size_t i = 0; i < input_length; i++) {
        if (strncmp(input + i, before, before_length) == 0) {
            //strcpy: Copy characters from string
            strcpy(result + result_pos, after);
            result_pos += after_length;
            i += before_length - 1;
        } else {
            result[result_pos] = input[i];
            result_pos++;
        }
    }

    result[result_length] = '\0'; // Null terminate

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "argument needed" << std::endl;
        return 1;
    }

    char* result = substitute_str(argv[1], argv[2], argv[3]);

    std::cout << result << "\nDone" << std::endl;

    return 0;
}