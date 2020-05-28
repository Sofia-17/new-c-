#include "io.h"
#include <stdio.h>
#include <stdlib.h>
int getTotalLines (FILE* fp) {
    char ch;
    int lines = 0;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }

    }
} // считаем колво строк