#define NOMINMAX
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <pxr/usd/usd/stage.h>


int main(int argc, char* argv[]) {
	
	
	std::cout << "Hello world!" << std::endl;
	double value = 1.0;
	double result = std::sin(value);

	std::cout << "The sin of " << value << " is " << result << std::endl;


}