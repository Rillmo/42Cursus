#include <iostream>
#include <fstream>
#include <string>

std::string findAndReplace(std::string line, std::string str1, std::string str2) {
	std::string result = "";
	std::size_t pos;
	std::size_t start = 0;

	pos = line.find(str1);
	while (pos != std::string::npos && str1.length() != 0) {
		result.append(line.substr(start, pos - start));
		result.append(str2);
		start = pos + str1.length();
		pos = line.find(str1, start);
	}
	result.append(line.substr(start, line.length()));
	return result;
}

int main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cout << "[ARGUMENT ERROR]" << std::endl;
		return (1);
	}
	std::string filename(argv[1]);
	std::string str1(argv[2]);
	std::string str2(argv[3]);
	std::ifstream origin;
	std::ofstream replace;
	std::string line;

	origin.open(filename);
	if (!origin.is_open()){
		std::cout << "[INFILE OPENING ERROR]" << std::endl;
		return (1);
	}
	replace.open(filename + ".replace");
	if (!replace.is_open()) {
		std::cout << "[OUTFILE OPENING ERROR]" << std::endl;
		return (1);
	}

	while (std::getline(origin, line)) {
		std::cout << findAndReplace(line, str1, str2) << std::endl;
	}
	
	origin.close();
	replace.close();

	// std::cout << filename << std::endl;
	// std::cout << str1 << std::endl;
	// std::cout << str2 << std::endl;
}