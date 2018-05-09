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
double intersect(double poly1[], int degree1,double poly2[], int degree2 );
double * readPolynomial(int &degree);

int main(){
	int degree1;
	double *poly1 = readPolynomial(degree1);
	print (poly1, degree1);
	
	int degree2;
	double *poly2 = readPolynomial(degree2);
	print (poly2, degree2);
	
	double lowestx = intersect( poly1, degree1, poly2, degree2 );
	
	if (lowestx == 0.0){
		cout<<"There is no intersect"<<endl;
	}
	else{
		cout <<"There is an intersect: "<< lowestx << endl;
	}
	
	delete[]poly1;
	poly1 = NULL;
	delete[]poly2;
	poly2 = NULL;
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
	

double intersect(double poly1[], int degree1,double poly2[], int degree2){
	double result1 = 0.0;
	double result2 = 0.0;
	double x = 1;
	if (degree1 < degree2 && poly1[0] > poly2[0] ){ 
		while (result2>result1){				
			result1 = eval(poly1, degree1, x);
			result2 = eval(poly2, degree2, x);
				x += .1;
				cout<<x;
		}
	}
	if (degree1 > degree2 && poly1[0] < poly2[0] ){ 
		while (result2>result1){				
			result1 = eval(poly1, degree1, x);
			result2 = eval(poly2, degree2, x);
				x += .1;
				cout<<x;
		}
	}
	if (degree1 = degree2 && poly1[0] > poly2[0] ){ 
		while (result2>result1){				
			result1 = eval(poly1, degree1, x);
			result2 = eval(poly2, degree2, x);
				x += .1;
				cout<<x;
		}
	}
return x;
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


