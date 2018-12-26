//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_LOWEREQUAL_H
#define UNTITLED_LOWEREQUAL_H

#include "../BinaryExpression.h"
#include "BooleanExpression.h"

class LowerEqual : public BooleanExpression<double> {
public:
    LowerEqual() = default;
    virtual bool calculate(double arg1, double arg2);
    ~LowerEqual() = default;
};


#endif //UNTITLED_LOWEREQUAL_H
