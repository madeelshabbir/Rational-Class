#include <iostream>
#include<sstream>
#include "Rational.h"
using namespace std;

int GCD(int n1, int n2)
{
	if(n2 > n1)
	{
		int k = n1;
		n1 = n2;
		n2 = k;
	}
	int r = 1;
	while(r != 0)
	{
		r = n1 % n2;
		n1 = n2;
		n2 = r;
	}
	return n1;
}

void Rational::simplification()
{
    int g = GCD(num, den);
    num /= g;
    den /= g;
	if (den < 0)
	{
		num *= -1;
		den *= -1;
	}
}

Rational& Rational::stoR(string s)
{
	stringstream ss;
	char c;
	c = 'a';
	ss << s;
	bool fm = 0, fb = 0, ft = 0;
	for (int i = 0; i < strlen(s.c_str()); i++)
	{
		ss.get(c);
		if (c >= '0' && c <= '9')
			fm = 1;
		else if ((c == '-' || c == '+') && fm == 0)
			fm = 1;
		else if (c == '/' && fb == 0)
			fb = 1;
		else
			throw 0;
		if (fb == 1 && ft == 0)
		{
			ft = 1;
			fm = 0;
		}
	}
	ss << s;
	ss >> num;
	ss.ignore(1);
	ss >> den;
	return *this;
}

int Rational::getNum() const
{
	return num;
}

void Rational::setNum(int p)
{
	num = p;
}

int Rational::getDen() const
{
	return den;
}

void Rational::setDen(int q)
{
	if (q == 0)
	{
		throw 0;
	}
	den = q;
}

Rational Rational::setRat(int p, int q)
{
	if (q == 0)
	{
		throw 0;
	}
	num = p;
	den = q;
}

Rational::Rational() : num(0), den(1)
{}

Rational::Rational(int p) : num(p), den(0)
{}

Rational::Rational(int p, int q) : num(p), den(q)
{
	if(q == 0)
	{
		throw 0;
	}
}

Rational::Rational(const Rational &rhs)
{
	num = rhs.num;
	den = rhs.den;
}

Rational Rational::operator+(const Rational &r) const
{
	Rational temp;
	temp.num = (r.den*num) + (den*r.num);
	temp.den = den * r.den;
	temp.simplification();
	return temp;
}

Rational Rational::operator+(int n) const
{
	Rational temp;
	temp.num = (num)+(den*n);
	temp.den = den;
	temp.simplification();
	return temp;
}

Rational operator+(int n, const Rational &r)
{
	Rational temp;
	temp.num = (r.den*n) + (r.num);
	temp.den = r.den;
	temp.simplification();
	return temp;
}

Rational Rational::operator+(double n) const
{
	Rational temp, r;
	r.double2Rat(n);
	temp.num = (r.den*num) + (den*r.num);
	temp.den = den * r.den;
	temp.simplification();
	return temp;
}

Rational operator+(double n, const Rational& r)
{
	Rational temp, r1;
	r1.double2Rat(n);
	temp.num = (r.den*r1.num) + (r1.den*r.num);
	temp.den = r.den * r.den;
	temp.simplification();
	return temp;
}

Rational Rational::operator-(const Rational &r) const
{
	Rational temp;
	if (*this != r)
	{
		temp.num = (r.den*num) - (den*r.num);
		temp.den = den * r.den;
		temp.simplification();
	}
	return temp;
}

Rational Rational::operator-(int n) const
{
	Rational temp;
	if (this->num != n)
	{
		temp.num = (num)-(den*n);
		temp.den = den;
		temp.simplification();
	}
	return temp;
}

Rational operator-(int n, const Rational &r)
{
	Rational temp;
	if (n != r.num)
	{
		temp.num = (r.den*n) - (r.num);
		temp.den = r.den;
		temp.simplification();
	}
	return temp;
}

Rational Rational::operator-(double n) const
{
	Rational temp, r;
	r.double2Rat(n);
	if (*this != r)
	{
		temp.num = (r.den*num) - (den*r.num);
		temp.den = den * r.den;
		temp.simplification();
	}
	return temp;
}

Rational operator-(double n, const Rational &r)
{
	Rational temp, r1;
	r1.double2Rat(n);
	if (r != r1)
	{
		temp.num = (r.den*r1.num) - (r1.den*r.num);
		temp.den = r1.den * r.den;
		temp.simplification();
	}
	return temp;
}

Rational Rational::operator*(const Rational &r) const
{
	Rational temp;
	temp.num = num * r.num;
	temp.den = den * r.den;
	if (temp.num != 0)
	{
		temp.simplification();
	}
	return temp;
}

Rational Rational::operator*(int n) const
{
	Rational temp;
	temp.num = num * n;
	temp.den = den;
	if (temp.num != 0)
	{
		temp.simplification();
	}
	return temp;
}

