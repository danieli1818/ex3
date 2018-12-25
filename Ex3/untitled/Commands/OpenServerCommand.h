//
// Created by danie on 15/12/2018.
//

#ifndef UNTITLED_OPENSERVERCOMMAND_H
#define UNTITLED_OPENSERVERCOMMAND_H


#include "Command.h"
#include "../Expression/ExpressionManager.h"
#include "ServerUtils.h"
#include <pthread.h>

class OpenServerCommand: public Command {
    static void * createServer(void * params);
public:
    OpenServerCommand();
    virtual void doCommand(list<string>::iterator& it, list<string> & args);
    virtual ~OpenServerCommand() = default;
};


#endif //UNTITLED_OPENSERVERCOMMAND_H
