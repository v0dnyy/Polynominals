#include "pch.h"
#include "../Polynominals/Header.h"

TEST(Polynomials, MakePolynominal) {
	Polynomials test(3);
	test.SetCoefficient(2,2);
	EXPECT_EQ(2, test[2]);
}

TEST(Polynomials, IndexPolynom) {
	Polynomials test(1);
	Polynomials test1(100);
	EXPECT_THROW(test[5], const char*);
	EXPECT_THROW(test1[101], const char*);
}

TEST(Polynomials, SetInPolynom) {
	Polynomials test(3);
	EXPECT_THROW(test.SetCoefficient(1, 5), const char*);
	EXPECT_THROW(test.SetCoefficient(1, -1), const char*);
	test.SetCoefficient(2, 2);
	EXPECT_EQ(2, test[2]);
}

TEST(Polynomials, OperatorPlus) {
	Polynomials test1(2), test2(2);
	Polynomials test3(2);
	test3 = test1 + test2;
	EXPECT_EQ(2.0, test3[1]);
	EXPECT_EQ(2.0, test3[0]);
}

TEST(Polynomials, OperatorMinus) {
	Polynomials test1(2), test2(2);
	test1.SetCoefficient(2, 2);
	test1.SetCoefficient(2, 1);
	test1.SetCoefficient(2, 0);
	test1 = test1 - test2;
	EXPECT_EQ(1, test1[2]);
	EXPECT_EQ(1, test1[1]);
	EXPECT_EQ(1, test1[0]);
}

TEST(Polynomials, OperatorMultiplication) {
	Polynomials test(2);
	test = test * 2;
	EXPECT_EQ(2, test[2]);
	EXPECT_EQ(2, test[1]);
	EXPECT_EQ(2, test[0]);
}

TEST(Polynomials, Result) {
	Polynomials test(1);
	EXPECT_EQ(3, test.Result(2));
}