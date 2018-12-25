//
// Created by daniel on 12/21/18.
//

#ifndef UNTITLED_TOOLBOX_H
#define UNTITLED_TOOLBOX_H


#include "SymbolTable.h"
#include "../Commands/ConnectClient.h"
#include <list>
#include <string>

class ToolBox {
    static SymbolTable st;
    static pthread_mutex_t mutex;
    static ConnectClient client;
    static bool isClientInitialized;
    static list<string> savedWords;
public:
    static SymbolTable& getSymbolTable();
    static pthread_mutex_t& getMutex();
    static ConnectClient& getClient();
    static bool getIsClientInitialized();
    static void setIsClientInitialized(bool value);
    static void initialize();
    static void destroy();
    static list<string> getSavedWords();
};


#endif //UNTITLED_TOOLBOX_H
