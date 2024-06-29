#include "PmergeMe.hpp"
#include <iomanip>

int main(int argc, char** argv) {
	try {
		PmergeMe pm(argc, argv);

		clock_t vtime = clock();
		pm.sort(VEC);
		vtime = clock() - vtime;
		clock_t dtime = clock();
		pm.sort(DEQ);
		dtime = clock() - dtime;

		std::cout << std::setw(9) << std::left << "VBefore: ";
		display(pm.getVorigin(), true);
		std::cout << std::setw(9) << std::left << "DBefore: ";
		display(pm.getDorigin(), true);
		std::cout << std::setw(9) << std::left << "VAfter: ";
		display(pm.getVec(), true);
		std::cout << std::setw(9) << std::left << "DAfter: ";
		display(pm.getDeq(), true);

		std::cout << "Time to process a range of " << pm.getVec().size() << " elements with std::vector : " << 1000*1000.0* (vtime) / CLOCKS_PER_SEC << " us" << std::endl;
		std::cout << "Time to process a range of " << pm.getDeq().size() << " elements with std::deque  : " << 1000*1000.0* (dtime) / CLOCKS_PER_SEC << " us" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}