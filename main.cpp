#include <iostream>

#include "src/mem_ops.cpp"
#include "src/signals.h"
#include <pthread.h>
#include "src/picture_tools.h"

int main() {

    int * threads = (int*)malloc(10*sizeof(int));
    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGCONT);
    sigprocmask(SIG_BLOCK, &signal_set, NULL);

    data_mem Data_Memory; //Data memory instanced
    reg_mem Vectorial_Register_Bank; // Vectorial Register bank instanced (8). TODO Consider moving this into CPU initialization
    instr_mem Instruction_Memory; //Instruction Memory instanced
    Data_Memory.setmem_element(0,'c');
    Instruction_Memory.setmem_element(0,0);

    reg Scalar_Register_Bank; //Scalar Registers (8)
    //char * filename = (char *)"../images/jojomidorya.bmp";
    unsigned char * picture_pixels = readBMP();

    printf("Pixel value: %i \n", picture_pixels[5]);

    FILE* f1 = fopen("/home/disojivm/Documents/Git_Repos/Arqui2_Proyecto2/Arqui2_Proyecto2/images/reBuilded.bmp","w+");
    //fclose(f1);
    printf("After open: \n");
    fwrite(picture_pixels, sizeof(unsigned char*), 250000,f1);
    printf("After write: \n");
    fclose(f1);
    return 0;
}


