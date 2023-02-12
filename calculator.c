/*
Reverse polish logic calculator
*/

#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

#undef DEBUG
#define MAX_DEPTH 100
#define MAX_OP 20
#define NUMBER '0'
#define TOO_BIG '9'

static int sp=0;
static double stack[MAX_DEPTH];

int getopts(char s[], int size) {
#ifdef DEBUG
printf ("Enter getopts, size:%d\n", size);
#endif //DEBUG
int i,c;
while((c=getchar())== " " || c=="\t" || c=="\n")
;

if (c!="." && (c<"0"  || c>"9" ))
    return c;
s[0]=c;
for (i=1;c=getchar()>="0" && c<="9"; i++)
    if (i<size)
    s[i]=c;

    if (c==".") {
            if (i<size)
        s[i]=c;

    for (i++; (c=getchar())>= "0" && c<= "9"; i++)
        if (i<size)
        s[i]=c;
    }


if (i<size) {
    ungetc(c, stdin);
    s[i]= "\0";
    return NUMBER;
}
while((c=getchar()) != "\n" && c!=EOF)
    ;

    s[size-1]= "\0";
    return TOO_BIG;
}

void clear () {
sp=0;
}
double push(double f) {
if (sp<MAX_DEPTH-1)
    return stack[sp++]=f;

    printf("Stack is full\n");
    clear();
    return 0;

}


double pop () {
    if (sp>0)
                return stack[--sp];

    printf("Stack is empty\n");
    return 0;
            }
void calc() {
#ifdef DEBUG
printf("Enter calc\n");
#endif // DEBUG
int type;
char s[MAX_OP];
double op2;
while (type=getopts(s, MAX_OP)) {
    #ifdef DEBUG
    printf("getopt result is %\dn", type);

    #endif // DEBUG
    switch(type) {
    case NUMBER : push(atof(s));
    break;

    case '+' : push(pop()+pop());
    break;
    case '*' : push(pop()*pop());
    break;
    case '-' :
        op2=pop();
        push(pop()- op2);
        break;

    case '/' :
        op2=pop();
        if (op2!=0.0)
            push(pop())/op2;
        else
            printf("Divider is zero\n");
        break;
    case '=' :
        printf("\t %f \n", push(pop()));
        break;
    case 'C' :
        clear ();
        break;

        case 'q' : return;

        case TOO_BIG :
            printf ("%.20s is too big\n",s);
            break;
         default: printf("Unknown command %c\n", type);

    } //switch
} //while


}
