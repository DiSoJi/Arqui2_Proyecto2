//
// Reused from Proect 1. Made by Diego, Pablo and Esteban
//
#include "pgm.h"

/**********************File I/O functions*******************************/
/***********************************************************************/

/*Gets an ascii pgm image file, store as a color pgm.*/
Image getPGMfile (char filename[]){
    FILE *in_file;
    char ch;
    int row, col, type;
    int ch_int;
    unsigned char red, green, blue;
    Pixel** res_rows;
    ImgSize size;

    in_file = fopen(filename, "r");
    if (in_file == NULL)
    {
        fprintf(stderr, "Error: Unable to open file %s\n\n", filename);
        exit(8);
    }

    printf("\nReading image file: %s\n", filename);

    /*determine pgm image type (only type three can be used)*/
    ch = getc(in_file);
    if(ch != 'P')
    {
        printf("ERROR(1): Not valid pgm/ppm file type\n");
        exit(1);
    }
    ch = getc(in_file);
    /*convert the one digit integer currently represented as a character to
    an integer(48 == '0')*/
    type = ch - 48;
    if((type != 2) && (type != 3) && (type != 5) && (type != 6))
    {
        printf("ERROR(2): Not valid pgm/ppm file type\n");
        exit(1);
    }

    while(getc(in_file) != '\n');             /* skip to end of line*/

    while (getc(in_file) == '#')              /* skip comment lines */
    {
        while (getc(in_file) != '\n');          /* skip to end of comment line */
    }

    /*there seems to be a difference between color and b/w.  This line is needed
    by b/w but doesn't effect color reading...*/
    fseek(in_file, -1, SEEK_CUR);             /* backup one character*/

    fscanf(in_file,"%d", &size.width);
    fscanf(in_file,"%d", &size.height);
    fscanf(in_file,"%d", &size.y);

    printf("\n width  = %d",size.width);
    printf("\n height = %d",size.height);
    printf("\n maxVal = %d",size.y);
    printf("\n");
    res_rows = (Pixel**) malloc(sizeof(Pixelp) * size.height);
    for(int y = 0; y < size.height; y++) {
        res_rows[y] = (Pixel *)malloc(sizeof(Pixel) * size.width);
    }

    if(type == 2) /*uncompressed ascii file (B/W)*/
    {
        for (row=size.height-1; row >=0; row--)
            for (col=0; col< size.width; col++)
            {
                fscanf(in_file,"%d", &ch_int);
                res_rows[row][col] = ch_int;
            }
    }
    else if(type == 3) /*uncompressed ascii file (color)*/
    {
        for (row=size.height-1; row >=0; row--)
            for (col=0; col< size.width; col++)
            {

                fscanf(in_file,"%d", &ch_int);
                red = (unsigned char)ch_int;

                fscanf(in_file,"%d", &ch_int);
                green = (unsigned char)ch_int;

                fscanf(in_file,"%d", &ch_int);
                blue = (unsigned char)ch_int;
                res_rows[row][col] = (red + green + blue) / 3.0f;
            }
    }
    else if(type == 5) /*compressed file (B/W)*/
        /*note: this type remains untested at this time...*/
    {
        while(getc(in_file) != '\n'); /*skip to end of line*/

        for (row=size.height-1; row >=0; row--)
            for (col=0; col< size.width; col++)
            {
                ch = getc(in_file);
                res_rows[row][col] = ch;
            }
    }

    else if(type == 6) /*compressed file (color)*/
    {
        while(getc(in_file) != '\n'); /*skip to end of line*/

        for (row=size.height-1; row >=0; row--)
            for (col=0; col< size.width; col++)
            {
                red = getc(in_file);
                green = getc(in_file);
                blue = getc(in_file);
                res_rows[row][col] = (red + green + blue) / 3.0f;
            }
    }

    fclose(in_file);
    printf("\nDone reading file.\n");
    Image result = {res_rows, size};
    return result;
}


void save(Image img, char* filename)
{
    int i, j, nr, nc, k;
    int red, green, blue;
    FILE *iop;

    nr = img.size.height;
    nc = img.size.width;

    iop = fopen(filename, "w");
    fprintf(iop, "P6\n");
    fprintf(iop, "%d %d\n", nc, nr);
    fprintf(iop, "255\n");

    k = 1;
    for(i = nr - 1; i  >= 0; i--)
    {
        for(j = 0; j <  nc; j++)
        {
            red = img.Rows[i][j];
            green = img.Rows[i][j];
            blue = img.Rows[i][j];
            if(red <  0)
            {
                printf("IMG_WRITE: Found value %d at row %d col %d\n", red, i, j);
                printf("           Setting red to zero\n");
                red = 0;
            }
            if(green <  0)
            {
                printf("IMG_WRITE: Found value %d at row %d col %d\n", green,i, j);
                printf("           Setting green to zero\n");
                green = 0;
            }
            if(blue <  0)
            {
                printf("IMG_WRITE: Found value %d at row %d col %d\n", blue, i, j);
                printf("           Setting green to zero\n");
                blue = 0;
            }
            if(red  > 255)
            {
                printf("IMG_WRITE: Found value %d at row %d col %d\n", red, i, j);
                printf("           Setting red to 255\n");
                red = 255;
            }
            if(green  > 255)
            {
                printf("IMG_WRITE: Found value %d at row %d col %d\n", green,i, j);
                printf("           Setting green to 255\n");
                green = 255;
            }
            if(blue  > 255)
            {
                printf("IMG_WRITE: Found value %d at row %d col %d\n", blue, i, j);
                printf("           Setting blue to 255\n");
                blue = 255;
            }

            putc(red, iop);
            putc(green, iop);
            putc(blue, iop);
        }
    }
    fprintf(iop, "\n");
    fclose(iop);
}