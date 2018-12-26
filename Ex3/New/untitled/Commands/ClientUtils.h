//
// Created by daniel on 12/21/18.
//

#ifndef UNTITLED_CLIENTUTILS_H
#define UNTITLED_CLIENTUTILS_H

#include <pthread.h>

struct IP {
    int p[4];
};

struct ClientParameters
{
    struct IP ip;
    int port;
};

#endif //UNTITLED_CLIENTUTILS_H
