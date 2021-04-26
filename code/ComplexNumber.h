//
// Created by Alex on 4/21/2021.
//

#ifndef TEMAPOO1_COMPLEXNUMBER_H
#define TEMAPOO1_COMPLEXNUMBER_H

#include <bits/stdc++.h>
using namespace std;


class ComplexNumber {

    double m_real;
    double m_imaginary;

    //friends

public:

    //constructors

    ComplexNumber();
    ComplexNumber(const double mReal, const double mImaginary);
    ComplexNumber(const ComplexNumber &other);

    //destructors

    virtual ~ComplexNumber();

    //operators

    //=
    ComplexNumber &operator=(const ComplexNumber &other);

    //cout
    friend ostream &operator<<(ostream &out, const ComplexNumber &realNumber);

    //+= , -= , *= , /=
    void operator+=(const ComplexNumber &other);
    void operator-=(const ComplexNumber &other);
    void operator*=(const ComplexNumber &other);
    void operator/=(const ComplexNumber &other);

    //getters

    double getMReal() const;
    double getMImaginary() const;

    //setters

    void setMReal(const double mReal);
    void setMImaginary(const double mImaginary);

    //special

    double getAbsoluteValue() const;
};


#endif //TEMAPOO1_COMPLEXNUMBER_H
