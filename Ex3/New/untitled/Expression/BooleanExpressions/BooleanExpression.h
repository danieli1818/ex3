//
// Created by daniel on 12/23/18.
//

#ifndef UNTITLED_BOOLEANEXPRESSION_H
#define UNTITLED_BOOLEANEXPRESSION_H

template <class T>
class BooleanExpression {
public:
    virtual bool calculate(T arg1, T arg2) = 0;
    virtual ~BooleanExpression() = default;
};


#endif //UNTITLED_BOOLEANEXPRESSION_H
