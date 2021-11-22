#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

template <typename T>
class Polynomials {
private:
	int n;
	struct Coefficients
	{
		int degree = 0;
		T value;
		struct Coefficients* next;
		Coefficients() {
			this->value = 1;
			this->next = nullptr;
		}
	};
	Coefficients* head;
public:
	Polynomials<T>(int size) {
		n = size;
		head = nullptr;
		Coefficients* pointer = head;
		for (size_t i = 0; i < size + 1; i++) {
			if (head == nullptr) {
				head = new Coefficients;
				head->degree = i;
				pointer = head;
			}
			else {
				while (pointer->next != nullptr) pointer = pointer->next;
				pointer->next = new Coefficients();
				pointer = pointer->next;
				pointer->degree = i;
			}
		}
	}
	T operator [](int index) {
		if (index > n) throw "Invalid index";
		Coefficients* tmp = head;
		for (int i = 0; i < index; i++) tmp = tmp->next;
		return tmp->value;
	}
	T SetCoefficient(T NewValue, int degree) {
		if (degree > n || degree < 0)  throw "Invaled index";
		Coefficients* tmp = head;
		Coefficients* new_head = head;
		for (int i = 0; i < degree; i++) {
			tmp = tmp->next;
		}
		tmp->value = NewValue;
		head = new_head;
	}
	T SetDegree(size_t NewDegree) {
		if (NewDegree < 0) throw "Invalid degree";
		n = NewDegree;
	}
	Polynomials<T> operator +(Polynomials<T>& rhs) {
		if (this->n > rhs.n) {
			Polynomials<T> result(this->n);
			Coefficients* ptr = this->head;
			Coefficients* rhs_ptr = rhs.head;
			Coefficients* res_prt = result.head;
			for (int i = 0; i < rhs.n + 1; i++) {
				res_prt->value = ptr->value + rhs_ptr->value;
				ptr = ptr->next;
				rhs_ptr = rhs_ptr->next;
				res_prt = res_prt->next;
			}
			for (int i = rhs.n; i < this->n; i++) {
				res_prt->value = ptr->value;
				ptr = ptr->next;
				res_prt = res_prt->next;
			}
			this->head = result.head;
		}
		if (this->n == rhs.n) {
			Polynomials<T> result(this->n);
			Coefficients* ptr = this->head;
			Coefficients* rhs_ptr = rhs.head;
			Coefficients* res_prt = result.head;
			for (int i = 0; i < rhs.n + 1; i++) {
				res_prt->value = ptr->value + rhs_ptr->value;
				ptr = ptr->next;
				rhs_ptr = rhs_ptr->next;
				res_prt = res_prt->next;
			}
			this->head = result.head;
		}
		if (this->n < rhs.n) {
			Polynomials<T> result(rhs.n);
			Coefficients* ptr = this->head;
			Coefficients* rhs_ptr = rhs.head;
			Coefficients* res_prt = result.head;
			for (int i = 0; i < this->n + 1; i++) {
				res_prt->value = ptr->value + rhs_ptr->value;
				ptr = ptr->next;
				rhs_ptr = rhs_ptr->next;
				res_prt = res_prt->next;
			}
			for (int i = this->n; i < rhs.n; i++) {
				res_prt->value = rhs_ptr->value;
				rhs_ptr = rhs_ptr->next;
				res_prt = res_prt->next;
			}
			this->head = result.head;
			this->n = result.n;
		}
		Polynomials<T> result(this->n);
		result.head = this->head;
		return result;
	}
	Polynomials<T> operator -(Polynomials<T>& rhs) {
		if (this->n > rhs.n) {
			Polynomials<T> result(this->n);
			Coefficients* ptr = this->head;
			Coefficients* rhs_ptr = rhs.head;
			Coefficients* res_prt = result.head;
			for (int i = 0; i < rhs.n + 1; i++) {
				res_prt->value = ptr->value - rhs_ptr->value;
				ptr = ptr->next;
				rhs_ptr = rhs_ptr->next;
				res_prt = res_prt->next;
			}
			for (int i = rhs.n; i < this->n; i++) {
				res_prt->value = -(ptr->value);
				ptr = ptr->next;
				res_prt = res_prt->next;
			}
			this->head = result.head;
		}
		if (this->n == rhs.n) {
			Polynomials<T> result(this->n);
			Coefficients* ptr = this->head;
			Coefficients* rhs_ptr = rhs.head;
			Coefficients* res_prt = result.head;
			for (int i = 0; i < rhs.n + 1; i++) {
				res_prt->value = ptr->value - rhs_ptr->value;
				ptr = ptr->next;
				rhs_ptr = rhs_ptr->next;
				res_prt = res_prt->next;
			}
			this->head = result.head;
		}
		if (this->n < rhs.n) {
			Polynomials<T> result(rhs.n);
			Coefficients* ptr = this->head;
			Coefficients* rhs_ptr = rhs.head;
			Coefficients* res_prt = result.head;
			for (int i = 0; i < this->n + 1; i++) {
				res_prt->value = ptr->value - rhs_ptr->value;
				ptr = ptr->next;
				rhs_ptr = rhs_ptr->next;
				res_prt = res_prt->next;
			}
			for (int i = this->n; i < rhs.n; i++) {
				res_prt->value = -(rhs_ptr->value);
				rhs_ptr = rhs_ptr->next;
				res_prt = res_prt->next;
			}
			this->head = result.head;
			this->n = result.n;
		}
		Polynomials<T> result(this->n);
		result.head = this->head;
		return result;
	}
	Polynomials <T> operator *(T scalar) {
		Polynomials<T> result(n);
		Coefficients* copy = head;
		Coefficients* copyres = result.head;
		for (int i = 0; i < n + 1; i++) {
			copyres->value = copy->value * scalar;
			copy = copy->next;
			copyres = copyres->next;
		}
		return result;
	}
	T Result(T x) {
		Coefficients* tmp = head;
		T res = 0;
		for (int i = 0; i < n + 1; i++) {
			res += tmp->value * pow(x, i);
			tmp = tmp->next;
		}
		return res;
	}
	friend std::ostream& operator << (std::ostream& out, const Polynomials<T>& polynomial) {
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << polynomial.head->value << "*x^" << 0;
		Coefficients* pointer = polynomial.head;
		pointer = pointer->next;
		for (int i = 1; i < polynomial.n + 1; i++) {
			if (pointer->value < 0) std::cout << pointer->value << "*x^" << i;
			else std::cout << "+" << pointer->value << "*x^" << i;
			pointer = pointer->next;
		}
		return std::cout;
	}
};