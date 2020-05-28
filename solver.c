#include "solver.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#define bufLen 8192
int solve (const char* line, int len, char** answer ) {
    // 1. Реализовать через два указателя (i, j) 
    // '.', ',', ' '
    int i = 0;
    int j = 0;
    int l = -1;
    int lineLen = strlen(line);
    for(i=0; i < lineLen; i=j) {
        while(i < lineLen && (line[i] == '.' || line[i] == ',' || line[i] == ' ')){
            i++; 
        }
            j = i;
        for(j = i; j < lineLen && ( line[j] != ',' && line[j] != '.' && line[j] != ' '); j++) 
           
        if (i < j) { 
            l = j - i; 
            if(startsWithChar(line,i,'A') > 0 && isEnglishUpperCaseCharsOnly(line,i,l) > 0 && l > len) {
                if (*answer != NULL) { 
                    free(*answer);
                }
                
                *answer = malloc((l + 1) *sizeof(char));
                strncpy((*answer),line + i,l); //копируем слово line[i],line[i+1].... до j - 1 в answer
                (*answer)[l] = '\0';
                len = l;
            }
            i = j;
        }
        
    }  
    return 0;     
}

int search(const char* fileInput, char** answer) {
    FILE* fin = fopen(fileInput, "r");
    if (fin == NULL)
        return -1;
    char line[bufLen + 1];
    int bestLen = -1;
    while (fgets(line , sizeof(line), fin) != NULL) { 
        solve(line, bestLen, answer);
        bestLen = strlen(*answer); // после обработанной строки обновляем луший ответ
    }
    fclose(fin);
    return 0;
}
