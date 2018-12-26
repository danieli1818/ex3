//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_BIGGER_H
#define UNTITLED_BIGGER_H

#include "../BinaryExpression.h"
#include "BooleanExpression.h"

class Bigger : public BooleanExpression<double> {
public:
    Bigger() = default;
    virtual bool calculate(double arg1, double arg2);
    ~Bigger() = default;
};


#endif //UNTITLED_BIGGER_H
