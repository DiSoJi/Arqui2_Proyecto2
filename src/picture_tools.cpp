//
// Created by disojivm on 5/9/19.
//

#include <cstdio>
#include <cstdlib>
#include "picture_tools.h"


unsigned char* readBMP()
{
    //int i;
    printf("Before open \n");
    FILE* f = fopen("../images/jojomidorya.bmp", "rb");
    /*unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    printf("Width: %i  \n", width);
    int height = *(int*)&info[22];
    printf("Height: %i  \n", height);*/

    //int size = -1 * width * height;
    int size = 500 * 500;
    printf("Before Malloc: %i  \n", size);
    unsigned char* data = (unsigned char*) malloc(size); // allocate 1 bytes per pixel
    printf("After Malloc: %i \n", data);
    fread(data, sizeof(unsigned char*), size, f); // read the rest of the data at once
    //printf("After read data: %i \n", data[500000]);
    fclose(f);
    printf("After close \n");
/*
    for(i = 0; i < size; i += 3)
    {
        unsigned char tmp = data[i];
        data[i] = data[i+2];
        data[i+2] = tmp;
    }*/

    return data;
}