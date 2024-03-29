#include <iostream>
#include <string>

std::string	strToUpper(std::string str) {
	int	len = str.length();

	for (int i=0; i<len; i++) {
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}

int main(int argc, char *argv[]) {
	std::string str;

	if (argc == 1)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i=1; i<argc; i++) {
			str.append(strToUpper(argv[i]));
		}
	}
	std::cout << str << std::endl;
	return 0;
}