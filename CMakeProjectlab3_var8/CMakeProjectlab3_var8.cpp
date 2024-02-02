#include <iostream>

class String {
private:
	char* data;
public:
	String(const char* str) { // Конструктор по умолчанию
		int length = std::strlen(str);
		data = new char[length + 1];
		std::strcpy(data, str);
	}

	~String() { // деконструктор
		delete[] data;
	}
	friend std::ostream& operator<<(std::ostream& x, const String& object) { // operator cout
		x << object.data;
		return x;
	}

	friend std::istream& operator>>(std::istream& y, String& object) { // operator cin
		delete[] object.data;

		char buffer[100];
		y >> buffer;

		object.data = new char[std::strlen(buffer) + 1];
		std::strcpy(object.data, buffer);

		return y;
	}

};
int main()
{
	String Word("TRAVIS SCOT");

	std::cout << "Initial String: " << Word << std::endl;
	std::cout << "Enter a new string: ";
	std::cin >> Word;
	std::cout << "Updated String: " << Word << std::endl;
	return 0;
}
