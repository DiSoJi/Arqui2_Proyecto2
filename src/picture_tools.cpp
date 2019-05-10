//
// Created by disojivm on 5/9/19.
//

#include <cstdio>
#include <cstdlib>
#include "picture_tools.h"


unsigned char* readBMP()
{
    printf("Before open \n");
    FILE* f = fopen("../images/jojomidorya.bmp", "rb");

    int size = PICTURE_SIZE;
    printf("Before Malloc: %i  \n", size);
    unsigned char* data = (unsigned char*) malloc(size); // allocate 1 bytes per pixel
    printf("After Malloc: %i \n", data);
    fread(data, sizeof(unsigned char*), size, f); // read the rest of the data at once
    //printf("After read data: %i \n", data[500000]);
    fclose(f);
    printf("After close \n");


    return data;
}