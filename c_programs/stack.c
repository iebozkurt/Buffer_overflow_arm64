/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* This function have a overflow problem */
void scpy(char *to, char *from){
    unsigned long temp, *fr, *t;
    fr = (unsigned long*)(from);
    t =  (unsigned long*)(to);
    int i=0;

    do {
        temp = fr[i];
        t[i] = temp;
        if( temp==0) break;
        i++;
    } while(temp != 0);
}

int bof(char *str)
{
    char buffer[12];
    /* The following statement has a buffer overflow problem */
    scpy(buffer, str);
    return 1;
}
int callThis(char *st){
return bof(st);

}
int callThat(char *s){
return callThis(s);
}
int main(int argc, char **argv)
{
    char str[517];
    FILE *badfile;

    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 517, badfile);
        callThis(str);
printf("Returned Properly\n");
return 1;
}
