#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
    printf("Checking the parentheses in argv arguments\n");

    int i, j;
    char c;
    Stack s;
    s.size = 0;
    s.top = NULL;

    for (i=1; i < argc; i++) {
        for (j=0; j < strlen(argv[i]) && j != -1; j++) {
            c = argv[i][j];
            switch(c) {
                case '{':
                case '[': push(&s, c); break;

                case ']':
                    if (pop(&s) != '[') j = -2;
                    break;
                case '}':
                    if (pop(&s) != '{') j = -2;
                    break;
            }
        }
        if (s.size != 0 || j < 0)
            printf("The parentheses do not match for %s\n", argv[i]);
        else
            printf("The parentheses match successfully for %s\n", argv[i]);
        pop_all(&s);
    }
    return 0;
}
