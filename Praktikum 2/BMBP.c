#include <stdio.h>
#include <string.h>

int main() {
    char wibubawang[101][101];
    int i=0;
    do {
        gets(wibubawang[i]);
        i++;
    } while (strcmp(wibubawang[i-1],"Bawang Merah")!=0 && strcmp(wibubawang[i-1],"Bawang Putih")!=0);
    i--;
    int p;
    for(p=0;p<i; p++) {
        int hadehhhh;
        for(hadehhhh=0; hadehhhh<strlen(wibubawang[p]); hadehhhh++){
            if(wibubawang[p][hadehhhh]>='A' && wibubawang[p][hadehhhh]<='Z') {
                wibubawang[p][hadehhhh]=wibubawang[p][hadehhhh]-'A'+'a';
            }
        }
    }
    char bawangmauapa[101];
    strcpy(bawangmauapa,wibubawang[0]);
    if(strcmp(wibubawang[i],"Bawang Merah")==0) {
        int j;
        for(j=1; j<i; j++) {
            if(strcmp(bawangmauapa,wibubawang[j])>0) {
                strcpy(bawangmauapa,wibubawang[j]);
            }
        }
    } else {
        int j;
        for(j=1; j<i; j++) {
            if(strcmp(bawangmauapa,wibubawang[j])<0) {
                strcpy(bawangmauapa,wibubawang[j]);
            }
        }
    }
    puts(bawangmauapa);

    return 0;
}