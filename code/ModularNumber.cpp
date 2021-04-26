//
// Created by Alex on 4/21/2021.
//

#include "ModularNumber.h"
#include <bits/stdc++.h>
using namespace std;

//constructors

ModularNumber::ModularNumber(){
    m_number = 0;
    m_modulo = 2;
}

ModularNumber::ModularNumber(const long long mNumber, const long long mModulo){
    m_number = mNumber % mModulo;
    m_modulo = mModulo;
}

ModularNumber::ModularNumber(const ModularNumber &other){
    m_number = other.m_number;
    m_modulo = other.m_modulo;
}

//destructors

ModularNumber::~ModularNumber(){}

//operators

//=
ModularNumber &ModularNumber::operator=(const ModularNumber &other){
    m_number = other.m_number;
    m_modulo = other.m_modulo;
    return *this;
}

//cout
ostream &operator<<(ostream &out, const ModularNumber &modularNumber){
    out << modularNumber.m_number;
    return out;
}

//+= , -= , *= , /=
void ModularNumber::operator+=(const ModularNumber &other){
    m_number += other.m_number;
    m_number %= m_modulo;
}
void ModularNumber::operator-=(const ModularNumber &other){
    m_number -= other.m_number;
    m_number = (m_number + m_modulo) % m_modulo;
}
void ModularNumber::operator*=(const ModularNumber &other){
    m_number *= other.m_number;
    m_number %= m_modulo;
}
void ModularNumber::operator/=(const ModularNumber &other){ //this is fun
    //I used Fermat's little theorem with m_modulo a prime number (also fast exponentiation)

    long long inverse_modular = 1LL;
    long long put = m_modulo - 2LL;
    long long base = other.m_number;
    while (put) {
        if (put & 1LL) inverse_modular = (inverse_modular * base) % m_modulo;
        base = (base * base) % m_modulo;
        put >>= 1LL;
    }

    m_number *= inverse_modular;
    m_number %= m_modulo;
}

//getters

long long ModularNumber::getMNumber() const{
    return m_number;
}

long long ModularNumber::getMModulo() const {
    return m_modulo;
}

//setters

void ModularNumber::setMNumber(const long long mNumber){
    m_number = mNumber;
}

void ModularNumber::setMModulo(const long long mModulo){
    m_number = mModulo;
}

//special