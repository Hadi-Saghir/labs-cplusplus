#include <iostream>

int main(){

	int val, sum;
	sum = 0;

	while(std::cin >> val)
	{
		
		sum += val;
	}
	
	
	std::cout << sum;
}