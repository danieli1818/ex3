//
// Created by daniel on 12/21/18.
//

#include <iostream>
#include "ConnectCommand.h"
#include "../Utils.h"
#include "ConnectClient.h"
#include "../Vars/ToolBox.h"

void ConnectCommand::createClient(string& ip, int port) {
    ToolBox::getClient().rebuild(ip, port);
    ToolBox::setIsClientInitialized(true);
}

void ConnectCommand::doCommand(list<string>::iterator &it, list<string> &args) {
    try {
        ExpressionManager em;
        string arg1 = *it;
        it++;
        double arg2 = em.calculate(it, args);
        if (it != args.end() || arg2 <= 0 || (int)arg2 != arg2) {
            throw "";
        }
        createClient(arg1, (int)arg2);
        //struct ClientParameters pParams;
//        vector<string> ipArr = Utils::split(arg1, ".");
//        if (ipArr.size() != 4) {
//            throw "";
//        }
//        for (auto)

        //pParams.port = (int)arg2;
    } catch (...) {
        throw "invalid number of arguments for openDataServer";
    }
}


