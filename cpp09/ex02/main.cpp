#include "PmergeMe.hpp"
#include <iomanip>

int main(int argc, char** argv) {
	try {
		PmergeMe pm(argc, argv);

		clock_t vstart = clock();
		pm.sort();
		clock_t vend = clock();
		// clock_t dstart = clock();
		// pm.sort(pm.getDeq());
		// clock_t dend = clock();

		std::cout << std::setw(9) << std::left << "Before: ";
		display(pm.getVorigin(), true);
		std::cout << std::setw(9) << std::left << "After: ";
		display(pm.getVec(), true);

		std::cout << "Time to process a range of 5 elements with std::vector : " << static_cast<double>(vend-vstart) << " us" << std::endl;
		// std::cout << "Time to process a range of 5 elements with std::deque  : " << static_cast<double>(dend-dstart) << " us" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}