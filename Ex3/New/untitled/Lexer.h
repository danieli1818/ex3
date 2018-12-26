//
// Created by daniel on 12/20/18.
//

#ifndef UNTITLED_LEXER_H
#define UNTITLED_LEXER_H

#include <string>
#include <list>

using namespace std;

class Lexer {
    void addSpaces(string& str);
    list<string> split(string str, const string& delimiter);
    void replaceTabs(string& str);
    inline bool isOperator(char c) {
        return ((c) == '+' || (c) == '-' || (c) == '*' || (c) == '/');
    }
    inline bool isOperatorOrBrackets(char c) {
        return isOperator(c) || (c) == '(' || (c) == ')' || (c) == '=';
    }
public:
    Lexer() = default;
    list<string> lexer(string& data);
};


#endif //UNTITLED_LEXER_H
