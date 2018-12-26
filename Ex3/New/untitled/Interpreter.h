//
// Created by daniel on 12/23/18.
//

#ifndef UNTITLED_INTERPRETER_H
#define UNTITLED_INTERPRETER_H


#include "Lexer.h"
#include "Parser.h"
#include <fstream>

class Interpreter {
    static Lexer lexer;
    static Parser parser;
    static ifstream* file;
public:
    static void initialize();
    static Lexer& getLexer();
    static Parser& getParser();
    static ifstream*& getFileStream();
};


#endif //UNTITLED_INTERPRETER_H
