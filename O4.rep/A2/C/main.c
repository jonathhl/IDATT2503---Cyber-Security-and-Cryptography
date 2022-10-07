#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replaceWord(const char* s, const char* oldW, const char* newW);

int main() {
    char str[] = "&lorem ipsum <testetsttets > <<<";
    char c[] = "&";
    char d[] = "&amp";
    char l[] = "<";
    char f[] = "&lt";
    char o[] = ">";
    char p[] = "&gt";

    char* output = NULL;

    printf("Old string: %s\n", str);

    output = replaceWord(str, c, d);
    output = replaceWord(output, l, f);
    output = replaceWord(output, o, p);

    printf("New string: %s", output);
    free(output);
    return 0;
}

char* replaceWord(const char* s, const char* oldW, const char* newW) {
    char* output;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    for(i = 0; s[i] != '\0'; i++) {
        if(strstr(&s[i], oldW) == &s[i]) {
            cnt++;
            i+= oldWlen -1;
        }
    }

    output = (char*) malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while(*s) {
        if(strstr(s, oldW) == s) {
            strcpy(&output[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else output[i++] = *s++;
    }

    output[i] = '\0';
    return output;
}
