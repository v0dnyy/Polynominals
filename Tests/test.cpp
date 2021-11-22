#include "pch.h"
#include "../Polynominals/Header.h"
#include<complex>

TEST(Polynomials, MakePolynominal) {
	EXPECT_THROW(Polynomials<int> test(-1), const char*);
	EXPECT_THROW(Polynomials<double> test(-100), const char*);
	EXPECT_THROW(Polynomials<std::complex<double>> test(-5), const char*);
}

TEST(Polynomials, IndexPolynom) {
	Polynomials<int> test1(1);
	EXPECT_THROW(test1[5], const char*);
	EXPECT_THROW(test1[-1], const char*);
	EXPECT_EQ(1, test1[1]);
	EXPECT_EQ(1, test1[0]);
	Polynomials<double> test2(1);
	EXPECT_EQ((double)1, test2[1]);
	EXPECT_EQ((double)1, test2[0]);
	Polynomials<std::complex<double>> test3(1);
	EXPECT_EQ((std::complex<double>)1, test3[1]);
	EXPECT_EQ((std::complex<double>)1, test3[0]);
}

TEST(Polynomials, SetInPolynom) {
	Polynomials<int> test1(1);
	EXPECT_THROW(test1.SetCoefficient(1, 5), const char*);
	EXPECT_THROW(test1.SetCoefficient(1, -1), const char*);
	test1.SetCoefficient(10, 1);
	EXPECT_EQ(10, test1[1]);
	Polynomials<std::complex<double>> test2(1);
	test2.SetCoefficient((3.5, 1.5), 1);
	EXPECT_EQ((3.5, 1.5), test2[1]);
}

TEST(Polynomials, OperatorPlus) {
	Polynomials<int> test1(1), test2(1);
	test1 = test1 + test2;
	EXPECT_EQ(2, test1[1]);
	EXPECT_EQ(2, test1[0]);
	Polynomials<double> test3(1), test4(1);
	test3 = test3 + test4;
	EXPECT_EQ((double)2, test3[1]);
	EXPECT_EQ((double)2, test3[0]);
	Polynomials<std::complex<double>> test5(1), test6(1);
	test5 = test5 + test6;
	EXPECT_EQ((std::complex<double>)2, test5[1]);
	EXPECT_EQ((std::complex<double>)2, test5[0]);
}

TEST(Polynomials, OperatorMinus) {
	Polynomials<int> test1(1), test2(1);
	test1.SetCoefficient(2, 1);
	test1.SetCoefficient(2, 0);
	test1 = test1 - test2;
	EXPECT_EQ(1, test1[1]);
	EXPECT_EQ(1, test1[0]);
	Polynomials<double> test3(1), test4(1);
	test3.SetCoefficient((double)2, 1);
	test3.SetCoefficient((double)2, 0);
	test3 = test3 - test4;
	EXPECT_EQ((double)1, test3[1]);
	EXPECT_EQ((double)1, test3[0]);
	Polynomials<std::complex<double>> test5(1), test6(1);
	test5.SetCoefficient((std::complex<double>)2, 1);
	test5.SetCoefficient((std::complex<double>)2, 0);
	test5 = test5 - test6;
	EXPECT_EQ((std::complex<double>)1, test5[1]);
	EXPECT_EQ((std::complex<double>)1, test5[0]);
}

TEST(Polynomials, OperatorMultiplication) {
	Polynomials<int> test1(1);
	test1 = test1 * 3;
	EXPECT_EQ(3, test1[1]);
	EXPECT_EQ(3, test1[0]);
	Polynomials<double> test2(1);
	test2 = test2 * 3;
	EXPECT_EQ((double)3, test2[1]);
	EXPECT_EQ((double)3, test2[0]);
	Polynomials<std::complex<double>> test3(1);
	test3 = test3 * 3;
	EXPECT_EQ((std::complex<double>)3, test3[1]);
	EXPECT_EQ((std::complex<double>)3, test3[0]);
}

TEST(Polynomials, Result) {
	Polynomials<int> test1(1);
	EXPECT_EQ(3, test1.Result(2));
	Polynomials<double> test2(1);
	EXPECT_EQ((double)3, test2.Result(2));
	Polynomials<std::complex<double>> test3(1);
	EXPECT_EQ((std::complex<double>)3, test3.Result(2));
}