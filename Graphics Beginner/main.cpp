#include "first_app.h"

// std
#include <iostream>
#include <stdexcept>
#include <cstdlib>

int main() {
	lve::first_app app{};

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
    return 0;
}