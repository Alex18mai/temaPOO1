//
// Created by Alex on 4/21/2021.
//

#include "Expression.h"
#include <bits/stdc++.h>
using namespace std;

//constructors

Expression::Expression(){
    m_expression = "";
}
Expression::Expression(const string &mExpression, const Field &mField){
    m_expression = mExpression;
    m_field = mField;
}
Expression::Expression(const Expression &other){
    m_expression = other.m_expression;
    m_field = other.m_field;
}

//destructors

Expression::~Expression(){
    m_expression.clear();
}

//operators

//=
Expression &Expression::operator=(const Expression &other){
    m_expression = other.m_expression;
    m_field.m_type = other.m_field.m_type; m_field.m_modulo = other.m_field.m_modulo; //here I use the fact that it is a friend class
    return *this;
}

//cout
ostream& operator<<(ostream& out, const Expression& expression){
    out << expression.m_expression;
    return out;
}

//getters

string Expression::getMExpression() const{
    return m_expression;
}
Field Expression::getMField() const{
     return m_field;
}


//setters

void Expression::setMExpression(const string &mExpression){
    m_expression = mExpression;
}
void Expression::setMField(const Field &mField){
    m_field = mField;
}

//special




