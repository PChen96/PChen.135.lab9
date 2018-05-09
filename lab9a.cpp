/*
Author: Phillip Chen
Course: 136
Instructor: Alex Nikolaev
Assignment: Lab9a

This program will store an polynomial and computes its value.
First it will ask the highest degree in your polynomial ( x^degree ).
Second it will ask you to input constants next to each coefficent degree 
( Each "Number" in "Number x^degree" )  
Third it will ask you the value of the coefficent ( vaule of x )
Forth it will compute the vaule of the entire polynomial
*/
#include <iostream>
#include <cmath>
using namespace std;

void print(double poly[], int degree);
double eval(double poly[], int degree, double x);
double * readPolynomial(int &degree);

int main(){
	int degree;
	double *poly = readPolynomial(degree);
	print (poly, degree);
	
	int x;
	cout << "Input x: ";
	cin >> x;
	double result =	eval( poly, degree, x);
	cout << result << endl;
	delete[]poly;
	poly = NULL;
}

double * readPolynomial(int &degree){
	cout << "Enter the degree: ";
	cin >> degree;	
	double* d = new double[degree+1];
	for (int i = degree ; i>=0  ;i--){
		cout<<"Enter the coefficient at x^"<<i<<": ";
		cin>>d[i];
	}
	return d;
}
	

double eval(double poly[], int degree, double x){
	double result = 0.0;
	for (int i = degree ; i>=0  ;i--){
		result += poly[i]*pow(x,i);
		}
	return result;
} 

void print(double poly[], int degree){
	bool something_printed = false;
	for (int i = degree ; i>=0  ;i--){
		if (poly [i] != 0){
			if (something_printed == true){
				cout<<" + ";
				}
			if (i !=1 && i !=0){
				cout << poly[i] <<" x^"<<i;
				something_printed = true;
				}
			if (i == 1){
				cout << poly[i] <<" x ";
			}
			if (i == 0){cout << poly[i];}	
		}
		if (i == 0){
			cout << endl;
		}
	}
}


