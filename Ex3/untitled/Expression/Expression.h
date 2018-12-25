//
// Created by danie on 15/12/2018.
//

#ifndef UNTITLED_EXPRESSION_H
#define UNTITLED_EXPRESSION_H


template <class T>
class Expression {
public:
    virtual T calculate() = 0;
    virtual ~Expression() = default;
};


#endif //UNTITLED_EXPRESSION_H
