#include "Mat2x2.h"
using namespace std;


Mat2x2::Mat2x2(double w , double x , double y , double z)
{
	a = w ;
	b = x ;
	c = y ;
	d = z ;
}

Mat2x2::Mat2x2(const array<double, 4>& y)
{

	a = y[0] ;
	b = y[1] ;
	c = y[2] ;
	d = y[3];
}

Mat2x2::Mat2x2(const array<array<double, 2>, 2>& y)
{

	a = y[0][0];
	b = y[0][1];
	c = y[1][0];
	d = y[1][1];
}

Mat2x2::Mat2x2(const initializer_list<double> y)
{

	double arr[4] = {0};
	int i = 0 ;

	std::initializer_list<double>::iterator it; 
	for (it = y.begin(); it != y.end(); ++it)
	{
		if (i > 3)
			break;

		arr[i] = *it ;
		i++;
	}

	a = arr[0];
	b = arr[1];
	c = arr[2];
	d = arr[3];
	
}

Mat2x2::Mat2x2(const Mat2x2 &x) 
{
	this->a = x.a;
	this->b = x.b;
	this->c = x.c;
	this->d = x.d;
}

void Mat2x2::setTolerance(double tol)
{
	tolerance = tol;
}

double Mat2x2::getTolerance()
{
	return tolerance;
}

Mat2x2::~Mat2x2()
{
	a = 0 ;
	b = 0 ;
	c = 0 ;
	d = 0 ;
}

double Mat2x2::norm() 
{
	double norm = this->a*this->a + this->b*this->b +this->c*this->c + this->d*this->d ;
	norm = sqrt(norm) ; 
	return norm ;
}

Mat2x2 Mat2x2::inverse()
{
	Mat2x2 inv ;

	double det = this->det();
	if (det != 0)
	{
		inv.a = this->d / det ;
		inv.d = this->a / det ;
		inv.b = -(this->b) /det ;
		inv.c = -(this->c) / det ;
	}

	return inv ;
}


double Mat2x2::det()
{
	double det = this->a*this->d - this->b*this->c ;
	return det;
}

void Mat2x2::operator=(Mat2x2 x)
{
	this->a = x.a;
	this->b = x.b;
	this->c = x.c;
	this->d = x.d;
}

bool Mat2x2::operator==(Mat2x2 x)
{
	Mat2x2 a = *this;
	
	a -= x ;

	if (a.norm() <= tolerance)
		return true;
	else
		return false;

}

Mat2x2 Mat2x2::operator+=(Mat2x2 x)
{
	this->a = this->a + x.a ;
	this->b = this->b + x.b ;
	this->c = this->c + x.c ;
	this->d = this->d + x.d ;

	return *this ;
}

Mat2x2 Mat2x2::operator+=(double x)
{
	this->a = this->a + x ;
	this->b = this->b + x ;
	this->c = this->c + x ;
	this->d = this->d + x ;

	return *this;
}

Mat2x2 Mat2x2::operator-=(Mat2x2 x)
{
	this->a = this->a - x.a;
	this->b = this->b - x.b;
	this->c = this->c - x.c;
	this->d = this->d - x.d;

	return *this;
}

Mat2x2 Mat2x2::operator-=(double x)
{
	this->a = this->a - x;
	this->b = this->b - x;
	this->c = this->c - x;
	this->d = this->d - x;

	return *this;
}

Mat2x2 Mat2x2::operator*=(Mat2x2 x)
{
	Mat2x2 mul = *this ;

	this->a = mul.a * x.a + mul.b * x.c ;
	this->b = mul.a * x.b + mul.b * x.d ;
	this->c = mul.c * x.a + mul.d * x.c ;
	this->d = mul.c * x.b + mul.d * x.d ;

	return *this;
}

Mat2x2 Mat2x2::operator*=(double x)
{
	this->a = this->a * x;
	this->b = this->b * x;
	this->c = this->c * x;
	this->d = this->d * x;

	return *this;
}

Mat2x2 Mat2x2::operator/=(Mat2x2 x)
{
	*this *= x.inverse();

	return *this;
}

Mat2x2 Mat2x2::operator/=(double x)
{
	this->a = this->a / x;
	this->b = this->b / x;
	this->c = this->c / x;
	this->d = this->d / x;

	return *this;
}

Mat2x2 Mat2x2::operator++(int)
{
	Mat2x2 temp = *this ;

	this->a = this->a + 1 ;
	this->b = this->b + 1 ;
	this->c = this->c + 1 ;
	this->d = this->d + 1 ;

	return temp ;
}

Mat2x2 Mat2x2::operator++()
{
	this->a = this->a + 1;
	this->b = this->b + 1;
	this->c = this->c + 1;
	this->d = this->d + 1;

	return *this ;
}

Mat2x2 Mat2x2::operator--(int)
{
	Mat2x2 temp = *this;

	this->a = this->a - 1;
	this->b = this->b - 1;
	this->c = this->c - 1;
	this->d = this->d - 1;

	return temp;
}

Mat2x2 Mat2x2::operator--()
{
	this->a = this->a - 1;
	this->b = this->b - 1;
	this->c = this->c - 1;
	this->d = this->d - 1;

	return *this;
}

Mat2x2 Mat2x2::operator+()
{
	return *this ;
}

Mat2x2 Mat2x2::operator-()
{
	Mat2x2 neg;

	neg.a = this->a * (- 1) ;
	neg.b = this->b * (- 1) ;
	neg.c = this->c * (- 1) ;
	neg.d = this->d * (- 1) ;

	return neg;
}

Mat2x2 Mat2x2::operator^(int k)
{
	Mat2x2 pow = *this ;
	Mat2x2 temp = *this ;

	if (k > 0)
		for (int i = 0; i < k - 1; i++)
			pow *= temp ;

	else if (k < 0)
	{
		k = k * (-1);
		pow = pow.inverse();
		pow *= k;
	}

	return pow ;
}

double& Mat2x2::operator[](int index)
{
	if (index >= 0 && index <= 3)
	{
		if (index == 0)
			return a ;
		else if (index == 1)
			return b;		
		else if (index == 2)
			return c;		
		else if (index == 3)
			return d;
	}
	else
	{
		throw invalid_argument("index out of bounds");
	}
}

const double& Mat2x2::operator[](int index) const 
{
	if (index >= 0 && index <= 3)
	{
		if (index == 0)
			return a;
		else if (index == 1)
			return b;
		else if (index == 2)
			return c;
		else if (index == 3)
			return d;
	}
	else
	{
		throw invalid_argument("index out of bounds");
	}
}

Mat2x2::operator bool() const
{
	double det = a * d - b * c;
	if (det > tolerance)
		return true;

	return false ;
}

double Mat2x2::operator()() const
{
	double norm = a * a + b * b + c * c + d * d;
	norm = sqrt(norm);
	return norm;
}

double& Mat2x2::operator()(size_t r, size_t c)
{
	if (r == 1 && c == 1)
		return this->a;
	else if (r == 1 && c == 2)
		return this->b;
	else if (r == 2 && c == 1)
		return this->c;	
	else if (r == 2 && c == 2)
		return this->d;	

	if (r < 1 || r > 2) 
		throw invalid_argument("row index out of bounds");

	if (c < 1 || c > 2) 
		throw invalid_argument("column index out of bounds");
}



