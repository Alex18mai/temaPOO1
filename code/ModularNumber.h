//
// Created by Alex on 4/21/2021.
//

#ifndef TEMAPOO1_MODULARNUMBER_H
#define TEMAPOO1_MODULARNUMBER_H

#include <bits/stdc++.h>
using namespace std;

class ModularNumber {

    long long m_number;
    long long m_modulo;

    //friends

public:

    //constructors

    ModularNumber();
    ModularNumber(const long long mNumber, const long long mModulo);
    ModularNumber(const ModularNumber &other);

    //destructors

    virtual ~ModularNumber();

    //operators

    //=
    ModularNumber &operator=(const ModularNumber &other);

    //cout
    friend ostream &operator<<(ostream &out, const ModularNumber &modularNumber);

    //+= , -= , *= , /=
    void operator+=(const ModularNumber &other);
    void operator-=(const ModularNumber &other);
    void operator*=(const ModularNumber &other);
    void operator/=(const ModularNumber &other);

    //getters

    long long getMNumber() const;
    long long getMModulo() const;

    //setters

    void setMNumber(const long long mNumber);
    void setMModulo(const long long mModulo);

    //special

};


#endif //TEMAPOO1_MODULARNUMBER_H
