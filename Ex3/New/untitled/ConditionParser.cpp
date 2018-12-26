//
// Created by daniel on 12/23/18.
//

#include "ConditionParser.h"

ConditionParser::ConditionParser() {
    parsingMap.emplace(">", new Bigger());
    parsingMap.emplace("<", new Lower());
    parsingMap.emplace(">=", new BiggerEqual());
    parsingMap.emplace("<=", new LowerEqual());
    parsingMap.emplace("==", new Equal());
    parsingMap.emplace("!=", new NotEqual());
}

bool ConditionParser::calculateExpression(double arg1, double arg2, const string &condition) {
    if (parsingMap.count(condition) == 1) {
        bool result = parsingMap[condition]->calculate(arg1, arg2);
        return result;
    }
    throw "Condition doesn't exist!!!!";
}

ConditionParser::~ConditionParser() {
    for (auto & element : parsingMap) {
        delete element.second;
    }
    parsingMap.clear();
}


