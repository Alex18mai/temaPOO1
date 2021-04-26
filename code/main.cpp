//ALEX ENACHE

#include <bits/stdc++.h>
#include "Field.h"
#include "Expression.h"
#include "RationalNumber.h"
#include "RealNumber.h"
#include "ComplexNumber.h"
#include "ModularNumber.h"

using namespace std;


bool isPrime(int n){
    for (int i=2; i*i<=n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

pair < char , int > readField(){
    cout<<"Please enter the field. The options are:\n";
    cout<<"Q - for (Q , + , *)\n";
    cout<<"R - for (R , + , *)\n";
    cout<<"C - for (C , + , *).\n";
    cout<<"Z p - for (Zp, + , *). Here p must be a prime integer (otherwise it will not be a field).\n";

    char c;
    cin>>c;

    int p = 0;
    if (c == 'Z'){
        cin>>p;
        if (!isPrime(p)){
            cout<<"Wrong input - not a prime number!\n";
            return readField();
        }
    }
    if (c != 'Q' && c != 'R' && c != 'C' && c != 'Z'){
        cout<<"Wrong input - unknown set of numbers!\n";
        return readField();
    }

    return {c , p};
;}


void rationalExpression(Field &field){
    cout<<"Please enter the number of terms in the expression:\n";
    int n;
    cin>>n;

    double nr;
    vector < RationalNumber > v;

    for (char term='A'; term<min(char('A'+n), 'Z'); term++){
        cout<<term<<"=";
        cin>>nr;
        v.push_back(RationalNumber(nr));
    }

    cout<<"Please enter the expression - no spaces, using capital letters as the terms, basic operation (+, -, *, /):\n";
    string exp;
    cin>>exp;

    Expression expression(exp, field);
    RationalNumber ans = expression.solveExpression<RationalNumber>(v);

    cout<<expression<<" = "<<ans<<"\n\n";
}

void realExpression(Field &field){
    cout<<"Please enter the number of terms in the expression:\n";
    int n;
    cin>>n;

    double nr;
    vector < RealNumber > v;

    for (char term='A'; term<min(char('A'+n), 'Z'); term++){
        cout<<term<<"=";
        cin>>nr;
        v.push_back(RealNumber(nr));
    }

    cout<<"Please enter the expression - no spaces, using capital letters as the terms, basic operation (+, -, *, /):\n";
    string exp;
    cin>>exp;

    Expression expression(exp, field);
    RealNumber ans = expression.solveExpression<RealNumber>(v);

    cout<<expression<<" = "<<ans<<"\n\n";
}

void complexExpression(Field &field){
    cout<<"Please enter the number of terms in the expression:\n";
    int n;
    cin>>n;

    double real, imaginary;
    vector < ComplexNumber > v;

    for (char term='A'; term<min(char('A'+n), 'Z'); term++){
        cout<<term<<".real=";
        cin>>real;
        cout<<term<<".imaginary=";
        cin>>imaginary;
        v.push_back(ComplexNumber(real, imaginary));
    }

    cout<<"Please enter the expression - no spaces, using capital letters as the terms, basic operation (+, -, *, /):\n";
    string exp;
    cin>>exp;

    Expression expression(exp, field);
    ComplexNumber ans = expression.solveExpression<ComplexNumber>(v);

    cout<<expression<<" = "<<ans<<"\n\n";
}

void modularExpression(Field &field){
    cout<<"Please enter the number of terms in the expression:\n";
    int n;
    cin>>n;

    long long nr;
    vector < ModularNumber > v;

    for (char term='A'; term<min(char('A'+n), 'Z'); term++){
        cout<<term<<"=";
        cin>>nr;
        v.push_back(ModularNumber(nr, field.getMModulo()));
    }

    cout<<"Please enter the expression - no spaces, using capital letters as the terms, basic operation (+, -, *, /):\n";
    string exp;
    cin>>exp;

    Expression expression(exp, field);
    ModularNumber ans = expression.solveExpression<ModularNumber>(v);

    cout<<expression<<" = "<<ans<<"\n\n";
}

void fieldExpression(){
    pair <char , int > field_parameters;

    field_parameters = readField();
    Field field(field_parameters.first, field_parameters.second);

    if (field.getMType() == "Q"){
        rationalExpression(field);
    }
    else if (field.getMType() == "R"){
        realExpression(field);
    }
    else if (field.getMType() == "C"){
        complexExpression(field);
    }
    else if (field.getMType() == "Zn"){
        modularExpression(field);
    }

}

void fieldIsomorphism(){
    pair <char , int > field_parameters;

    cout<<"Field 1\n";
    field_parameters = readField();
    Field field1(field_parameters.first, field_parameters.second);

    cout<<"Field 2\n";
    field_parameters = readField();
    Field field2(field_parameters.first, field_parameters.second);

    bool ok = field1.isIsomorphism(field2);

    if (ok)
        cout<<field1<<" is isomorphic with "<<field2<<'\n';
    else
        cout<<field1<<" is not isomorphic with "<<field2<<'\n';

}


int main() {

    while (true){
        cout<<"Menu:\n";
        cout<<"E - evaluate an expression with variables from a field.\n";
        cout<<"I - check if 2 fields are isomorphic.\n";
        cout<<"Q - quit.\n";

        char step;
        cin>>step;

        if (step == 'E'){
            fieldExpression();
        }
        else if (step == 'I'){
            fieldIsomorphism();
        }
        else if (step == 'Q'){
            cout<<"Bye bye! :)\n";
            break;
        }
        else {
            cout<<"Wrong input!\n";
        }
    }

    return 0;
}