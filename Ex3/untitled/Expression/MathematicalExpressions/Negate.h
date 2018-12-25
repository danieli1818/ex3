//
// Created by daniel on 12/19/18.
//

#ifndef UNTITLED_NEGATE_H
#define UNTITLED_NEGATE_H

#include "../UnaryExpression.h"

class Negate : public UnaryExpression<double> {
    Negate(Expression<double> * e) : UnaryExpression(e) {}
    virtual double calculate() {
        return -(m_expression->calculate());
    }
};

#endif //UNTITLED_NEGATE_H
