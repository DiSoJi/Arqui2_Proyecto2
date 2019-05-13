//
// Created by disojivm on 5/12/19.
//

#include "image.h"

void free_image(Image image){
    for(int y = 0; y < image.size.height; y++) {
        free( image.Rows[y]);
    }
    free(image.Rows);
}

Pixel get_pixel(Image image,int x, int y){
    return image.Rows[y][x];
}

void set_pixel(Image image, int x, int y, Pixel val){
    image.Rows[y][x] = val;
}

Image clone(Image image){
    //Reserve memory
    Pixelp * res_rows = (Pixelp*) malloc(sizeof(Pixelp) * image.size.height);
    for(int y = 0; y < image.size.height; y++) {
        res_rows[y] = (Pixel *)malloc(sizeof(Pixel) * image.size.width);
    }

    for(int y = 0; y < image.size.height; y++) {
        memcpy(res_rows[y],image.Rows[y], image.size.width);
    }

    Image result = {res_rows, image.size};
    return result;
}