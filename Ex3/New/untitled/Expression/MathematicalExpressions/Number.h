//
// Created by danie on 15/12/2018.
//

#ifndef UNTITLED_NUMBER_H
#define UNTITLED_NUMBER_H


#include "../Expression.h"

class Number : public Expression<double> {
    double m_num;
public:
    explicit Number(double num) : m_num(num) {};
    virtual double calculate() {
        return m_num;
    }

};


#endif //UNTITLED_NUMBER_H
