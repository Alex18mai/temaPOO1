//
// Created by Alex on 4/21/2021.
//

#include "RealNumber.h"
#include <bits/stdc++.h>
using namespace std;


//constructors

RealNumber::RealNumber(){
    m_number = 0.0;
}

RealNumber::RealNumber(const double mNumber){
    m_number = mNumber;
}

RealNumber::RealNumber(const RealNumber &other){
    m_number = other.m_number;
}

//destructors

RealNumber::~RealNumber(){}

//operators

//=
RealNumber &RealNumber::operator=(const RealNumber &other){
    m_number = other.m_number;
    return *this;
}

//cout
ostream &operator<<(ostream &out, const RealNumber &realNumber){
    out << realNumber.m_number;
    return out;
}

//+= , -= , *= , /=
void RealNumber::operator+=(const RealNumber &other){
    m_number += other.m_number;
}
void RealNumber::operator-=(const RealNumber &other){
    m_number -= other.m_number;
}
void RealNumber::operator*=(const RealNumber &other){
    m_number *= other.m_number;
}
void RealNumber::operator/=(const RealNumber &other){
    m_number /= other.m_number;
}

//getters

double RealNumber::getMNumber() const{
    return m_number;
}

//setters

void RealNumber::setMNumber(const double mNumber){
    m_number = mNumber;
}

//special