//
// Created by Alex on 4/21/2021.
//

#include "RationalNumber.h"
#include <bits/stdc++.h>
using namespace std;

//constructors

RationalNumber::RationalNumber(){
    m_number = 0.0;
}

RationalNumber::RationalNumber(const double mNumber){
    m_number = mNumber;
}

RationalNumber::RationalNumber(const RationalNumber &other){
    m_number = other.m_number;
}

//destructors

RationalNumber::~RationalNumber(){}

//operators

//=
RationalNumber &RationalNumber::operator=(const RationalNumber &other){
    m_number = other.m_number;
    return *this;
}

//cout
ostream &operator<<(ostream &out, const RationalNumber &rationalNumber){
    out << rationalNumber.m_number;
    return out;
}

//+= , -= , *= , /=
void RationalNumber::operator+=(const RationalNumber &other){
    m_number += other.m_number;
}
void RationalNumber::operator-=(const RationalNumber &other){
    m_number -= other.m_number;
}
void RationalNumber::operator*=(const RationalNumber &other){
    m_number *= other.m_number;
}
void RationalNumber::operator/=(const RationalNumber &other){
    m_number /= other.m_number;
}

//getters

double RationalNumber::getMNumber() const{
    return m_number;
}

//setters

void RationalNumber::setMNumber(const double mNumber){
    m_number = mNumber;
}

//special