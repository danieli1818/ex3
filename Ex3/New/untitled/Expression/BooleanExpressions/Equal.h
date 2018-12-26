//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_EQUAL_H
#define UNTITLED_EQUAL_H


#include "../BinaryExpression.h"
#include "BooleanExpression.h"

class Equal : public BooleanExpression<double> {
public:
    Equal() = default;
    virtual bool calculate(double arg1, double arg2);
    ~Equal() = default;
};


#endif //UNTITLED_EQUAL_H