Rational operator*(int n, const Rational &r)
{
	Rational temp;
	temp.num = n * r.num;
	temp.den = r.den;
	if (temp.num != 0)
	{
		temp.simplification();
	}
	return temp;
}

Rational Rational::operator*(double n) const
{
	Rational temp, r;
	r.double2Rat(n);
	temp.num = num * r.num;
	temp.den = den * r.den;
	if (temp.num != 0)
	{
		temp.simplification();
	}
	return temp;
}
Rational operator*(double n, const Rational &r)
{
	Rational temp, r1;
	r1.double2Rat(n);
	temp.num = r1.num * r.num;
	temp.den = r1.den * r.den;
	if (temp.num != 0)
	{
		temp.simplification();
	}
	return temp;
}

Rational Rational::operator/(const Rational &r) const
{
	if (r.num == 0)
	{
		throw 0;
	}
	Rational temp;
	temp.num = num * r.den;
	temp.den = den * r.num;
	temp.simplification();
	return temp;
}

Rational Rational::operator/(int n) const
{
	if (n == 0)
	{
		throw 0;
	}
	Rational temp;
	temp.num = num;
	temp.den = den * n;
	temp.simplification();
	return temp;
}

Rational operator/(int n, const Rational &r)
{
	if (r.num == 0)
	{
		throw 0;
	}
	Rational temp;
	temp.num = n * r.den;
	temp.den = r.num;
	if (temp.num != 0)
	{
		temp.simplification();
	}
	return temp;
}

Rational Rational::operator/(double n) const
{
	Rational r;
	r.double2Rat(n);
	if (r.num == 0)
	{
		throw 0;
	}
	Rational temp;
	temp.num = num * r.den;
	temp.den = den * r.num;
	temp.simplification();
	return temp;
}

Rational operator/(double n, const Rational &r)
{
	Rational r1;
	r1.double2Rat(n);
	if (r.num == 0)
	{
		throw 0;
	}
	Rational temp;
	temp.num = r1.num * r.den;
	temp.den = r1.den * r.num;
	temp.simplification();
	return temp;
}

Rational& Rational::operator=(const Rational &rhs)
{
	if(this != &rhs)
	{
		num = rhs.num;
		den = rhs.den;
	}
	return *this;
}

Rational& Rational::operator=(int n)
{
	if (num != n && den != 1)
	{
		num = n;
		den = 1;
	}
	return *this;
}

Rational& Rational::operator=(double n)
{
	Rational r;
	r.double2Rat(n);
	if (this != &r)
	{
		num = r.num;
		den = r.den;
	}
	return *this;
}

Rational& Rational::operator+=(const Rational &r)
{
	num = (r.den*num) + (den*r.num);
	den *= r.den;
	this->simplification();
	return *this;
}

Rational& Rational::operator+=(int n)
{
	num = (num) + (den*n);
	this->simplification();
	return *this;
}

Rational& Rational::operator+=(double n)
{
	Rational r;
	r.double2Rat(n);
	num = (r.den*num) + (den*r.num);
	den *= r.den;
	this->simplification();
	return *this;
}

Rational& Rational::operator-=(const Rational &r)
{
	if (*this != r)
	{
		num = (r.den*num) - (den*r.num);
		den *= r.den;
		this->simplification();
	}
	else
	{
		num = 0;
		den = 1;
	}
	return *this;
}

Rational& Rational::operator-=(int n)
{
	if (num != n && den != 1)
	{
		num = (num) - (den*n);
		this->simplification();
	}
	else
	{
		num = 0;
		den = 1;
	}
	return *this;
}

Rational& Rational::operator-=(double n)
{
	Rational r;
	r.double2Rat(n);
	if (*this != r)
	{
		num = (r.den*num) - (den*r.num);
		den *= r.den;
		this->simplification();
	}
	else
	{
		num = 0;
		den = 1;
	}
	return *this;
}

Rational& Rational::operator*=(const Rational &r)
{
	num *= r.num;
	den *= r.den;
	if (num != 0)
	{
		this->simplification();
	}
	return *this;
}

Rational& Rational::operator*=(int n)
{
	num *= n;
	if (num != 0)
	{
		this->simplification();
	}
	return *this;
}

Rational& Rational::operator*=(double n)
{
	Rational r;
	r.double2Rat(n);
	num *= r.num;
	den *= r.den;
	if (num != 0)
	{
		this->simplification();
	}
	return *this;
}

Rational& Rational::operator/=(const Rational &r)
{
	if(r.num == 0)
	{
		throw 0;
	}
	num *= r.den;
	den *= r.num;
	return *this;
}

Rational& Rational::operator/=(int n)
{
	if (n == 0)
	{
		throw 0;
	}
	den *= n;
	return *this;
}

