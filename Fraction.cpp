#include<iostream>
#include<cstdlib>
#include<stdexcept>
#include "Fraction.h"

using namespace std;

int findGCD(int a,int b){
	if(a==0)
		return b;
	if(b==0)
		return a;
	return findGCD(b%a,a);
}

Fraction::Fraction(){
	this->numerator=0;
	this->denominator=1;
}

Fraction::Fraction(int num, int den=1){
	this->numerator = num;
	this->denominator = den;
	this->checkSign();
}

Fraction::Fraction(Fraction &f2){
	this->numerator = f2.numerator;
	this->denominator = f2.denominator;
}

int Fraction::getNum(){ return this->numerator; }
int Fraction::getDen(){ return this->denominator; }
void Fraction::setNum(int n){ this->numerator = n;}
void Fraction::setDen(int d){ this->denominator = d; }

void Fraction::print(){
	cout<<this->getNum();
	if(this->getDen() != 1)
		cout<<"/"<<this->getDen()<<endl;
	else
		cout<<endl;
}

bool Fraction::isValid(){
	if(this->denominator == 0)
		return false;
	return true;
}

void Fraction::checkSign(){
	if(this->numerator < 0 && this->denominator < 0){
		this->numerator = abs(this->numerator);
		this->denominator = abs(this->denominator);
	}
}

void Fraction::reduceFraction(){
	if(this->numerator == 0)
		this->denominator = 1;
	else{
		int num = this->numerator;
		int den = this->denominator;
		int GCDF = 0;
		do{
			GCDF = findGCD(num,den);
			num /= GCDF;
			den /= GCDF;
		}while(GCDF != 1);
		this->numerator = num;
		this->denominator = den;
		this->checkSign();
	}
}

double Fraction::convertToDouble(){
	try{
		if(this->isValid())
			return double(this->numerator) / double(this->denominator);
		else
			throw runtime_error("DivideByZero: Denominator cannot be zero");
	}
	catch(runtime_error &e){
		cout<<"Program Execution stopped"<<endl<<e.what()<<endl;
	}
	double inf = 1/0;
	return inf;
}

int Fraction::convertToInt(){
	try{
		if(this->isValid())
			return this->numerator/this->denominator;
			else
				throw runtime_error("DivideByZero: Denominator cannot be zero");
	}
	catch(runtime_error &e){
		cout<<"Program Execution stopped"<<endl<<e.what()<<endl;
	}

	int inf = 1/0;
	return inf;
}


Fraction Fraction::operator + (Fraction &op2){
	Fraction result;
	result.numerator = numerator + op2.getNum();
	result.denominator = denominator + op2.getDen();
	result.reduceFraction();
	return result;
}

Fraction Fraction::operator - (Fraction &op2){
	Fraction result;
	result.numerator = this->numerator - op2.getNum();
	result.denominator = this->denominator - op2.getDen();
	result.reduceFraction();
	return result;
}

Fraction Fraction::operator * (Fraction &op2){
	Fraction result;
	result.numerator = this->numerator * op2.getNum();
	result.denominator = this->denominator * op2.getDen();
	result.reduceFraction();
	return result;
}

Fraction Fraction::operator / (Fraction &op2){
	Fraction result;
	result.numerator = this->numerator * op2.getDen();
	result.denominator = this->denominator * op2.getNum();
	result.reduceFraction();
	return result;
}

void Fraction::operator += (Fraction &op2){
	this->numerator += op2.getNum();
	this->denominator += op2.getDen();
	this->reduceFraction();
}

void Fraction::operator -= (Fraction &op2){
	this->numerator -= op2.getNum();
	this->denominator -= op2.getDen();
	this->reduceFraction();
}

void Fraction::operator *= (Fraction &op2){
	this->numerator *= op2.getNum();
	this->denominator *= op2.getDen();
	this->reduceFraction();
}

void Fraction::operator /= (Fraction &op2){
	this->numerator *= op2.getDen();
	this->denominator *= op2.getNum();
	this->reduceFraction();
}


bool Fraction::operator == (Fraction &op2){
	double tmp1 = double(this->numerator)/double(this->denominator);
	double tmp2 = double(op2.getNum())/double(op2.getDen());

	if(tmp1 == tmp2)
		return true;
	return false;
}

bool Fraction::operator != (Fraction &op2){
	double tmp1 = double(this->numerator)/double(this->denominator);
	double tmp2 = double(op2.getNum())/double(op2.getDen());

	if(tmp1 != tmp2)
		return true;
	return false;
}


bool Fraction::operator <= (Fraction &op2){
	double tmp1 = double(this->numerator)/double(this->denominator);
	double tmp2 = double(op2.getNum())/double(op2.getDen());

	if(tmp1 <= tmp2)
		return true;
	return false;
}

bool Fraction::operator < (Fraction &op2){
	double tmp1 = double(this->numerator)/double(this->denominator);
	double tmp2 = double(op2.getNum())/double(op2.getDen());

	if(tmp1 < tmp2)
		return true;
	return false;
}

bool Fraction::operator >= (Fraction &op2){
	double tmp1 = double(this->numerator)/double(this->denominator);
	double tmp2 = double(op2.getNum())/double(op2.getDen());

	if(tmp1 >= tmp2)
		return true;
	return false;
}

bool Fraction::operator > (Fraction &op2){
	double tmp1 = double(this->numerator)/double(this->denominator);
	double tmp2 = double(op2.getNum())/double(op2.getDen());

	if(tmp1 > tmp2)
		return true;
	return false;
}

ostream& operator << (ostream &cout_obj, Fraction &f){
	int num = f.getNum(), den = f.getDen();

	if(num < 0 || den < 0){
		cout_obj<<"-";
		num = abs(num);
		den = abs(den);
	}

	if(den != 1)
		cout_obj<<"("<<num<<"/"<<den<<")";
	else
		cout_obj<<num;

	return cout_obj;
}

void inputFraction(Fraction &F){
	int num,den;
	cout<<"Enter Numerator and Denominator (Only Integer Values accepted)"<<endl;
	cin>>num>>den;
	F.setNum(num);
	F.setDen(den);
}
