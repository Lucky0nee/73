/*
  Змініть наступну програму, замінивши звичайний вказівник на розумний вказівник std::shared_ptr
На додаткову оцінку допишіть метод для скорочення раціональних дробів
*/
#include <iostream>

class Fraction {
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{ }

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
private:
	int m_numerator = 0;
	int m_denominator = 1;
};

std::unique_ptr<Fraction> DoSomething(int firstNum, int secondNum) {
	for (int i = 2; i < 17; i++) {
		if (firstNum % i == 0 && secondNum % i == 0) {
			firstNum /= i; //std::cout << firstNum << " ";
			secondNum /= i;  //std::cout << secondNum << " ";
			i = 2;
		}
		//std::cout << i;
	}
	return std::make_unique<Fraction>(firstNum, secondNum);
}

void printFraction(std::shared_ptr<Fraction> ptr) { // const Fraction* const ptr
	if (ptr) std::cout << *ptr;
}

int main() {
	std::shared_ptr<Fraction> ptr = std::make_unique<Fraction>(49, 11711);

	std::cout << "\n" << "Початковий дріб: ";
	printFraction(std::move(ptr));
	std::cout << "\n" << "Скорочений дріб: ";
	printFraction(std::move(DoSomething(49, 11711)));

	return 0;
}
