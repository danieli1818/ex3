//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_NOTEQUAL_H
#define UNTITLED_NOTEQUAL_H


#include "../BinaryExpression.h"
#include "BooleanExpression.h"

class NotEqual : public BooleanExpression<double> {
public:
    NotEqual() = default;
    virtual bool calculate(double arg1, double arg2);
    ~NotEqual() = default;
};


#endif //UNTITLED_NOTEQUAL_H
