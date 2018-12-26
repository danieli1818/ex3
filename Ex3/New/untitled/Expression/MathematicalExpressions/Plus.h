//
// Created by danie on 15/12/2018.
//

#ifndef UNTITLED_PLUS_H
#define UNTITLED_PLUS_H


#include "../BinaryExpression.h"

class Plus : public BinaryExpression<double, double> {
public:
    Plus(Expression<double>* first, Expression<double>* second) : BinaryExpression(first, second) {};
    virtual double calculate() {
            return m_first->calculate() + m_second->calculate();
    }
};


#endif //UNTITLED_PLUS_H
