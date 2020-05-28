#include "utils.h"
int startsWithChar(const char* line,int startPos, char sym) {
    if(line[startPos] == sym) 
        return 1;
    return 0;

    
}

int isEnglishUpperCaseCharsOnly(const char* line,int startPos, int len) {
    int i;
    for(i = 0;i < len; i++) {
        if(!(line[startPos + i] >= 'A' && line[startPos + i] <= 'Z'))
            return 0;
    }
    return 1;  
}
