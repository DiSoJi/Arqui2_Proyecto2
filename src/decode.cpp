//
// Created by disojivm on 5/10/19.
//

#include "decode.h"
#include "mem_ops.cpp"


class control_unit{
public:


};




class fetch_decode_pipe{
public:
    int instruction;
    int scalar_value;
    char opCode;
    //REGV
    char regA, regB, regWR, scalreg;


public:
    fetch_decode_pipe(){
        instruction = 0;
        opCode = 0;
        regA = 0;
        regB = 0;
        regWR = 0;
        scalreg = 0;
        scalar_value = 0;
    }
    void setInst(int instr){
        instruction = instr;
    };

    void fetch_decode_pass(){
        opCode = (instruction)>>24;
        regA= (instruction<<12)>>28;
        regB= (instruction<<16)>>28;
        regWR= (instruction<<8)>>28;
        scalreg = regB;
        scalar_value= (instruction<<16)>>16;
    }
};


