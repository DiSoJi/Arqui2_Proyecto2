//
// Created by disojivm on 5/7/19.
//

#include <cstdlib>
#include <malloc.h>
#include "mem_ops.h"


class data_mem{
private:
    char* mem;
public:
    data_mem(){
        mem  = (char *)malloc(DATA_MEMORY_SIZE * (sizeof(char)));
    }
    char getmem_element(int address){
        return mem[address];

    };

    void setmem_element(int address, char data){
        mem[address] = data;

    }


};

class reg{
private:
    char* data;
public:

    reg() {
        data = (char*)malloc(REGISTER_SIZE * sizeof(char));
    }


    char get_data(int value_pos){
        return data[value_pos];
    }
    void set_data(int value_pos, char value){
        data[value_pos] = value;
    }

};

class reg_mem{
private:
    reg* regs;
public:


    reg_mem(){
        regs = (reg*)malloc(REGISTER_BANK_SIZE * (sizeof(reg)));
        for (int i = 0; i<REGISTER_BANK_SIZE; i++){
            reg rg;
            regs[i] = rg;
        }
    }

    reg get_register(int reg_name){
        return regs[reg_name];
    }

};

class instr_mem{
private:
    char* mem;
public:
    instr_mem(){
        mem  = (char *)malloc(INSTRUCTION_MEMORY_SIZE * (sizeof(char)));


    }
    char getmem_element(int address){
        return mem[address];

    };

    void setmem_element(int address, char data){
        mem[address] = data;

    }


};
