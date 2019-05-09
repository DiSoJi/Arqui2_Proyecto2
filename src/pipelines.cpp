//
// Created by disojivm on 5/8/19.
//

//#include "pipelines.h"


#include <cstdlib>
#include "signals.h"


class fetch_decode{
public:
    char * input = (char*)malloc(sizeof(char));
    char * output = (char*)malloc(sizeof(char));
    void * pipe(){
        sigwait( &signal_set, &sig_int);
        *output = *input;
    }

};

class pipelines {

};
