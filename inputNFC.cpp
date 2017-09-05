#include "inputNFC.hpp" 

inputDecoder::~inputDecoder() {}

/*****************************/
/* inputDecoder::addInput()  */
/*****************************/

/**
    inputDecoder::addInput()

    Uses input from Elatec device to generate human readable RFID/NFC ID 

    @author Christof Groschke
    @version 1.0 02.08.2017
*/


void inputDecoder::addInput(const char* more)
{
    union inputStream i;
    size_t current = 0;
    
    i.rawBytes = more;
    
    try{
        if (i.ev->type == EV_KEY && i.ev->value == 0){
                
            switch(i.ev->code){
                case KEY_1:
                    this->formatInput += "1";
                    break;
                case KEY_2:
                    this->formatInput += "2";
                    break;
                case KEY_3:
                    this->formatInput += "3";
                    break;
                case KEY_4:
                    this->formatInput += "4";
                    break;
                case KEY_5:
                    this->formatInput += "5";
                    break;
                case KEY_6:
                    this->formatInput += "6";
                    break;
                case KEY_7:
                    this->formatInput += "7";
                    break;
                case KEY_8:
                    this->formatInput += "8";
                    break;
                case KEY_9:
                    this->formatInput += "9";
                    break;
                case KEY_0:
                    this->formatInput += "0";
                    break;
                case KEY_A:
                    this->formatInput += "A";
                    break;
                case KEY_B:
                    this->formatInput += "B";
                    break;    
                case KEY_C:
                    this->formatInput += "C";
                    break;    
                case KEY_D:
                    this->formatInput += "D";
                    break;
                case KEY_E:
                    this->formatInput += "E";
                    break;
                case KEY_F:
                    this->formatInput += "F";
                    /*falltrough*/                       
            }
                
                /* all other inputs are simple ignored and disgarded if you need more inherent */              
                
        }
    }
    catch(...) {
        std::cerr << "Error in reading input stream, truncate input and continue" << std::endl;
        this->clearInput();
    }
}
