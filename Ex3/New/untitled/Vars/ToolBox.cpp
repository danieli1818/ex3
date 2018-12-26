//
// Created by daniel on 12/21/18.
//

#include "ToolBox.h"

SymbolTable ToolBox::st;
pthread_mutex_t ToolBox::mutex;
ConnectClient ToolBox::client;
bool ToolBox::isClientInitialized = false;
list<string> ToolBox::savedWords;

SymbolTable& ToolBox::getSymbolTable() {
    return st;
}

pthread_mutex_t& ToolBox::getMutex() {
    return mutex;
}

ConnectClient& ToolBox::getClient() {
    return client;
}

bool ToolBox::getIsClientInitialized() {
    return isClientInitialized;
}

void ToolBox::setIsClientInitialized(bool value) {
    isClientInitialized = value;
}

void ToolBox::initialize() {
    ToolBox::savedWords = {
            "openDataServer",
            "connect",
            "var",
            "bind",
            "while",
            "if",
            "print"
    };
    pthread_mutex_init(&mutex, nullptr);
}

void ToolBox::destroy() {
    pthread_mutex_destroy(&mutex);
}

list<string> ToolBox::getSavedWords() {
    return savedWords;
}


