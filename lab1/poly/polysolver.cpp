#include <iostream>
#include "poly2.cpp"
#include <vector>
#include <fstream>

void printRoots(const std::vector<float>& roots, Poly2 poly) {
    	if (roots.size() == 0) {
        	std::cout << "No real roots." << std::endl;
    	} else if (roots.size() == 1) {
        	std::cout << "One real double root: " << roots[0] << std::endl;
    	} else {
        	std::cout << "Two real roots : " << roots[0] << " and " << roots[1] << std::endl;
    	}

	std::cout << "Evaluate poly at x = 3: " << poly.eval(3) << std::endl;
}

int main(int argc, const char* argv[])
{

	std::cout << "Root-finding started..." << std::endl;

	std::ifstream inputFile(argv[1]);

	float a,b,c;

	while(inputFile >> a >> b >> c){
		std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

		Poly2 poly(a,b,c);
    		printRoots(poly.findRoots(), poly);
	}
	
	inputFile.close();
    
	return 0;
}