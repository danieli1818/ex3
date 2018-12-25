//
// Created by daniel on 12/20/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "../Expression/ExpressionManager.h"

void PrintCommand::doCommand(list<string>::iterator& it, list<string> & args) {
    if (it == args.end()) {
        throw "Not enough arguments!!!!";
    }
    if (next(it) != args.end()) {
        throw "Too many arguments!!!!";
    }
    if ((*it)[0] != '\"') {
        ExpressionManager em;
        try {
            double result = em.calculate(it, args);
            cout << result << endl;
            return;
        } catch (...) {
            throw "Not Valid Print Command!!!!";
        }
    }
    if ((*it)[it->length() - 1] != '\"') {
        throw "Not Valid String!!!!";
    }
    cout << it->substr(1, it->length() - 2) << endl;
    it++;
}


