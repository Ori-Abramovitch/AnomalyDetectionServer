// Ori Abramovitch 315598664

/*
 * Server.h
 *
 *  Created on: Dec 13, 2020
 *      Author: Eli
 */

#ifndef SERVER_H_
#define SERVER_H_


#include <thread>
#include <netdb.h>
#include "CLI.h"
#include <sys/socket.h>
#include <unistd.h>

#include <pthread.h>
#include <thread>

#include <iostream>
#include<netinet/in.h>


using namespace std;

// edit your ClientHandler interface here:
class ClientHandler {
public:
    virtual void handle(int clientID) = 0;
};


// you can add helper classes here and implement on the cpp file


// edit your AnomalyDetectionHandler class here
class AnomalyDetectionHandler : public ClientHandler {
public:
    virtual void handle(int clientID) {
        SocketIO socketIo(clientID);
        CLI cli(&socketIo);
        cli.start();

    }
};


// implement on Server.cpp
class Server {

    int sockfd;
    sockaddr_in server;
    sockaddr_in client;


    thread *t; // the thread to run the start() method in

    // you may add data members

public:
    volatile bool isStop = false;
    Server(int port) throw(const char *);

    virtual ~Server();

    void start(ClientHandler &ch) throw(const char *);

    void stop();
};

#endif /* SERVER_H_ */
