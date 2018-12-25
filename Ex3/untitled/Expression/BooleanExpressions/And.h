//
// Created by daniel on 12/19/18.
//

#ifndef UNTITLED_AND_H
#define UNTITLED_AND_H

#include "../BinaryExpression.h"
#include "BooleanExpression.h"

class And : BooleanExpression<bool> {
public:
    And() = default;
    bool calculate(bool arg1, bool arg2);
    ~And() = default;
};


#endif //UNTITLED_AND_H
