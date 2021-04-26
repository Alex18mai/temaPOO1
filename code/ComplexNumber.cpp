//
// Created by Alex on 4/21/2021.
//

#include "ComplexNumber.h"
#include <bits/stdc++.h>
using namespace std;


//constructors

ComplexNumber::ComplexNumber(){
    m_real = 0.0;
    m_imaginary = 0.0;
}

ComplexNumber::ComplexNumber(const double mReal, const double mImaginary){
    m_real = mReal;
    m_imaginary = mImaginary;
}

ComplexNumber::ComplexNumber(const ComplexNumber &other){
    m_real = other.m_real;
    m_imaginary = other.m_imaginary;
}

//destructors

ComplexNumber::~ComplexNumber(){}

//operators

//=
ComplexNumber &ComplexNumber::operator=(const ComplexNumber &other){
    m_real = other.m_real;
    m_imaginary = other.m_imaginary;
    return *this;
}

//cout
ostream &operator<<(ostream &out, const ComplexNumber &complexNumber){
    out << complexNumber.m_real << " + " << complexNumber.m_imaginary << "i";
    return out;
}

//+= , -= , *= , /=
void ComplexNumber::operator+=(const ComplexNumber &other){
    m_real += other.m_real;
    m_imaginary += other.m_imaginary;
}
void ComplexNumber::operator-=(const ComplexNumber &other){
    m_real -= other.m_real;
    m_imaginary -= other.m_imaginary;
}
void ComplexNumber::operator*=(const ComplexNumber &other){
    double real = m_real * other.m_real - m_imaginary * other.m_imaginary; //ac - bd
    double imaginary = m_real * other.m_imaginary + m_imaginary * other.m_real; //ad + bc
    m_real = real;
    m_imaginary = imaginary;
}
void ComplexNumber::operator/=(const ComplexNumber &other){
    double denominator = other.m_real * other.m_real + other.m_imaginary * other.m_imaginary; //c^2 + d^2
    double real = (m_real * other.m_real + m_imaginary * other.m_imaginary) / denominator; //(ac + bd) / (c^2 + d^2)
    double imaginary = (m_imaginary * other.m_real - m_real * other.m_imaginary) / denominator; //(bc - ad) / (c^2 + d^2)
    m_real = real;
    m_imaginary = imaginary;
}

//getters

double ComplexNumber::getMReal() const{
    return m_real;
}
double ComplexNumber::getMImaginary() const {
    return m_imaginary;
}

//setters

void ComplexNumber::setMReal(const double mReal){
    m_real = mReal;
}
void ComplexNumber::setMImaginary(const double mImaginary){
    m_imaginary = mImaginary;
}

//special

double ComplexNumber::getAbsoluteValue() const {
    return sqrt(m_real * m_real + m_imaginary * m_imaginary);
}