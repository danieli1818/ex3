//
// Created by daniel on 12/23/18.
//

#include <iostream>
#include "WhileCommand.h"
#include "../Expression/ExpressionManager.h"
#include "../ConditionParser.h"
#include "../Interpreter.h"

void WhileCommand::doCommand(list<string>::iterator &it, list<string> &args) {
    m_condition.clear();
    if (it == args.end()) {
        throw "Not Enough Arguments To The While Command!!!!";
    }
    ExpressionManager em;
    list<string>::iterator conditionIterator = it;
    double arg1 = em.calculate(it, args);
    if (it == args.end()) {
        throw "Not Valid While Command!!!!";
    }
    string condition = *it;
    it++;
    if (it == args.end()) {
        throw "Not Valid While Command!!!!";
    }
    double arg2 = em.calculate(it, args);
    while (conditionIterator != it) {
        m_condition.push_back(*conditionIterator);
        conditionIterator++;
    }
    bool brackets = true;
    if (it == args.end()) {
        brackets = false;
    } else {
        if (*it != "{") {
            throw "Not Valid While Command!!!!";
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
                            throw "While Command Not Valid!!!!";
                        }
                        if (it == args.end()) {
                            continue;
                        } else {
                            it++;
                            while (it != args.end() && it->empty()) {
                                it++;
                            }
                            if (it != args.end()) {
                                throw "Not Valid While Command!!!!";
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
                        throw "Not Valid While Command!!!!";
                    }
                    if (numberOfBrackets <= 0) {
                        list<string> final;
                        while (it != args.end() && next(it) != args.end()) {
                            final.push_back(*it);
                        }
                        if (it != args.end()) {
                            it++;
                        }
                        m_commandsStrings.emplace_back(final);
                        Interpreter::getParser().parser(final);
                        break;
                    } else {
                        m_commandsStrings.emplace_back(args);
                        Interpreter::getParser().parser(args);
                    }
                }
            }
        } else { //reads from user input.
            string line;
            getline(cin, line);
            while (true) {
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
                            throw "While Command Not Valid!!!!";
                        }
                        if (it == args.end()) {
                            continue;
                        } else {
                            it++;
                            while (it != args.end() && it->empty()) {
                                it++;
                            }
                            if (it != args.end()) {
                                throw "Not Valid While Command!!!!";
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
                        throw "Not Valid While Command!!!!";
                    }
                    if (numberOfBrackets <= 0) {
                        list<string> final;
                        while (it != args.end() && next(it) != args.end()) {
                            final.push_back(*it);
                        }
                        if (it != args.end()) {
                            it++;
                        }
                        m_commandsStrings.emplace_back(final);
                        Interpreter::getParser().parser(final);
                        break;
                    } else {
                        m_commandsStrings.emplace_back(args);
                        Interpreter::getParser().parser(args);
                    }
                }
                getline(cin, line);
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
                            throw "While Command Not Valid!!!!";
                        }
                        if (it == args.end()) {
                            continue;
                        } else {
                            it++;
                            while (it != args.end() && it->empty()) {
                                it++;
                            }
                            if (it != args.end()) {
                                throw "Not Valid While Command!!!!";
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
                        throw "Not Valid While Command!!!!";
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
        } else { //reads from user input.
            string line;
            getline(cin, line);
            while (true) {
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
                            throw "While Command Not Valid!!!!";
                        }
                        if (it == args.end()) {
                            continue;
                        } else {
                            it++;
                            while (it != args.end() && it->empty()) {
                                it++;
                            }
                            if (it != args.end()) {
                                throw "Not Valid While Command!!!!";
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
                        throw "Not Valid While Command!!!!";
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
                getline(cin, line);
            }
        }
        return;
    }
    conditionIterator = m_condition.begin();
    arg1 = em.calculate(conditionIterator, m_condition);
    conditionIterator++;
    arg2 = em.calculate(conditionIterator, m_condition);
    while (cp.calculateExpression(arg1, arg2, condition)) {
        for (int i = 0; i < m_commandsStrings.size(); i++)
        {
            list<string> elements = m_commandsStrings[i];
            Interpreter::getParser().parser(elements);
        }
        conditionIterator = m_condition.begin();
        arg1 = em.calculate(conditionIterator, m_condition);
        conditionIterator++;
        arg2 = em.calculate(conditionIterator, m_condition);
    }
}


