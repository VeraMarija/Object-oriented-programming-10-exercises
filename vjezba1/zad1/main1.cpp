// Unesite sljedeci program i modificirajte ga testirajuci gornje manipulatore.
#include <iostream>
#include <iomanip>
int main()
{
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::noboolalpha << flag << std::endl;
	int a = 255;
	int b = 543;
	std::cout << "hex a -->" << std::hex << a << std::endl;
	std::cout << "hex b -->" << std::uppercase << b << std::endl;
	std::cout << "dec " << std::dec << a << std::uppercase << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;
	double c = 0.00000457485454;
	std::cout << "c = " << std::scientific;
	std::cout << std::setprecision(5) << std::setw(5);
	std::cout << c << std::endl;
}