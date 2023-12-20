#include "main.h"

char *_strtok(char *str, const char *sep) 
{
    static char *lastToken = NULL;
    char *tokenStart;

    if (str != NULL) {
        lastToken = str;
    } else {
        if (lastToken == NULL) {
            return NULL;
        }
    }

    lastToken += strspn(lastToken, sep);

    if (*lastToken == '\0') {
        lastToken = NULL;
        return NULL;
    }

    tokenStart = lastToken;

    
    lastToken += strcspn(lastToken, sep);

    
    if (*lastToken != '\0') {
        *lastToken = '\0';
        lastToken++;
    } else {
        
        lastToken = NULL;
    }

    return tokenStart;
}
