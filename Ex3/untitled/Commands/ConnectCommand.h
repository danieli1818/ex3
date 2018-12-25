//
// Created by daniel on 12/21/18.
//

#ifndef UNTITLED_CONNECTCOMMAND_H
#define UNTITLED_CONNECTCOMMAND_H


#include "Command.h"
#include "../Expression/ExpressionManager.h"
#include "ClientUtils.h"

class ConnectCommand : public Command {
    void createClient(string& ip, int port);
public:
    ConnectCommand() = default;
    void doCommand(list<string>::iterator & it, list<string> & args);
    virtual ~ConnectCommand() = default;
};


#endif //UNTITLED_CONNECTCOMMAND_H
