#include "Serializer.hpp"

int main() {
	Data origin;
	uintptr_t raw;
	Data *res;

	origin.inner = "test";

	raw = Serializer::serialize(&origin);
	std::cout << raw << std::endl;

	res = Serializer::deserialize(raw);
	std::cout << (*res).inner << std::endl;

}