//
// Created by Alex on 4/21/2021.
//

#ifndef TEMAPOO1_REALNUMBER_H
#define TEMAPOO1_REALNUMBER_H

#include <bits/stdc++.h>
using namespace std;


class RealNumber {

    double m_number;

    //friends

public:

    //constructors

    RealNumber();
    RealNumber(const double mNumber);
    RealNumber(const RealNumber &other);

    //destructors

    virtual ~RealNumber();

    //operators

    //=
    RealNumber &operator=(const RealNumber &other);

    //cout
    friend ostream &operator<<(ostream &out, const RealNumber &realNumber);

    //+= , -= , *= , /=
    void operator+=(const RealNumber &other);
    void operator-=(const RealNumber &other);
    void operator*=(const RealNumber &other);
    void operator/=(const RealNumber &other);

    //getters

    double getMNumber() const;

    //setters

    void setMNumber(const double mNumber);

    //special

};


#endif //TEMAPOO1_REALNUMBER_H
