//
// Created by daniel on 12/23/18.
//

#include "Interpreter.h"

Lexer Interpreter::lexer;
Parser Interpreter::parser;
ifstream* Interpreter::file;

void Interpreter::initialize() {
    parser.initialize();
    file = nullptr;
}

Lexer& Interpreter::getLexer() {
    return lexer;
}

Parser& Interpreter::getParser() {
    return parser;
}

ifstream*& Interpreter::getFileStream() {
    return file;
}


