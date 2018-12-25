//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_LOWER_H
#define UNTITLED_LOWER_H

#include "../BinaryExpression.h"
#include "BooleanExpression.h"

class Lower : public BooleanExpression<double> {
public:
    Lower() = default;
    virtual bool calculate(double arg1, double arg2);
    ~Lower() = default;
};


#endif //UNTITLED_LOWER_H
