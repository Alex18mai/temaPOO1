//
// Created by Alex on 4/21/2021.
//

#ifndef TEMAPOO1_RATIONALNUMBER_H
#define TEMAPOO1_RATIONALNUMBER_H

#include <bits/stdc++.h>
using namespace std;

class RationalNumber {

    double m_number;

    //friends

public:

    //constructors

    RationalNumber();
    RationalNumber(const double mNumber);
    RationalNumber(const RationalNumber &other);

    //destructors

    virtual ~RationalNumber();

    //operators

    //=
    RationalNumber &operator=(const RationalNumber &other);

    //cout
    friend ostream &operator<<(ostream &out, const RationalNumber &rationalNumber);

    //+= , -= , *= , /=
    void operator+=(const RationalNumber &other);
    void operator-=(const RationalNumber &other);
    void operator*=(const RationalNumber &other);
    void operator/=(const RationalNumber &other);

    //getters

    double getMNumber() const;

    //setters

    void setMNumber(const double mNumber);

    //special
};


#endif //TEMAPOO1_RATIONALNUMBER_H
