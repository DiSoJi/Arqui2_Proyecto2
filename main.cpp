#include <iostream>

//#include "src/mem_ops.cpp"
//#include "src/signals.h"
//#include <pthread.h>
#include "src/picture_tools.h"
#include "src/ALU.cpp"
#include "src/image.h"
#include "src/pgm.h"
int main() {

    /*
    int * threads = (int*)malloc(10*sizeof(int));
    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGCONT);
    sigprocmask(SIG_BLOCK, &signal_set, NULL);*/

    data_mem Data_Memory;
    reg_mem Vectorial_Register_Bank;
    instr_mem Instruction_Memory;
    reg Scalar_Register_Bank;

    Image imgRaw = getPGMfile("/home/disojivm/Documents/Git_Repos/Arqui2_Proyecto2/Arqui2_Proyecto2/images/jojomidorya.pgm");

    //Load Picture:
    unsigned char * picture_pixels = readBMP();
    //



    //##########################Fetch Cycle###################################


    //##########################Decode Cycle##################################


    //##########################Execute Cycle#################################

    //##########################Memory Cycle##################################

    //##########################write Back Cycle##############################



    //Save Picture:
    FILE* f1 = fopen("/home/disojivm/Documents/Git_Repos/Arqui2_Proyecto2/Arqui2_Proyecto2/images/reBuilded.bmp","w+");
    fwrite(picture_pixels, 1, PICTURE_SIZE,f1);
    fclose(f1);

/*
    data_mem Data_Memory; //Data memory instanced
    reg_mem Vectorial_Register_Bank; // Vectorial Register bank instanced (8). TODO Consider moving this into CPU initialization
    instr_mem Instruction_Memory; //Instruction Memory instanced
    Data_Memory.setmem_element(0,'c');
    Instruction_Memory.setmem_element(0,0);
*/
/*
    reg Scalar_Register_Bank; //Scalar Registers (8)
    //char * filename = (char *)"../images/jojomidorya.bmp";
    unsigned char * picture_pixels = readBMP();

    printf("Pixel value: %i \n", picture_pixels[5]);

    FILE* f1 = fopen("/home/disojivm/Documents/Git_Repos/Arqui2_Proyecto2/Arqui2_Proyecto2/images/reBuilded.bmp","w+");
    //fclose(f1);
    printf("After open: \n");
    fwrite(picture_pixels, 1, PICTURE_SIZE,f1);
    printf("After write: \n");
    fclose(f1);*/
/*
    reg* a = new reg();
    a->set_data(0,1);
    a->set_data(1,2);
    a->set_data(2,3);
    a->set_data(3,4);
    a->set_data(4,5);
    a->set_data(5,6);
    a->set_data(6,7);
    a->set_data(7,8);
    reg* b = new reg();
    b->set_data(0,2);
    b->set_data(1,3);
    b->set_data(2,4);
    b->set_data(3,5);
    b->set_data(4,6);
    b->set_data(5,7);
    b->set_data(6,8);
    b->set_data(7,9);

    printf("Add: \n");
    ALU* alu = new ALU();
    alu->input1 = a;
    alu->input2 = b;
    alu->add_v();

    for (int i = 0; i<8; i++){
        printf("Value %i is: %i \n",i, alu->output->get_data(i));
    }
    printf("Subs: \n");
    alu->subs_v();

    for (int i = 0; i<8; i++){
        printf("Value %i is: %i \n",i, alu->output->get_data(i));
    }
    printf("XORs: \n");
    alu->xor_v();

    for (int i = 0; i<8; i++){
        printf("Value %i is: %i \n",i, alu->output->get_data(i));
    }
*/
    return 0;
}


