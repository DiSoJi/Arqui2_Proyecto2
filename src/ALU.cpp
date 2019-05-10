//
// Created by disojivm on 5/8/19.
//

#include <cstdlib>
#include "ALU.h"
#include "mem_ops.cpp"
#include "signals.h"
#include <pthread.h>
#include <omp.h>
#include <sys/wait.h>


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

    void operate(){
        *output = *input1 + *input2;
    }


};

class subber{
public:
    char  *input1;
    char  *input2;
    char  *output;
    subber(){
        input1 = (char*)malloc(sizeof(char));
        input2 = (char*)malloc(sizeof(char));
        output = (char*)malloc(sizeof(char));
    };

    void operate(){
        *output = *input1 - *input2;
    }


};

class xorer{
public:
    char  *input1;
    char  *input2;
    char  *output;
    xorer(){
        input1 = (char*)malloc(sizeof(char));
        input2 = (char*)malloc(sizeof(char));
        output = (char*)malloc(sizeof(char));
    };

    void operate(){
        *output = (*input1) ^ (*input2);
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
        input1 = new reg();
        input2 = new reg();
        output = new reg();
    }

private:
    //Four adders
    adder add_l1;
    adder add_l2;
    adder add_l3;
    adder add_l4;
    //Four substractors
    subber sub_l1;
    subber sub_l2;
    subber sub_l3;
    subber sub_l4;
    //Four XOR doers
    xorer xor_l1;
    xorer xor_l2;
    xorer xor_l3;
    xorer xor_l4;

public:
    void add_v(){
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
        add_l2.input2 = &input2_l2;
        char input2_l3 = (*input2).get_data(2);
        add_l3.input2 = &input2_l3;
        char input2_l4 = (*input2).get_data(3);
        add_l4.input2 = &input2_l4;
        //int a = 0;
        //pthread_create(NULL,NULL,(THREADFUNCPTR)add_l1.add(),NULL)
        //pthread_create(a,NULL,add_l1.add(),NULL);
        //omp_set_num_threads(4);
        #pragma omp parallel
        {
            add_l1.operate();
            add_l2.operate();
            add_l3.operate();
            add_l4.operate();

        }
        //wait(reinterpret_cast<int *>(1));
        #pragma omp parallel
        {
            (*output).set_data(0, *add_l1.output);
            (*output).set_data(1, *add_l2.output);
            (*output).set_data(2, *add_l3.output);
            (*output).set_data(3, *add_l4.output);
        }
        //printf("Before wait");
        //sigwait( &signal_set, &sig_int);

        input1_l1 = (*input1).get_data(4);
        add_l1.input1 = &input1_l1;
        input1_l2 = (*input1).get_data(5);
        add_l2.input1 = &input1_l2;
        input1_l3 = (*input1).get_data(6);
        add_l3.input1 = &input1_l3;
        input1_l4 = (*input1).get_data(7);
        add_l4.input1 = &input1_l4;
        //Operate 4 lanes with first
        input2_l1 = (*input2).get_data(4);
        add_l1.input2 = &input2_l1;
        input2_l2 = (*input2).get_data(5);
        add_l2.input2 = &input2_l2;
        input2_l3 = (*input2).get_data(6);
        add_l3.input2 = &input2_l3;
        input2_l4 = (*input2).get_data(7);
        add_l4.input2 = &input2_l4;

        #pragma omp parallel
        {
            add_l1.operate();
            add_l2.operate();
            add_l3.operate();
            add_l4.operate();
        }

        #pragma omp parallel
        {
            output->set_data(4, *add_l1.output);
            output->set_data(5, *add_l2.output);
            output->set_data(6, *add_l3.output);
            output->set_data(7, *add_l4.output);
        }

    };
    void subs_v(){
        //Pass to the 4 lanes the first 4 elements from input1;
        char input1_l1 = (*input1).get_data(0);
        sub_l1.input1 = &input1_l1;
        char input1_l2 = (*input1).get_data(1);
        sub_l2.input1 = &input1_l2;
        char input1_l3 = (*input1).get_data(2);
        sub_l3.input1 = &input1_l3;
        char input1_l4 = (*input1).get_data(3);
        sub_l4.input1 = &input1_l4;
        //Operate 4 lanes with first
        char input2_l1 = (*input2).get_data(0);
        sub_l1.input2 = &input2_l1;
        char input2_l2 = (*input2).get_data(1);
        sub_l2.input2 = &input2_l2;
        char input2_l3 = (*input2).get_data(2);
        sub_l3.input2 = &input2_l3;
        char input2_l4 = (*input2).get_data(3);
        sub_l4.input2 = &input2_l4;
        //int a = 0;
        //pthread_create(NULL,NULL,(THREADFUNCPTR)add_l1.add(),NULL)
        //pthread_create(a,NULL,add_l1.add(),NULL);
        //omp_set_num_threads(4);
#pragma omp parallel
        {
            sub_l1.operate();
            sub_l2.operate();
            sub_l3.operate();
            sub_l4.operate();

        }
        //wait(reinterpret_cast<int *>(1));
#pragma omp parallel
        {
            (*output).set_data(0, *sub_l1.output);
            (*output).set_data(1, *sub_l2.output);
            (*output).set_data(2, *sub_l3.output);
            (*output).set_data(3, *sub_l4.output);
        }
        //printf("Before wait");
        //sigwait( &signal_set, &sig_int);

        input1_l1 = (*input1).get_data(4);
        sub_l1.input1 = &input1_l1;
        input1_l2 = (*input1).get_data(5);
        sub_l2.input1 = &input1_l2;
        input1_l3 = (*input1).get_data(6);
        sub_l3.input1 = &input1_l3;
        input1_l4 = (*input1).get_data(7);
        sub_l4.input1 = &input1_l4;
        //Operate 4 lanes with first
        input2_l1 = (*input2).get_data(4);
        sub_l1.input2 = &input2_l1;
        input2_l2 = (*input2).get_data(5);
        sub_l2.input2 = &input2_l2;
        input2_l3 = (*input2).get_data(6);
        sub_l3.input2 = &input2_l3;
        input2_l4 = (*input2).get_data(7);
        sub_l4.input2 = &input2_l4;

#pragma omp parallel
        {
            sub_l1.operate();
            sub_l2.operate();
            sub_l3.operate();
            sub_l4.operate();
        }

#pragma omp parallel
        {
            output->set_data(4, *sub_l1.output);
            output->set_data(5, *sub_l2.output);
            output->set_data(6, *sub_l3.output);
            output->set_data(7, *sub_l4.output);
        }

    };
    void xor_v(){
        //Pass to the 4 lanes the first 4 elements from input1;
        char input1_l1 = (*input1).get_data(0);
        xor_l1.input1 = &input1_l1;
        char input1_l2 = (*input1).get_data(1);
        xor_l2.input1 = &input1_l2;
        char input1_l3 = (*input1).get_data(2);
        xor_l3.input1 = &input1_l3;
        char input1_l4 = (*input1).get_data(3);
        xor_l4.input1 = &input1_l4;
        //Operate 4 lanes with first
        char input2_l1 = (*input2).get_data(0);
        xor_l1.input2 = &input2_l1;
        char input2_l2 = (*input2).get_data(1);
        xor_l2.input2 = &input2_l2;
        char input2_l3 = (*input2).get_data(2);
        xor_l3.input2 = &input2_l3;
        char input2_l4 = (*input2).get_data(3);
        xor_l4.input2 = &input2_l4;
        //int a = 0;
        //pthread_create(NULL,NULL,(THREADFUNCPTR)add_l1.add(),NULL)
        //pthread_create(a,NULL,add_l1.add(),NULL);
        //omp_set_num_threads(4);
#pragma omp parallel
        {
            xor_l1.operate();
            xor_l2.operate();
            xor_l3.operate();
            xor_l4.operate();

        }
        //wait(reinterpret_cast<int *>(1));
#pragma omp parallel
        {
            (*output).set_data(0, *xor_l1.output);
            (*output).set_data(1, *xor_l2.output);
            (*output).set_data(2, *xor_l3.output);
            (*output).set_data(3, *xor_l4.output);
        }
        //printf("Before wait");
        //sigwait( &signal_set, &sig_int);

        input1_l1 = (*input1).get_data(4);
        xor_l1.input1 = &input1_l1;
        input1_l2 = (*input1).get_data(5);
        xor_l2.input1 = &input1_l2;
        input1_l3 = (*input1).get_data(6);
        xor_l3.input1 = &input1_l3;
        input1_l4 = (*input1).get_data(7);
        xor_l4.input1 = &input1_l4;
        //Operate 4 lanes with first
        input2_l1 = (*input2).get_data(4);
        xor_l1.input2 = &input2_l1;
        input2_l2 = (*input2).get_data(5);
        xor_l2.input2 = &input2_l2;
        input2_l3 = (*input2).get_data(6);
        xor_l3.input2 = &input2_l3;
        input2_l4 = (*input2).get_data(7);
        xor_l4.input2 = &input2_l4;

#pragma omp parallel
        {
            xor_l1.operate();
            xor_l2.operate();
            xor_l3.operate();
            xor_l4.operate();
        }

#pragma omp parallel
        {
            output->set_data(4, *xor_l1.output);
            output->set_data(5, *xor_l2.output);
            output->set_data(6, *xor_l3.output);
            output->set_data(7, *xor_l4.output);
        }

    };

};