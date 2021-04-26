//
// Created by Alex on 4/21/2021.
//

#ifndef TEMAPOO1_EXPRESSION_H
#define TEMAPOO1_EXPRESSION_H

#include "Field.h"
#include <bits/stdc++.h>
using namespace std;


class Expression {

    string m_expression;
    Field m_field;
    int m_pnt = 0;

    //friends

    //private functions
    template<typename T> T f1(const vector < T > &v){
        T ans = f2(v);
        while (m_pnt < m_expression.size() && (m_expression[m_pnt] == '+' || m_expression[m_pnt] == '-')) {
            if (m_expression[m_pnt] == '+') {
                m_pnt++;
                ans += f2(v);
            }
            else {
                m_pnt++;
                ans -= f2(v);
            }
        }
        return ans;
    }
    template<typename T> T f2(const vector < T > &v){
        T ans = f3(v);
        while (m_pnt < m_expression.size() && (m_expression[m_pnt] == '*' || m_expression[m_pnt] == '/')) {
            if (m_expression[m_pnt] == '*') {
                m_pnt++;
                ans *= f3(v);
            }
            else {
                m_pnt++;
                ans /= f3(v);
            }
        }
        return ans;
    }
    template<typename T> T f3(const vector < T > &v){
        T ans;
        if (m_pnt < m_expression.size() && m_expression[m_pnt] == '(') {
            m_pnt++;
            ans = f1(v);
            m_pnt++;
        }
        else if (m_pnt < m_expression.size() && (m_expression[m_pnt] >= 'A' && m_expression[m_pnt] <= 'Z')) {
            ans = v[m_expression[m_pnt]-'A'];
            m_pnt++;
        }
        return ans;
    }

public:

    //constructors

    Expression();
    Expression(const string &mExpression, const Field &mField);
    Expression(const Expression &other);

    //destructors

    virtual ~Expression();

    //operators

    //=
    Expression &operator=(const Expression &other);

    //cout
    friend ostream& operator<<(ostream& out, const Expression& expression);

    //getters

    string getMExpression() const;
    Field getMField() const;


    //setters

    void setMExpression(const string &mExpression);
    void setMField(const Field &mField);


    //special

    template<typename T> T solveExpression(const vector < T > &v){ //I really needed templates for this -> I use this function on 4 different classes
        m_pnt = 0;
        return f1(v);
    }
};


#endif //TEMAPOO1_EXPRESSION_H
