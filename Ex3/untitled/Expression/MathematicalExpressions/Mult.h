//
// Created by danie on 15/12/2018.
//

#ifndef UNTITLED_MULT_H
#define UNTITLED_MULT_H


#include "../BinaryExpression.h"

class Mult : public BinaryExpression<double, double> {
public:
    Mult(Expression<double>* first, Expression<double>* second) : BinaryExpression(first, second) {};
    virtual double calculate() {
        return m_first->calculate() * m_second->calculate();
    }
};


#endif //UNTITLED_MULT_H
