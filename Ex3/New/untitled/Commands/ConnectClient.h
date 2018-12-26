//
// Created by daniel on 12/21/18.
//

#ifndef UNTITLED_CONNECTCLIENT_H
#define UNTITLED_CONNECTCLIENT_H


#include <netdb.h>
#include <string>

using  namespace std;

class ConnectClient {
    /*string m_server;
    int m_port;*/
    int m_sock;
public:
    ConnectClient();
    ConnectClient(string& ip, int port);
    void setFlightParameter(string pathToVariable, double value);
    void rebuild(string ip, int port);
    ~ConnectClient();
};


#endif //UNTITLED_CONNECTCLIENT_H
