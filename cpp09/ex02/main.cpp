#include "PmergeMe.hpp"
#include <cctype>

int main(int argc, char** argv) {
	try {
		PmergeMe pm(argc, argv);

		pm.sort();
		// pm.displayVector();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}