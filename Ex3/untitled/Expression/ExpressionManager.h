//
// Created by daniel on 12/17/18.
//

#ifndef UNTITLED_EXPRESSIONCOMMAND_H
#define UNTITLED_EXPRESSIONCOMMAND_H


#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include "../Commands/Command.h"
#include "MathematicalExpressions/MathExpressions.h"

class ExpressionManager {
    bool isNumber(string& str);
    Expression<double>* getExpressionFromQueue(stack<string> &s);
    bool isPrecendencable(char op1, char op2);
    Expression<double>* getExpressionFromString(list<string>::iterator& it, list<string>& args);
    void fixUnaryOperator(list<string>::iterator& it, list<string>& args);
    inline static bool isOperator(char c) {
        return ((c) == '+' || (c) == '-' || (c) == '*' || (c) == '/');
    }
public:
    ExpressionManager();
    double calculate(list<string>::iterator& it, list<string>& listArgs);
    ~ExpressionManager() = default;
};


#endif //UNTITLED_EXPRESSIONCOMMAND_H
