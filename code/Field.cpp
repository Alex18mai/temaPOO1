//
// Created by Alex on 4/21/2021.
//

#include "Field.h"
#include <bits/stdc++.h>
using namespace std;

//static variables

const string Field::fieldTypes[4] = {
        "Q",
        "R",
        "C",
        "Zn"
};

//static functions

Field::FieldType Field::parseFieldType(const char &type){

    switch (type){
        case 'Q':
            return Q;
        case 'R':
            return R;
        case 'C':
            return C;
        case 'Z':
            return Zn;
    }
    return R;
}

//constructors

Field::Field(){
    m_type = R;
}
Field::Field(const char &mType){
    m_type = parseFieldType(mType);
}
Field::Field(const char &mType, const long long &mModulo){
    m_type = parseFieldType(mType);
    m_modulo = mModulo;
}
Field::Field(const Field &other){
    m_type = other.m_type;
    m_modulo = other.m_modulo;
}

//destructors

Field::~Field(){}

//operators

//=
Field &Field::operator=(const Field &other){
    m_type = other.m_type;
    m_modulo = other.m_modulo;
    return *this;
}

//cout
ostream &operator<<(ostream &out, const Field &field){
    if (field.m_type == Field::Zn){
        out << "(Z" << field.m_modulo <<", +, *)";
    }
    else{
        out<< "(" << Field::fieldTypes[field.m_type] << ", +, *)";
    }
    return out;
}

//getters

string Field::getMType() const{
    return fieldTypes[m_type];
}
long long Field::getMModulo() const{
    return m_modulo;
}

//setters

void Field::setMType(const Field::FieldType &mType){
    m_type = mType;
}
void Field::setMModulo(const long long &mModulo){
    m_modulo = mModulo;
}

//special

bool Field::isIsomorphism(const Field &other){
    if (m_type == other.m_type){
        if (m_type != Zn || (m_modulo == other.m_modulo)){
            return true;
        }
    }
    return false;
}