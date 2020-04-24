#include <iostream>
#include "String.h"
#include <string>

int main() {
	Custom::String string("Nice");
	Custom::String string1(" play");
	std::cout << string + " team" + string1 << std::endl;
}