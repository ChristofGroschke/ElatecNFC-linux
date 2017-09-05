#pragma once
#include <string>
#include <iostream>
#include <linux/input.h> 

/*******************************/
/*   inputDecoder              */
/*******************************/


/**
    inputDecoder

    Decodes input from rfid/nfc reader like TWN4 Legic from Elatec GmbH use /dev file directly
    Create your own more special implementation if needed :)

    @author Christof Groschke
    @version 1.0 02.08.2017
*/


class inputDecoder{
    public:
        inputDecoder() {}
        virtual ~inputDecoder();
        virtual void addInput(const char* more);
        virtual std::string& getInput() { return this->formatInput; }
        void clearInput() { this->formatInput.clear(); }
        size_t getSize() { return this->formatInput.size(); } 
    protected:
        std::string formatInput;
};

union inputStream{
    const char* rawBytes;
    const struct input_event* ev;
};
