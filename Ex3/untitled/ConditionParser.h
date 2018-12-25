//
// Created by daniel on 12/23/18.
//

#ifndef UNTITLED_CONDITIONPARSER_H
#define UNTITLED_CONDITIONPARSER_H

#include <map>
#include <string>
#include "Expression/Expression.h"
#include "Expression/BooleanExpressions/BooleanExpression.h"
#include "Expression/BooleanExpressions/BooleanExpressions.h"

using namespace std;

class ConditionParser {
    map<string, BooleanExpression<double>* > parsingMap;
public:
    ConditionParser();
    bool calculateExpression(double arg1, double arg2, const string& condition);
    ~ConditionParser();
};


#endif //UNTITLED_CONDITIONPARSER_H