Rational& Rational::operator/=(double n)
{
	Rational r;
	r.double2Rat(n);
	if (r.num == 0)
	{
		throw 0;
	}
	num *= r.den;
	den *= r.num;
	return *this;
}

ostream& operator<<(ostream &s, const Rational &r)
{
	s << r.num << "/" << r.den;
	return s;
}

istream& operator>>(istream &s, Rational &r)
{
	string st;
	s >> st;
	r.stoR(st);
	if (r.den == 0)
	{
		throw 0;
	}
	if (r.num != 0)
	{
		r.simplification();
	}
	return s;
}

Rational& Rational::operator++()
{
	num = (num) + (den*1);
	this->simplification();
	return *this;
}

Rational& Rational::operator--()
{
	if (num != den)
	{
		num = num - (den*1);
		this->simplification();
	}
	else
	{
		num = 0;
		den = 1;
	}
	return *this;
}

Rational& Rational::operator-()
{
	this->num = (-1)*this->num;
	return *this;
}

bool Rational::operator==(const Rational &r) const
{
	if (double(num) / den == double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator==(int n) const
{
	if (double(num) / den == double(n))
	{
		return true;
	}
	return false;
}

bool operator==(int n, const Rational &r)
{
	if (double(r.num)  / r.den == double(n))
	{
		return true;
	}
	return false;
}

bool Rational::operator==(double n) const
{
	if (double(num) / den == n)
	{
		return true;
	}
	return false;
}

bool operator==(double n, const Rational &r)
{
	if (n == double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator!=(const Rational &r) const
{
	if (double(num) / den == double(r.num) / r.den)
	{
		return false;
	}
	return true;
}

bool Rational::operator!=(int n) const
{
	if (double(num) / den == double(n))
	{
		return false;
	}
	return true;
}

bool operator!=(int n, const Rational &r)
{
	if (double(r.num) / r.den == double(n))
	{
		return false;
	}
	return true;
}

bool Rational::operator!=(double n) const
{
	if (double(num) / den == n)
	{
		return false;
	}
	return true;
}

bool operator!=(double n, const Rational &r)
{
	if (n == double(r.num) / r.den)
	{
		return false;
	}
	return true;
}

bool Rational::operator>(const Rational &r) const
{
	if (double(num)/den > double(r.num)/r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator>(int n) const
{
	if (double(num) / den > double(n))
	{
		return true;
	}
	return false;
}

bool operator>(int n, const Rational &r)
{
	if (double(n) > double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator>(double n) const
{
	if (double(num) / den > double(n))
	{
		return true;
	}
	return false;
}

bool operator>(double n, const Rational &r)
{
	if (n > double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator<(const Rational &r) const
{
	if (double(num) / den < double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator<(int n) const
{
	if (double(num) / den < double(n))
	{
		return true;
	}
	return false;
}

bool operator<(int n, const Rational &r)
{
	if (double(n) < double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator<(double n) const
{
	if (double(num) / den < n)
	{
		return true;
	}
	return false;
}

bool operator<(double n, const Rational &r)
{
	if (n < double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator>=(const Rational &r) const
{
	if (double(num) / den >= double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator>=(int n) const
{
	if (double(num) / den >= double(n))
	{
		return true;
	}
	return false;
}

bool operator>=(int n, const Rational &r)
{
	if (double(n) >= double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator>=(double n) const
{
	if (double(num) / den >= n)
	{
		return true;
	}
	return false;
}

bool operator>=(double n, const Rational &r)
{
	if (n >= double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator<=(const Rational &r) const
{
	if (double(num) / den <= double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator<=(int n) const
{
	if (double(num) / den <= double(n))
	{
		return true;
	}
	return false;
}

bool operator<=(int n, const Rational &r)
{
	if (double(n) <= double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

bool Rational::operator<=(double n) const
{
	if (double(num) / den <= n)
	{
		return true;
	}
	return false;
}

bool operator<=(double n, const Rational &r)
{
	if (n <= double(r.num) / r.den)
	{
		return true;
	}
	return false;
}

Rational::operator double()
{
	return num/double(den);
}

Rational Rational::double2Rat(double d)
{
	int temp = 1;
	while (int(temp*d) != double(temp)*d)
	{
		temp *= 10;
	}
	int g = GCD(temp*d, temp);
	num = (int)temp*d / g;
	den = temp / g;
	return *this;
}

Rational Rational::reciprocal() const
{
	if(num == 0)
	{
		throw 0;
	}
	Rational temp;
	temp.num = den;
	temp.den = num;
	return temp;
}

Rational Rational::power(int p) const
{
	Rational temp = *this;
	if (p == 0)
	{
		temp.num = 1;
		temp.den = 1;
	}
	for(int i = 1; i < p; i++)
	{
		temp *= *this;
	}
	return temp;
}

string Rational::stringify() const
{
	stringstream ss;
	ss << num << "/" << den;
	return ss.str();
}