// Ori Abramovitch 315598664


#ifndef CLI_H_
#define CLI_H_

#include <cstring>
#include "commands.h"
#include <vector>

using namespace std;

class CLI {
    DefaultIO *dio;
    vector<Command *> menuVec;
    CommandsData data;
    // you can add data members

private:
    void initial_menu();
    void write_menu();

public:
    CLI(DefaultIO *dio);

    void start();



//    void write_line(float num, Command &command);

    virtual ~CLI();
};


#endif /* CLI_H_ */
