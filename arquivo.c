#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file;
    file=fopen("teste.txt","r");

    if (file==NULL) {
        printf("Erro\n");
        return 0;
    }

    char a[50]; int c=0;

    while(!feof(file)){

        fscanf(file, "%s", a);
        strlwr(a);
        c = strlen(a);
        for(int i=0;i<c;i++){
            if(ispunct(a[i]))
                a[i]=NULL;
        }
        c=strlen(a);
        printf("%s %d\n", a,c);

    }

    fclose(file);

    return 0;
}
