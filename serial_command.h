/******************************************************************
    Author:     Juan Menendez Blanco    <juanmb@gmail.com>

    This code is part of the NexStarAdapter project:
        https://github.com/juanmb/NexStarAdapter

*******************************************************************/

#ifndef _SerialCommand_h_
#define _SerialCommand_h_

#include <inttypes.h>

#define MAX_CMD_SIZE 32
#define MAX_COMMANDS 32


typedef void (* cbFunction)(char*);


typedef struct commandCallback {
    char firstChar;
    uint8_t size;
    cbFunction function;
} commandCallback;


class SerialCommand {
public:
    SerialCommand();
    void readSerial();
    int addCommand(const char, uint8_t, cbFunction);
private:
    commandCallback commandList[MAX_COMMANDS];
    char buffer[MAX_CMD_SIZE];
    cbFunction cmdFunction;
    int nCommands;
    int cmdSize;
    int bufPos;
};

#endif
