#include <stdio.h>
#include "Header.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>

int GetKey() noexcept {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int Ent() noexcept {
	while (true) {
		int key = GetKey();
		if (key == 13) return key;
	}
}

void FirstMenu(Polynomials main) {
	while (true) {
		system("cls");
		std::cout << main;
		std::cout << "\n1. Change coefficient";
		std::cout << "\n2. Add to another polynomial";
		std::cout << "\n3. Subtract another polynomial";
		std::cout << "\n4. Multiply by a scalar number";
		std::cout << "\n5. Calculate for a given x";
		std::cout << "\n6. Exit";
		int m = GetKey();
		if (m == 49) {
			system("cls");
			std::cout << "To what degree do you want to change the coefficient?\n";
			int degreetochange;
			std::cin >> degreetochange;
			std::cout << "Enter a new coefficient: ";
			double newcoef;
			std::cin >> newcoef;
			try {
				main.SetCoefficient(newcoef, degreetochange);
			}
			catch (const char* err) {
				std::cout << "Error: " << err;
				return;
			}
			std::cout << "The change was successful! Press Enter to continue...";
			Ent();
		}
		if (m == 50) {
			system("cls");
			std::cout << "Enter the greatest degree of the second polynomial!\n";
			int maxdegree2;
			std::cin >> maxdegree2;
			try {
				Polynomials second(maxdegree2);
				int i = 0;
				while (i != maxdegree2 + 1) {
					std::cout << "Coefficient at i = " << maxdegree2 - i << ":";
					double coef = 0;
					std::cin >> coef;
					second.SetCoefficient(coef, maxdegree2 - i);
					i++;
				}
				std::cout << "Second polynomial: ";
				std::cout << second;
				std::cout << "\n";
				main = main + second;
			}
			catch (const char* err) {
				std::cout << "Error: " << err;
				return;
			}
			std::cout << "The addition was successful! Press Enter to continue...";
			Ent();
		}
		if (m == 51) {
			system("cls");
			std::cout << "Enter the greatest degree of the second polynomial!\n";
			int maxdegree2;
			std::cin >> maxdegree2;
			try {
				Polynomials second(maxdegree2);
				int i = 0;
				while (i != maxdegree2 + 1) {
					std::cout << "Coefficient at i = " << maxdegree2 - i << ":";
					double coef = 0;
					std::cin >> coef;
					second.SetCoefficient(coef, maxdegree2 - i);
					i++;
				}
				std::cout << "Second polynomial: ";
				std::cout << second;
				std::cout << "\n";
				main = main - second;
			}
			catch (const char* err) {
				std::cout << "Error: " << err;
				return;
			}
			std::cout << "Subtraction was successful! Press Enter to continue...";
			Ent();
		}
		if (m == 52) {
			system("cls");
			std::cout << "Enter the number by which the polynomial will be multiplied: ";
			double scalar;
			std::cin >> scalar;
			main = main * scalar;
			std::cout << "Multiplication by a number was successful! Press Enter to continue...";
			Ent();
		}
		if (m == 53) {
			system("cls");
			std::cout << "Enter x: ";
			double x;
			std::cin >> x;
			std::cout << "" << main.Result(x);
			std::cout << "\nPress Enter to continue...";
			Ent();
		}
		if (m == 54) break;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Enter the greatest degree of the polynomial!\n";
	int maxdegree = 0;
	try {
		std::cin >> maxdegree;
		Polynomials main(maxdegree);
		FirstMenu(main);
	}
	catch (const char* err) {
		std::cout << "Error: " << err;
	}
	return 0;
}