//
// Created by danie on 15/12/2018.
//

#include <iostream>
#include "OpenServerCommand.h"
#include "DataReaderServer.h"

OpenServerCommand::OpenServerCommand() {}

void* OpenServerCommand::createServer(void *params) {
    try {
        ServerParameters serverParameters = *static_cast<ServerParameters*>(params);
        DataReaderServer drs(serverParameters.port, serverParameters.hz, serverParameters.count_mutex, serverParameters.condition_var);
        delete (ServerParameters*)params;
        //cout << "yay" << endl;
        drs.runServer();
    } catch (...) {
        throw "Not Valid Parameters";
    }
    return nullptr;
}


void OpenServerCommand::doCommand(list<string>::iterator& it, list<string> & args) {
    try {
        ExpressionManager em;
        double arg1 = em.calculate(it, args);
        if (it == args.end()) {
            throw "Not Valid Open Server Command!!!!";
        }
        if ((*it) == ",") {
            it++;
        }
        double arg2 = em.calculate(it, args);
        if (it != args.end() || arg1 <= 0 || (int)arg1 != arg1 || arg2 <= 0 || (int)arg2 != arg2) {
            throw "";
        }
        pthread_t trid;
        struct ServerParameters* pParams = new ServerParameters();
        pParams->port = (int)arg1;
        pParams->hz = (int)arg2;
        pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
        pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;
        pParams->count_mutex = &count_mutex;
        pParams->condition_var = &condition_var;
        pthread_create(&trid, nullptr, createServer, pParams);
        // Lock mutex and then wait for signal to relase mutex
        pthread_mutex_lock( &count_mutex );

        // Wait while functionCount2() operates on count
        // mutex unlocked if condition varialbe in functionCount2() signaled.
        pthread_cond_wait( &condition_var, &count_mutex );
        pthread_mutex_unlock( &count_mutex);
        pthread_mutex_destroy(&count_mutex);
        pthread_cond_destroy(&condition_var);
    } catch (...) {
        throw "invalid number of arguments for openDataServer";
    }
}


