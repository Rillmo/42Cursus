#include "Base.hpp"

int main() {
	Base* test1;

	test1 = generate();
	identify(test1);
	identify(*test1);

	delete test1;
}