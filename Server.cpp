// Ori Abramovitch 315598664


#include "Server.h"

Server::Server(int port) throw(const char *) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        throw "socket error: failed";
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        throw "bind error: failed";

    }
    if (listen(sockfd, 2) < 0) {
        throw "listen error: failed";
    }


}

void Server::start(ClientHandler &ch) throw(const char *) {

    {

        t = new thread([&ch, this]() {
            while (!isStop) {
                socklen_t clientSize = sizeof(client);
//                cout << "accept: "<<endl;

                int aClient = accept(sockfd, (struct sockaddr *) &client, &clientSize);
                if (aClient < 0) {
                    throw "accept error: failed";
                }
//                cout << ": handle"<<endl;
                ch.handle(aClient);
//                cout << ": close aClient  a"<<endl;
                close(aClient);
//                cout << ": close aClient  b"<<endl;

            }
            close(sockfd);
        });
    }

}

void Server::stop() {
    isStop = true;
    t->join(); // do not delete this!
}

Server::~Server() {
}

