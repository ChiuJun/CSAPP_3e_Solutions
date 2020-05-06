#include <stdio.h>
#include <string.h>

void good_echo(void){
    const int num = 10;
    char str[num];
    while (fgets(str,num,stdin)!=NULL){
        printf("%s",str);
        if (str[strlen(str)-1]=='\n')
            break;
    }
}

int main(void){
    good_echo();

    return 0;
}