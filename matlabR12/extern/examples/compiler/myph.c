/*
 * $Revision: 1.3 $
 */

#include "matlab.h"
#include "mr_external.h"


/* print handler function */ 
static void myPrintHandler(const char *s) 
{ 
    printf("%s\n", s); 
}

/* print handler initialization function */ 
void Mmr_initprnt(void) 
{ 
    /* Establish myPrintHandler as the print handler routine. */ 
    mlfSetPrintHandler(myPrintHandler);
 } 

