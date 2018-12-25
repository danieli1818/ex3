//
// Created by daniel on 12/17/18.
//

#include <algorithm>
#include "ExpressionManager.h"
#include "../Vars/ToolBox.h"

ExpressionManager::ExpressionManager() {}

double ExpressionManager::calculate(list<string>::iterator &it, list<string>& args ) {
    Expression<double>* e = getExpressionFromString(it, args);
    double result = e->calculate();
    delete e;
    return result;
}
//-,(,2,+,3,)
// 0 - (2 + 3)
// -()
// 1 + 2 +  (0-(1 + 3))
// operator or nothing or (

// TODO add that as method
void ExpressionManager::fixUnaryOperator(list<string>::iterator& it, list<string>& args)
{


    if ((*it)[0] == '-') {
        // first
        args.insert(it, "0");
        it--;
    }

    list<string>::iterator prev_it = it;
    list<string>::iterator curr_it = next(prev_it);

    while (curr_it != args.end() && !curr_it->empty()) {
        if ((*curr_it)[0] == '-') {
            if (1 == prev_it->size() && (isOperator((*(prev_it))[0]) || *(prev_it) == "(")) {
                args.insert(curr_it, "(");
                args.insert(curr_it, "0");
                if (next(curr_it) != args.end() && *next(curr_it) == "(" ) {
                    int numOfBrackets = 1;
                    list<string>::iterator tmp_it = next(curr_it);
                    while (numOfBrackets != 0) {
                        if (tmp_it == args.end()) {
                            break;
                        } else if (*tmp_it == "(") {
                            numOfBrackets++;
                        } else if(*tmp_it == ")") {
                            numOfBrackets--;
                        }
                    }
                if (numOfBrackets != 0) {
                    throw "Brackets aren't closed!!!!";
                }
                args.insert(next(tmp_it), ")");
                }

            }


        }
        prev_it++;
        curr_it++;

    }
}

Expression<double>* ExpressionManager::getExpressionFromString(list<string>::iterator& it, list<string>& args) {
    if (it == args.end()) {
        throw "Error: Not Valid Expression Entered!!!!";
    }

    fixUnaryOperator(it, args);


    queue<string> numbersQueue;
    stack<string> expressionsStack;
    bool isLastNumber = false;
    bool hasStarted = false;
    while (it != args.end()) {
        if (isNumber(*it)) {
            if (hasStarted && isLastNumber) {
                break;
            }
            numbersQueue.push(*it);
            isLastNumber = true;
        } else if ((*it) == "(") {
            expressionsStack.push(*it);
            isLastNumber = false;
        } else if (1 == it->size() && isOperator((*it)[0])) {
            while (!expressionsStack.empty() &&
                   isOperator(expressionsStack.top()[0]) &&
                   isPrecendencable(expressionsStack.top()[0], (*it)[0])) {
                numbersQueue.push(expressionsStack.top());
                expressionsStack.pop();
            }
            expressionsStack.push(*it);
            isLastNumber = false;
        } else if ((*it) == ")") {
            while (!expressionsStack.empty() && expressionsStack.top() != "(") {
                numbersQueue.push(expressionsStack.top());
                expressionsStack.pop();
            }
            if (expressionsStack.empty()) {
                throw "Not Valid Expression Missing (";
            } else {
                expressionsStack.pop();
            }
            isLastNumber = false;
        } else {
            Variable* var = ToolBox::getSymbolTable().getVariable(*it);
            if (var == nullptr || (hasStarted && isLastNumber)) {
                break;
            }
            numbersQueue.push(to_string(var->getData()));
            isLastNumber = true;
        }
        it++;
        hasStarted = true;
    }
    while (!expressionsStack.empty()) {
        numbersQueue.push(expressionsStack.top());
        expressionsStack.pop();
    }
    stack<string> execution_stack;
    while (!numbersQueue.empty()) {
        execution_stack.push(numbersQueue.front());
        numbersQueue.pop();
    }
    Expression<double> * result = nullptr;
    try {
        result = getExpressionFromQueue(execution_stack);
    } catch (...) {
        delete result;
        throw;
    }
    return result;
}

bool ExpressionManager::isPrecendencable(char op1, char op2) {
    static map<char, int> precedence = {
            {'/', 2},
            {'*', 2},
            {'+', 1},
            {'-', 1},
    };

    return precedence[op1] >= precedence[op2];
}

Expression<double>* ExpressionManager::getExpressionFromQueue(stack<string> &s) {
    /*if (s.empty()) {
        throw;
    }*/
    if (isNumber(s.top())) {
        int number = stoi(s.top());
        s.pop();
        return new Number(number);
    } else {
        char c = s.top()[0];
        s.pop();
        if (c == '*') {
            Expression<double>* arg2 = getExpressionFromQueue(s);
            Expression<double>* arg1 = getExpressionFromQueue(s);
            return new Mult(arg1, arg2);
        } else if (c == '/') {
            Expression<double>* arg2 = getExpressionFromQueue(s);
            Expression<double>* arg1 = getExpressionFromQueue(s);
            return new Div(arg1, arg2);
        } else if (c == '+') {
            Expression<double>* arg2 = getExpressionFromQueue(s);
            Expression<double>* arg1 = getExpressionFromQueue(s);
            return new Plus(arg1, arg2);
        } else if (c == '-') {
            Expression<double>* arg2 = getExpressionFromQueue(s);
            Expression<double>* arg1 = getExpressionFromQueue(s);
            return new Minus(arg1, arg2);
        } else {
            throw to_string(c) + " isn't a valid character!";
        }
    }
}

bool ExpressionManager::isNumber(string &str) {
    try {
        stod(str);
        return true;
    } catch (...) {
        return false;
    }
//    return find_if(str.begin(), str.end(), [](char c){
//        return !isdigit(c);
//    }) == str.end();
}


