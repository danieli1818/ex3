//
// Created by danie on 14/12/2018.
//

#ifndef UNTITLED_COMMAND_H
#define UNTITLED_COMMAND_H

#include <string>
#include <list>
using namespace std;

class Command {
public:
    virtual void doCommand(list<string>::iterator & it, list<string> & args) = 0;
    virtual ~Command() = default;
};

#endif //UNTITLED_COMMAND_H
