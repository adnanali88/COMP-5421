#ifndef Mat2x2
#define Mat2x2_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <array>
#include <initializer_list>
using namespace std;

class Mat2x2
{
private:
	static double tolerance; // initial value = 1.0E-6

	double a; // top-left
	double b; // top-right
	double c; // bottom-left
	double d; // bottom-right

public:
	explicit Mat2x2(double = 0, double = 0, double = 0, double = 0);
	Mat2x2(const array<double, 4>&); // using std::array;
	Mat2x2(const array<array<double, 2>, 2>&); // using std::array;
	Mat2x2(const initializer_list<double>); // using std::initializer_list;

	static void setTolerance(double tol);
	static double getTolerance();

	Mat2x2(const Mat2x2&);
	~Mat2x2();
	double norm();
	Mat2x2 inverse();
	double det();

	void operator=(const Mat2x2);
	bool operator==(Mat2x2);
	Mat2x2 operator+=(Mat2x2);
	Mat2x2 operator+=(double);
	Mat2x2 operator-=(Mat2x2);
	Mat2x2 operator-=(double);
	Mat2x2 operator*=(Mat2x2);
	Mat2x2 operator*=(double);
	Mat2x2 operator/=(Mat2x2);
	Mat2x2 operator/=(double);
	Mat2x2 operator++(int);
	Mat2x2 operator++();
	Mat2x2 operator--(int);
	Mat2x2 operator--();
	Mat2x2 operator+();
	Mat2x2 operator-();
	Mat2x2 operator^(int );
	double& operator[](int);
	const double& operator[](int) const ;
	operator bool() const ;
	double operator()() const ;
	double& operator()(size_t r, size_t c);

	//friend ostream& operator << (ostream& out, const Mat2x2& x);
	//friend istream& operator >> (istream& in, Mat2x2& x);
	//friend Mat2x2 operator+(Mat2x2 a, Mat2x2 b);
	//friend Mat2x2 operator-(Mat2x2 a, Mat2x2 b);
	//friend Mat2x2 operator*(Mat2x2 a, Mat2x2 b);
	//friend Mat2x2 operator/(Mat2x2 a, Mat2x2 b);

	//friend Mat2x2 operator+(Mat2x2 a, double b);
	//friend Mat2x2 operator-(Mat2x2 a, double b);
	//friend Mat2x2 operator*(Mat2x2 a, double b);
	//friend Mat2x2 operator/(Mat2x2 a, double b);

	//friend Mat2x2 operator+(double a, Mat2x2 b);
	//friend Mat2x2 operator-(double a, Mat2x2 b);
	//friend Mat2x2 operator*(double a, Mat2x2 b);
	//friend Mat2x2 operator/(double a, Mat2x2 b);

	//friend bool operator<(Mat2x2 a, Mat2x2 b);
	//friend bool operator<=(Mat2x2 a, Mat2x2 b);
	//friend bool operator>(Mat2x2 a, Mat2x2 b);
	//friend bool operator>=(Mat2x2 a, Mat2x2 b);
	//friend bool operator!=(Mat2x2 a, Mat2x2 b);

};

#endif // !Mat2x2_H