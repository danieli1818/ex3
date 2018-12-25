//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_BIGGEREQUAL_H
#define UNTITLED_BIGGEREQUAL_H

#include "../BinaryExpression.h"
#include "BooleanExpression.h"

class BiggerEqual : public BooleanExpression<double> {
public:
    BiggerEqual() = default;
    virtual bool calculate(double arg1, double arg2);
    ~BiggerEqual() = default;
};


#endif //UNTITLED_BIGGEREQUAL_H
