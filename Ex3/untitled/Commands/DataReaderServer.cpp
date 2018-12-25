//
// Created by daniel on 12/17/18.
//

#include <cstdio>
#include <cstdlib>
#include <strings.h>
#include <chrono>
#include <iostream>
#include "DataReaderServer.h"
#include "../Lexer.h"
#include "../Vars/ToolBox.h"

using namespace std;

const size_t DataReaderServer::BUFFER_SIZE = 256;

//Example code: A simple server side code, which echos back the received message.
//Handle multiple socket connections with select and fd_set on Linux
#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <condition_variable>

#define TRUE 1
#define FALSE 0

DataReaderServer::DataReaderServer(int port, int hz, pthread_mutex_t* count_mutex, pthread_cond_t* condition_var) :
                                    m_hz(hz), m_port(port), m_count_mutex(count_mutex), m_condition_var(condition_var) {
    if (hz <= 0) {
        throw "Hz must be > 0";
    }
    m_master_socket = 0;
    m_client_socket = 0;
}

void DataReaderServer::runServer() {

    int opt = 1;
    ssize_t valread;
    size_t addrlen;
    struct sockaddr_in address;
    bool first_time = true;

    char buffer[BUFFER_SIZE];  //data buffer of 1K

    //create a master socket
    if( (m_master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //set master socket to allow multiple connections ,
    //this is just a good habit, it will work without this
    if( setsockopt(m_master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
                   sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( m_port );

    //bind the socket to localhost port m_port
    if (bind(m_master_socket, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    //printf("Listener on port %d \n", m_port);

    //try to specify maximum of 3 pending connections for the master socket
    if (listen(m_master_socket, MAX_CLIENTS) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //accept the incoming connection
    //cout << "waiting for client" << endl;
    addrlen = sizeof(address);
    //puts("Waiting for connections ...");
    m_client_socket = accept(m_master_socket,
                             (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (m_client_socket < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    first_time = true;



    string bufferStr;
    //cout << "client connected" << endl;
    bool got_error = false;
    while (true) {
        auto before = std::chrono::high_resolution_clock::now();
        size_t read_size = 0;
        valread = read(m_client_socket, buffer, BUFFER_SIZE);
        if (0 == valread) {
            close(m_client_socket);
            break;
        } else if (valread < 0) {
            perror("Failed reading");
            got_error = true;
            break;
        }  else {
            read_size += valread;
//            copy(buffer, buffer+valread, back_inserter(bufferStr));
            bufferStr += string(buffer, valread);
            while (find(bufferStr.begin(), bufferStr.end(), '\n') == bufferStr.end()) {
                valread = read(m_client_socket, buffer, BUFFER_SIZE);
                if (valread < 0) {
                    perror("Failed reading");
                    got_error = true;
                    break;
                }
                read_size += valread;
//                copy(buffer, buffer+valread, back_inserter(bufferStr));
                bufferStr += string(buffer, valread);
            }
            if (got_error) {
                break;
            }
            if (first_time) {
                pthread_cond_signal( m_condition_var );
                first_time = !first_time;
            }

//            bufferStr.resize(read_size);
//            cout << "Read size " << read_size << endl;

            auto pos = bufferStr.find('\n');
            string symbolsXml = bufferStr.substr(0, pos);
//            cout << "Whole: " << bufferStr << endl;
//            cout << "got:" << symbolsXml <<endl;
            if (pos < bufferStr.size() - 1) {
              //  cout << "rest size " << (bufferStr.size() - pos) << endl;
                bufferStr = bufferStr.substr(pos + 1, bufferStr.size() - pos);
            } else {
                bufferStr.clear();
            }
//            cout << "rest:" << bufferStr <<endl;
            try {
                ToolBox::getSymbolTable().updateSymbolTable(symbolsXml);
            } catch (...) {
                pthread_mutex_unlock(&(ToolBox::getMutex()));
                //cout << "Got exception while updating symbol table" << endl;
            }
        }
        double sleepTime = (1 / (double)m_hz) * 1000000;
        auto timePassed = std::chrono::duration_cast<std::chrono::microseconds>
                (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        if (sleepTime > timePassed) {
            usleep((unsigned int) sleepTime - timePassed);
        }
    }
    //cout << "Client stopped" << endl;

    if (got_error) {
        // TODO handle error
        return;
    }
}

DataReaderServer::~DataReaderServer() {
    if (m_master_socket > 0) {
        close(m_master_socket);
    }
    if (m_client_socket > 0) {
        close (m_client_socket);
    }
}


