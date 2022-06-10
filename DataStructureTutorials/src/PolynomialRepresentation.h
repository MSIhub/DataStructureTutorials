#pragma once
#include <iostream>

class Term
{
public:
	int coeff;
	int exp;
};


class Polynomial
{
private:
	int n;
	Term* t;
public:
	Polynomial(int n)
	{
		this->n = n;
		t = new Term[n];
	}
	~Polynomial() { delete[] t; }

	Polynomial operator+(Polynomial& p);

	//Operator overloading 
	friend std::istream& operator >> (std::istream& is, Polynomial& s);
	friend std::ostream& operator << (std::ostream& os, Polynomial& s);

};

void polyTest();

