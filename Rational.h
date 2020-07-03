#include <iostream>
using namespace std;
class Rational
{
private:
	int num;
	int den;
	void simplification();
public:
	//Getters/Setters
	int getNum() const;
	void setNum(int);
	int getDen() const;
	void setDen(int);
	Rational setRat(int, int);
	Rational& stoR(string s);

	//Constructors
	Rational();
	Rational(int p);
	Rational(int p, int q);
	Rational(const Rational&);

	//Arithmetic Operators Overloading
	Rational operator+(const Rational&) const;
	Rational operator+(int) const;
	friend Rational operator+(int, const Rational&);
	Rational operator+(double) const;
	friend Rational operator+(double, const Rational&);
	Rational operator-(const Rational&) const;
	Rational operator-(int) const;
	friend Rational operator-(int, const Rational&);
	Rational operator-(double) const;
	friend Rational operator-(double, const Rational&);
	Rational operator*(const Rational&) const;
	Rational operator*(int) const;
	friend Rational operator*(int, const Rational&);
	Rational operator*(double) const;
	friend Rational operator*(double, const Rational&);
	Rational operator/(const Rational&) const;
	Rational operator/(int) const;
	friend Rational operator/ (int, const Rational&);
	Rational operator/(double) const;
	friend Rational operator/(double, const Rational&);

	//Assignment Operators Overloading
	Rational& operator=(const Rational&);
	Rational& operator=(int);
	Rational& operator=(double);
	Rational& operator+=(const Rational&);
	Rational& operator+=(int);
	Rational& operator+=(double);
	Rational& operator-=(const Rational&);
	Rational& operator-=(int);
	Rational& operator-=(double);
	Rational& operator*=(const Rational&);
	Rational& operator*=(int);
	Rational& operator*=(double);
	Rational& operator/=(const Rational&);
	Rational& operator/=(int);
	Rational& operator/=(double);

	//IO Operators Overloading
	friend ostream& operator<<(ostream&, const Rational&);
	friend istream& operator>>(istream&, Rational&);

	//Increment Operators & Unary Minus Operator Overloading
	Rational& operator++();
	Rational& operator--();
	Rational& operator-();

	//Comparison Operators Overloading
	bool operator==(const Rational&) const;
	bool operator==(int) const;
	friend bool operator==(int, const Rational&);
	bool operator==(double) const;
	friend bool operator==(double, const Rational&);
	bool operator!=(const Rational&) const;
	bool operator!=(int) const;
	friend bool operator!=(int, const Rational&);
	bool operator!=(double) const;
	friend bool operator!=(double, const Rational&);
	bool operator>(const Rational&) const;
	bool operator>(int) const;
	friend bool operator>(int, const Rational&);
	bool operator>(double) const;
	friend bool operator>(double, const Rational&);
	bool operator<(const Rational&) const;
	bool operator<(int) const;
	friend bool operator<(int, const Rational&);
	bool operator<(double) const;
	friend bool operator<(double, const Rational&);
	bool operator>=(const Rational&) const;
	bool operator>=(int) const;
	friend bool operator>= (int, const Rational&);
	bool operator>=(double) const;
	friend bool operator>=(double, const Rational&);
	bool operator<=(const Rational&) const; 
	bool operator<=(int) const;
	friend bool operator<=(int, const Rational&);
	bool operator<=(double) const;
	friend bool operator<=(double, const Rational&);

	//Other Functions
	operator double();
	Rational double2Rat(double);
	Rational reciprocal() const;
	Rational power(int) const;
	string stringify() const;
};