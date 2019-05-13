//
// Created by disojivm on 5/7/19.
//

#include <cstdlib>
#include <malloc.h>
#include "mem_ops.h"

#include <fstream>
#include <iostream>
#include <string>
#include <array>

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

class scalar_mem{
public:

    int* data;
    scalar_mem(){
        data = (int*)malloc(REGISTER_BANK_SIZE * sizeof(int));
    };
    int get_data(int value_pos){
        return data[value_pos];
    }
    void set_data(int value_pos, int value){
        data[value_pos] = value;
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

    char WE;
    int values;
    reg *WData;
    reg_mem(){
        WE = 0;
        values = 0;
        WData = new(reg);
        regs = (reg*)malloc(REGISTER_BANK_SIZE * (sizeof(reg)));
        for (int i = 0; i<REGISTER_BANK_SIZE; i++){
            reg* rg = new reg();
            regs[i] = *rg;
            free(rg);
        }
    }

    reg* get_register(int reg_name1,int reg_name2){
        reg outputregs[2] = {regs[reg_name1],regs[reg_name2]};
        return outputregs;
    }
    void set_WE(char value){
        WE = value;
    }
    void set_register(int reg_name1){ //This function uses a state machine to choose which positions to fill
        if (WE == 0) WE = 0;
        if (WE == 1) regs[reg_name1] = *WData;
        if (WE == 2) {
            regs[reg_name1].set_data(0,(values<<8)>>8);
            regs[reg_name1].set_data(1,(values)>>8);
        }
        if (WE == 3) {
            regs[reg_name1].set_data(2,(values<<8)>>8);
            regs[reg_name1].set_data(3,(values)>>8);
        }
        if (WE == 4) {
            regs[reg_name1].set_data(4,(values<<8)>>8);
            regs[reg_name1].set_data(5,(values)>>8);
        }
        if (WE == 5) {
            regs[reg_name1].set_data(6,(values<<8)>>8);
            regs[reg_name1].set_data(7,(values)>>8);
        }
    }

};

class instr_mem{
private:
    int* mem;
    int address;
public:
    instr_mem(){
        address = 0;
        mem  = (int *)malloc(INSTRUCTION_MEMORY_SIZE * (sizeof(int)));
        std::ifstream file("/home/disojivm/Documents/Git_Repos/Arqui2_Proyecto2/Arqui2_Proyecto2/codes/xor_code.txt");
        if (file.is_open()) {
            std::string line;
            int i=0;
            while (getline(file, line)) {
                mem[i]=std::stoi(line.c_str(),nullptr,2);
                i++;
            }
            file.close();
        }

    }
    int getmem_element(){
        return mem[address];

    };

};
