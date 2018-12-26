//
// Created by daniel on 12/17/18.
//

#ifndef UNTITLED_DATAREADERSERVER_H
#define UNTITLED_DATAREADERSERVER_H

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include "../Parser.h"
#include "ServerUtils.h"
#define MAX_CLIENTS 5

class DataReaderServer {
    int m_hz;
    int m_port;
    pthread_mutex_t* m_count_mutex;
    pthread_cond_t*  m_condition_var;
    int m_master_socket;
    int m_client_socket;
    //Parser m_parser;
    static const size_t BUFFER_SIZE;
public:
    DataReaderServer(int port, int hz, pthread_mutex_t* count_mutex, pthread_cond_t* condition_var);
    void runServer();
    ~DataReaderServer();
};


#endif //UNTITLED_DATAREADERSERVER_H
