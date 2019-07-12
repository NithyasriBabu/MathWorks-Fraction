#include<iostream>
#include "Fraction.h"
using namespace std;

int main(){

	Fraction F1,F2;
	inputFraction(F1);
	inputFraction(F2);

	Fraction F;
	F = F1+F2;
	cout<<F1<< "+" << F2 << "=" << F<<endl;

	F = F1-F2;
	cout<<F1<<"-"<<F2<<"="<<F<<endl;

	F = F1*F2;
	cout<<F1<<"*"<<F2<<"="<<F<<endl;

	F = F1/F2;
	cout<<F1<<"/"<<F2<<"="<<F<<endl;

	Fraction F3(F1);
	F3 += F2;

	Fraction F4(F1);
	F4 -= F2;

	Fraction F5(F1);
	F5 *= F2;

	Fraction F6(F1);
	F6 /= F2;

	cout<<"Below Cross checking answers for +=, -=, *=, /= (All Must be true)"<<endl;
	cout<<(((F1+F2)==F3)?"True":"False")<<endl;
	cout<<(((F1-F2)==F4)?"True":"False")<<endl;
	cout<<(((F1*F2)==F5)?"True":"False")<<endl;
	cout<<(((F1/F2)==F6)?"True":"False")<<endl;

	cout<<endl<<"All comparisons below are for Fraction 1 <operator> Fraction 2"<<endl;
	cout<<"Not Equal??"<<endl;
	cout<<((F1 != F2)?"True":"False")<<endl;

	cout<<"Greater than or equal to??"<<endl;
	cout<<((F1 >= F2)?"True":"False")<<endl;

	cout<<"Greater Than??"<<endl;
	cout<<((F1 > F2)?"True":"False")<<endl;

	cout<<"Less than or equal to??"<<endl;
	cout<<((F1 <= F2)?"True":"False")<<endl;

	cout<<"Less than??"<<endl;
	cout<<((F1 < F2)?"True":"False")<<endl;

	cout<<"Converting Fractions to Double and Int, Will Through exception if denominator is zero"<<endl;
	cout<<F1<<" as Double = "<<F1.convertToDouble()<<endl;
	cout<<F2<<" as Integer (rounded up) = "<<F2.convertToInt()<<endl;

	return 0;
}
