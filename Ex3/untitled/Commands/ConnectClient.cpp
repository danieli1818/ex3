//
// Created by daniel on 12/21/18.
//

#include "ConnectClient.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

ConnectClient::ConnectClient() : m_sock(-1) {}

ConnectClient::ConnectClient(string& ip, int port) {
    rebuild(ip, port);
}

void ConnectClient::setFlightParameter(string pathToVariable, double value) {
    string msg = "set " + pathToVariable + " " + to_string(value) + "\r\n";
    send(m_sock, msg.c_str(), msg.length(), 0);
}

void ConnectClient::rebuild(string ip, int port) {
    if (m_sock >= 0) {
        close(m_sock);
    }
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        throw ("\n Socket creation error \n");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr)<=0)
    {
        throw ("\nInvalid address/ Address not supported \n");
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        throw ("\nConnection Failed \n");
    }
    m_sock = sock;
    //send(sock , hello , strlen(hello) , 0 );
    //printf("Hello message sent\n");
    //valread = read( sock , buffer, 1024);
    //printf("%s\n",buffer );
}

ConnectClient::~ConnectClient() {
    if (m_sock > 0) {
        close(m_sock);
    }
}


