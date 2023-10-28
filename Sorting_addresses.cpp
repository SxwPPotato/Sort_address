#include <iostream>
#include <fstream>
#include <string>

class Sort_address {
private:

	std::string city;
	std::string street;
	int number_house;
	int number_room;

public:

	Sort_address() {
		number_room = number_house = 0;
		street = city = "";
	}

	Sort_address(std::string city, std::string street, int number_house, int number_room) {
		this->city = city;
		this->street = street;
		this->number_house = number_house;
		this->number_room = number_room;
	}

	std::string out_city() {
		return city;
	}

	std::string String_output() {
		return city + ", " + street + ", " + std::to_string(number_house) + ", " + std::to_string(number_room) + "\n";
	}
	
};


void sort(Sort_address* address_amount, int& amount) {
	for (int i = 0; i < amount-1; ++i) {
		for (int j = 0; j < amount - 1;++j) {
			if(address_amount[j].out_city().compare(address_amount[j+1].out_city()) > 0) {
				Sort_address temp = address_amount[j + 1];
				address_amount[j + 1] = address_amount[j];
				address_amount[j] = temp;
			}
		}
	}
	
}


int main()
{
    setlocale(LC_ALL, "russian");
    std::ifstream filein("in.txt");
	std::ofstream fileout("out.txt");

	if (filein.is_open())
		std::cout << "Все ОК! Файл открыт!\n\n";
	else
	{
		std::cout << "Файл не открыт!\n\n";
		return -1;
	}

	std::string street;
	std::string city;
	int number_house;
	int number_room;
	int amount;
	filein >> amount;
	Sort_address* address_amount = new Sort_address[amount];
	fileout << amount << "\n";


	for (int i = 0; i < amount; ++i) {
		filein >> city;
		filein >> street;
		filein >> number_house;
		filein >> number_room;
		Sort_address address(city, street, number_house, number_room);
		address_amount[i] = address;
		
	}


	sort(address_amount, amount);

	
	for (int i = 0; i < amount ; ++i) {
		fileout << address_amount[i].String_output();
	
	}

	delete[] address_amount;
}

