#include<iostream>
#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction{
	private:
		int numerator;
		int denominator;

	public:

		//Constructors
		Fraction();
		Fraction(int, int);
		Fraction(Fraction&);

		//friend functions for accessing private members
		friend int findGCD(int a, int b);
		friend std::ostream& operator <<(std::ostream& , Fraction&);
		friend void inputFraction(Fraction&);

		//get/set functions to access private members out of scope
		int getNum();
		int getDen();
		void setNum(int num);
		void setDen(int den);

		//Support Functions
		void print(); // Display the fraction in a format (cout can also Can be used)
		bool isValid(); // Check if Fraction is valid (if Denominator zero)
		void checkSign(); //changes the sign of numbers if both num and den are negative
		void reduceFraction(); //reduces the fraction to its simplest form

		//Conversion functions
		double convertToDouble();
		int convertToInt();

		//Operator overloaded functions

		//Basic Operations
		Fraction operator + (Fraction&);
		Fraction operator - (Fraction &);
		Fraction operator * (Fraction&);
		Fraction operator / (Fraction&);

		//Basic Assignment Math Operations
		void operator += (Fraction &);
		void operator -= (Fraction&);
		void operator *= (Fraction&);
		void operator /= (Fraction&);

		//Comparison Operations
		//Equality/ NonEquality
		bool operator == (Fraction&);
		bool operator != (Fraction&);

		//less than or equal to
		bool operator <= (Fraction&);
		bool operator < (Fraction&);

		//greater than or equal to
		bool operator >= (Fraction&);
		bool operator > (Fraction&);
};

#endif /* FRACTION_H_ */
