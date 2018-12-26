//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_SERVERUTILS_H
#define UNTITLED_SERVERUTILS_H

struct ServerParameters
{
    int port;
    int hz;
    pthread_mutex_t* count_mutex;
    pthread_cond_t*  condition_var;
};

#endif //UNTITLED_SERVERUTILS_H
