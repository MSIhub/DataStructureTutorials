#include "PolynomialRepresentation.h"

void polyTest()
{
	Polynomial p1(3);
	Polynomial p2(3);

	std::cin >> p1;
	std::cin >> p2;

	Polynomial p3 = p1 + p2;
	std::cout << "First Polynomial:\t";
	std::cout << p1;
	std::cout << "\nSecond Polynomial:\t";
	std::cout << p2;
	std::cout << "\nSum Polynomial:\t";
	std::cout << p3;
}


Polynomial Polynomial::operator+(Polynomial& p)
{
	Polynomial* sum = new Polynomial(n+p.n);
	
	int i = 0, j = 0, k = 0; 
	while (i< n && j< p.n)
	{
		if (t[i].exp > p.t[j].exp)
			sum->t[k++] = p.t[j++];
		else if (t[i].exp < p.t[j].exp)
			sum->t[k++] = t[i++]; 
		else
		{
			sum->t[k].exp = t[i].exp;
			sum->t[k++].coeff = t[i++].coeff + p.t[j++].coeff;
		}
	}

	for (; i < n; i++)
		sum->t[k++] = t[i];
	for (; j < p.n; j++)
		sum->t[k++] = p.t[j];

	sum->n = k;
	return *sum;
}

std::istream& operator >> (std::istream& is, Polynomial& p)
{
	std::cout << "Enter terms [coeff, exp]:\n";
	for (int i = 0; i < p.n; i++)
		std::cin >> p.t[i].coeff >> p.t[i].exp;

	return is;
}

std::ostream& operator << (std::ostream& os, Polynomial& p)
{
	for (int i = 0; i < p.n; i++)
		std::cout << p.t[i].coeff << "x" << p.t[i].exp << " + ";
	
	return os;
}