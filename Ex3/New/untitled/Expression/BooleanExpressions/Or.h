//
// Created by daniel on 12/19/18.
//

#include "../BinaryExpression.h"
#include "BooleanExpression.h"

#ifndef UNTITLED_OR_H
#define UNTITLED_OR_H

#endif //UNTITLED_OR_H

class Or : public BooleanExpression<bool> {
public:
    Or() = default;
    virtual bool calculate(bool arg1, bool arg2);
    ~Or() = default;
};



