//
// Created by Alex on 4/21/2021.
//

#ifndef TEMAPOO1_FIELD_H
#define TEMAPOO1_FIELD_H

#include <bits/stdc++.h>
using namespace std;


class Field {

    enum FieldType{
        Q,
        R,
        C,
        Zn
    };
    static const string fieldTypes[4];

    static FieldType parseFieldType(const char &type);

    FieldType m_type;
    long long m_modulo;

    //friends

    friend class Expression;

public:

    //constructors

    Field();
    Field(const char &mType);
    Field(const char &mType, const long long &mModulo);
    Field(const Field &other);

    //destructors

    virtual ~Field();

    //operators

    //=
    Field &operator=(const Field &other);

    //cout
    friend ostream &operator<<(ostream &out, const Field &field);

    //getters

    string getMType() const;
    long long getMModulo() const;

    //setters

    void setMType(const FieldType &mType);
    void setMModulo(const long long &mModulo);

    //special

    bool isIsomorphism(const Field &other);

};


#endif //TEMAPOO1_FIELD_H
