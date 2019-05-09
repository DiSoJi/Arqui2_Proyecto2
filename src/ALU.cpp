//
// Created by disojivm on 5/8/19.
//

#include <cstdlib>
#include "ALU.h"
#include "mem_ops.cpp"
#include "signals.h"
#include <pthread.h>



class adder{
public:
    char  *input1;
    char  *input2;
    char  *output;
    adder(){
        input1 = (char*)malloc(sizeof(char));
        input2 = (char*)malloc(sizeof(char));
        output = (char*)malloc(sizeof(char));
    };

    void add(){
        *output = *input1 + *input2;
    }


};

class ALU {
public:
    bool* signals;
    reg * output;
    reg * input1;
    reg * input2;
    ALU(){
        signals = (bool *)malloc(4*sizeof(bool));
        input1 = (reg *)malloc((sizeof(reg)));
        input2 = (reg *)malloc((sizeof(reg)));
        output = (reg *)malloc(sizeof(reg));
    }

private:
    adder add_l1;
    adder add_l2;
    adder add_l3;
    adder add_l4;

public:
    char * add_v(){
        //Pass to the 4 lanes the first 4 elements from input1;
        char input1_l1 = (*input1).get_data(0);
        add_l1.input1 = &input1_l1;
        char input1_l2 = (*input1).get_data(1);
        add_l2.input1 = &input1_l2;
        char input1_l3 = (*input1).get_data(2);
        add_l3.input1 = &input1_l3;
        char input1_l4 = (*input1).get_data(3);
        add_l4.input1 = &input1_l4;
        //Operate 4 lanes with first
        char input2_l1 = (*input2).get_data(0);
        add_l1.input2 = &input2_l1;
        char input2_l2 = (*input2).get_data(1);
        add_l2.input2 = &input2_l1;
        char input2_l3 = (*input2).get_data(2);
        add_l3.input2 = &input2_l1;
        char input2_l4 = (*input2).get_data(3);
        add_l4.input2 = &input2_l1;
        //int a = 0;
        //pthread_create(NULL,NULL,(THREADFUNCPTR)add_l1.add(),NULL)
        //pthread_create(a,NULL,add_l1.add(),NULL);
        add_l1.add();
        add_l2.add();
        add_l3.add();
        add_l4.add();
        sigwait( &signal_set, &sig_int);
        

    };
    char * sub_v(char* input, char* output);
    char * mult_v(char* input, char* output);
    char * div_v(char* input, char* output);
    char * xor_v(char* input, char* output);

};