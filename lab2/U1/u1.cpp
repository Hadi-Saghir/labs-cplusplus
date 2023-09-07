#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "argument needed" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);
    
    if (n < 2 || n > 10000) {
        std::cout << "Input must be between 2 and 10000" << std::endl;
        return 1;
    }

    // Create a list from 2 to n
    bool* isPrime = new bool[n + 1];

    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }

    // next number is prime
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            //if prime, eliminate all multiples
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Print prime numbers
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            std::cout << i << " ";
        }
    }

    std::cout << "\nDone" << std::endl;

    delete[] isPrime;
    return 0;
}