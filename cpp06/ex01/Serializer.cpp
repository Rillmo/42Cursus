#include "Serializer.hpp"

/* Orthodox Canonical Form */
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& obj) {(void)obj;}
Serializer& Serializer::operator=(const Serializer& obj) {(void)obj; return *this;}
Serializer::~Serializer() {}
/* ----------------------- */

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}