//
// Reused from Proect 1. Made by Diego, Pablo and Esteban
//

#ifndef PGM_H
#define PGM_H

#include <stdio.h>
#include <stdlib.h>
#include "image.h"


/***prototypes**********************************************************/
/***********************************************************************/

Image getPGMfile (char filename[]);
void save(Image img, char* filename);

#endif