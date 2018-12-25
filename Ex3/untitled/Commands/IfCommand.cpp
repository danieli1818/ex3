//
// Created by daniel on 12/20/18.
//

#include <iostream>
#include "IfCommand.h"
#include "../Expression/ExpressionManager.h"
#include "../ConditionParser.h"
#include "../Interpreter.h"

void IfCommand::doCommand(list<string>::iterator &it, list<string> &args) {
    if (it == args.end()) {
        throw "Not Enough Arguments To The If Command!!!!";
    }
    ExpressionManager em;
    double arg1 = em.calculate(it, args);
    if (it == args.end()) {
        throw "Not Valid If Command!!!!";
    }
    string condition = *it;
    it++;
    if (it == args.end()) {
        throw "Not Valid If Command!!!!";
    }
    double arg2 = em.calculate(it, args);
    bool brackets = true;
    if (it == args.end()) {
        brackets = false;
    } else {
        if (*it != "{") {
            throw "Not Valid If Command!!!!";
        }
        it++;
    }
    int numberOfBrackets = 1;
    ConditionParser cp;
    if (cp.calculateExpression(arg1, arg2, condition)) {
        if (Interpreter::getFileStream() != nullptr) { // reads from file.
            string line;
            while (getline(*Interpreter::getFileStream(), line))
            {
                args = Interpreter::getLexer().lexer(line);
                it = args.begin();
                if (!brackets) {
                    while (it != args.end() && it->empty()) {
                        it++;
                    }
                    if (*it == "{") {
                        brackets = true;
                        it++;
                        while (it != args.end() && it->empty()) {
                            it++;
                        }
                        if (it != args.end() && *it != "}") {
                            throw "If Command Not Valid!!!!";
                        }
                        if (it == args.end()) {
                            continue;
                        } else {
                            it++;
                            while (it != args.end() && it->empty()) {
                                it++;
                            }
                            if (it != args.end()) {
                                throw "Not Valid If Command!!!!";
                            }
                            break;
                        }
                    }
                } else {
                    list<string>::iterator temp = it;
                    while (temp != args.end() && numberOfBrackets > 0) {
                        if (*temp == "{") {
                            numberOfBrackets++;
                        } else {
                            if (*temp == "}") {
                                numberOfBrackets--;
                            }
                        }
                        temp++;
                    }
                    if (temp != args.end()) {
                        throw "Not Valid If Command!!!!";
                    }
                    if (numberOfBrackets <= 0) {
                        list<string> final;
                        while (it != args.end() && next(it) != args.end()) {
                            final.push_back(*it);
                        }
                        if (it != args.end()) {
                            it++;
                        }
                        Interpreter::getParser().parser(final);
                        break;
                    } else {
                        Interpreter::getParser().parser(args);
                    }
                }
            }
        }
    } else {
        if (Interpreter::getFileStream() != nullptr) { // reads from file.
            string line;
            while (getline(*Interpreter::getFileStream(), line))
            {
                args = Interpreter::getLexer().lexer(line);
                it = args.begin();
                if (!brackets) {
                    while (it != args.end() && it->empty()) {
                        it++;
                    }
                    if (*it == "{") {
                        brackets = true;
                        it++;
                        while (it != args.end() && it->empty()) {
                            it++;
                        }
                        if (it != args.end() && *it != "}") {
                            throw "If Command Not Valid!!!!";
                        }
                        if (it == args.end()) {
                            continue;
                        } else {
                            it++;
                            while (it != args.end() && it->empty()) {
                                it++;
                            }
                            if (it != args.end()) {
                                throw "Not Valid If Command!!!!";
                            }
                            break;
                        }
                    }
                } else {
                    list<string>::iterator temp = it;
                    while (temp != args.end() && numberOfBrackets > 0) {
                        if (*temp == "{") {
                            numberOfBrackets++;
                        } else {
                            if (*temp == "}") {
                                numberOfBrackets--;
                            }
                        }
                        temp++;
                    }
                    if (temp != args.end()) {
                        throw "Not Valid If Command!!!!";
                    }
                    if (numberOfBrackets <= 0) {
                        list<string> final;
                        while (it != args.end() && next(it) != args.end()) {
                            final.push_back(*it);
                        }
                        if (it != args.end()) {
                            it++;
                        }
                    }
                }
            }
        }
    }
}


