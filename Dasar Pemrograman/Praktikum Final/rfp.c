#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define cmp(q,y) strcmp(q,y)==0
#define less(q,y) strcmp(q,y)<0
#define more(q,y) strcmp(q,y)>0

typedef struct Card {
    char nama[100], typecard[100], typemonster[100], description[100], linkmarker[100], attribute[100];
    int star, rank, overlayunit, link, scale, defense, attack;
}card;

void swap(card * a, card * b) {
    card c = *a;
    *a = *b;
    *b = c;
}

void sortbyname(card a[], int n) {
    bool sorted = false;
    while(!sorted) {
        int i;
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(more(a[i].nama, a[i+1].nama)) {
                sorted = false;
                swap(&a[i], &a[i+1]);
            }
        }
    }
}

void sortbyou(card a[], int n) {
    bool sorted = false;
    while(!sorted) {
        int i;
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(a[i].overlayunit < a[i+1].overlayunit) {
                sorted = false;
                swap(&a[i], &a[i+1]);
            } else if(a[i].overlayunit == a[i+1].overlayunit) {
                if(more(a[i].nama, a[i+1].nama)) {
                    sorted = false;
                    swap(&a[i], &a[i+1]);
                }
            }
        }
    }
}

void sortbystar(card a[], int n) {
    bool sorted = false;
    while(!sorted) {
        int i;
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(a[i].star < a[i+1].star) {
                sorted = false;
                swap(&a[i], &a[i+1]);
            } else if(a[i].star == a[i+1].star) {
                if(more(a[i].nama, a[i+1].nama)) {
                    sorted = false;
                    swap(&a[i], &a[i+1]);
                }
            }
        }
    }
}

void sortbyrank(card a[], int n) {
    bool sorted = false;
    while(!sorted) {
        int i;
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(a[i].rank < a[i+1].rank) {
                sorted = false;
                swap(&a[i], &a[i+1]);
            } else if(a[i].rank == a[i+1].rank) {
                if(more(a[i].nama, a[i+1].nama)) {
                    sorted = false;
                    swap(&a[i], &a[i+1]);
                }
            }
        }
    }
}

void sortbylink(card a[], int n) {
    bool sorted = false;
    while(!sorted) {
        int i;
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(a[i].link < a[i+1].link) {
                sorted = false;
                swap(&a[i], &a[i+1]);
            } else if(a[i].link == a[i+1].link) {
                if(more(a[i].nama, a[i+1].nama)) {
                    sorted = false;
                    swap(&a[i], &a[i+1]);
                }
            }
        }
    }
}

void sortbyscale(card a[], int n) {
    bool sorted = false;
    while(!sorted) {
        int i;
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(a[i].scale < a[i+1].scale) {
                sorted = false;
                swap(&a[i], &a[i+1]);
            } else if(a[i].scale == a[i+1].scale) {
                if(more(a[i].nama, a[i+1].nama)) {
                    sorted = false;
                    swap(&a[i], &a[i+1]);
                }
            }
        }
    }
}

void sortbydef(card a[], int n) {
    bool sorted = false;
    while(!sorted) {
        int i;
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(a[i].defense < a[i+1].defense) {
                sorted = false;
                swap(&a[i], &a[i+1]);
            } else if(a[i].defense == a[i+1].defense) {
                if(more(a[i].nama, a[i+1].nama)) {
                    sorted = false;
                    swap(&a[i], &a[i+1]);
                }
            }
        }
    }
}

void sortbyatt(card a[], int n) {
    bool sorted = false;
    while(!sorted) {
        int i;
        sorted = true;
        for(i=0; i<n-1; i++) {
            if(a[i].attack < a[i+1].attack) {
                sorted = false;
                swap(&a[i], &a[i+1]);
            } else if(a[i].attack == a[i+1].attack) {
                if(more(a[i].nama, a[i+1].nama)) {
                    sorted = false;
                    swap(&a[i], &a[i+1]);
                }
            }
        }
    }
}

int main() {
    card kartu[120];
    int n, i;
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++) {
        gets(kartu[i].nama);
        scanf("%s", kartu[i].typecard);
        getchar();
        if(cmp(kartu[i].typecard, "Normal")
        || cmp(kartu[i].typecard, "Fusion")
        || cmp(kartu[i].typecard, "Synchro")) {
            scanf("%d", &kartu[i].star);
            scanf("%d", &kartu[i].defense);
            scanf("%d", &kartu[i].attack);
            scanf("%s", kartu[i].attribute);
            getchar();
            gets(kartu[i].typemonster);
            gets(kartu[i].description);
            kartu[i].rank = INT_MIN;
            kartu[i].overlayunit = INT_MIN;
            kartu[i].link = INT_MIN;
            kartu[i].linkmarker[0] = '\0';
            kartu[i].scale = INT_MIN;
        } else if(cmp(kartu[i].typecard, "XYZ")) {
            scanf("%d", &kartu[i].rank);
            scanf("%d", &kartu[i].overlayunit);
            scanf("%d", &kartu[i].defense);
            scanf("%d", &kartu[i].attack);
            scanf("%s %s", kartu[i].attribute, kartu[i].typemonster);
            getchar();
            gets(kartu[i].description);
            kartu[i].star = INT_MIN;
            kartu[i].link = INT_MIN;
            kartu[i].linkmarker[0] = '\0';
            kartu[i].scale = INT_MIN;
        } else if(cmp(kartu[i].typecard, "Pendullum")) {
            scanf("%d", &kartu[i].star);
            scanf("%d", &kartu[i].scale);
            scanf("%d", &kartu[i].defense);
            scanf("%d", &kartu[i].attack);
            scanf("%s", kartu[i].attribute);
            getchar();
            gets(kartu[i].typemonster);
            gets(kartu[i].description);
            kartu[i].rank = INT_MIN;
            kartu[i].overlayunit = INT_MIN;
            kartu[i].link = INT_MIN;
            kartu[i].linkmarker[0] = '\0';
        } else if(cmp(kartu[i].typecard, "Link")) {
            scanf("%d", &kartu[i].link);
            getchar();
            gets(kartu[i].linkmarker);
            scanf("%d", &kartu[i].attack);
            scanf("%s", kartu[i].attribute);
            getchar();
            gets(kartu[i].typemonster);
            gets(kartu[i].description);
            kartu[i].star = INT_MIN;
            kartu[i].rank = INT_MIN;
            kartu[i].overlayunit = INT_MIN;
            kartu[i].scale = INT_MIN;
            kartu[i].defense = INT_MIN;
        } else if(cmp(kartu[i].typecard, "Trap")
        || cmp(kartu[i].typecard, "Spell")) {
            gets(kartu[i].description);
            kartu[i].star = INT_MIN;
            kartu[i].rank = INT_MIN;
            kartu[i].overlayunit = INT_MIN;
            kartu[i].link = INT_MIN;
            kartu[i].linkmarker[0] = '\0';
            kartu[i].scale = INT_MIN;
            kartu[i].defense = INT_MIN;
            kartu[i].attack = INT_MIN;
            kartu[i].attribute[0] = '\0';
        } 
        int j = i;
        while (less(kartu[j].nama, kartu[j-1].nama) && i > 0) {
            swap(&kartu[j], &kartu[j-1]);
            j--;
        }
    }
    
    char query[50];
    while (scanf("%s", query)) {
        getchar();
        if(cmp(query, "END")) break;
        else if(cmp(query, "Where")) {
            char q2[50];
            scanf("%s", q2);
            bool ada = false;
            getchar();
            if(strcmp(q2, "Star") == 0) {
                int val;
                scanf("%d", &val);
                getchar();
                for(i=0; i<n; i++) {
                    if(kartu[i].star == val) {
                        printf("%s %d\n", kartu[i].nama, kartu[i].star);
                        ada = true;
                    }
                }
            } else if(strcmp(q2, "Rank") == 0) {
                int val;
                scanf("%d", &val);
                getchar();
                for(i=0; i<n; i++) {
                    if(kartu[i].rank == val) {
                        printf("%s %d\n", kartu[i].nama, kartu[i].rank);
                        ada = true;
                    }
                }
            } else if(strcmp(q2, "Link") == 0) {
                int val;
                scanf("%d", &val);
                getchar();
                for(i=0; i<n; i++) {
                    if(kartu[i].link == val) {
                        printf("%s %d\n", kartu[i].nama, kartu[i].link);
                        ada = true;
                    }
                }
            } else if(strcmp(q2, "Linkmarker") == 0) {
                char val[100];
                scanf("%s", val);
                getchar();
                for(i=0; i<n; i++) {
                    if(strstr(kartu[i].linkmarker, val) != NULL) {
                        printf("%s %s\n", kartu[i].nama, kartu[i].linkmarker);
                        ada = true;
                    }
                }
            } else if(strcmp(q2, "Scale") == 0) {
                int val;
                scanf("%d", &val);
                getchar();
                for(i=0; i<n; i++) {
                    if(kartu[i].scale == val)  {
                        printf("%s %d\n", kartu[i].nama, kartu[i].scale);
                        ada = true;
                    }
                }
            } else if(strcmp(q2, "Defense") == 0) {
                int val;
                scanf("%d", &val);
                getchar();
                for(i=0; i<n; i++) {
                    if(kartu[i].defense == val)  {
                        printf("%s %d\n", kartu[i].nama, kartu[i].defense);
                        ada = true;
                    }
                }
            } else if(strcmp(q2, "Attack") == 0) {
                int val;
                scanf("%d", &val);
                getchar();
                for(i=0; i<n; i++) {
                    if(kartu[i].attack == val)  {
                        printf("%s %d\n", kartu[i].nama, kartu[i].attack);
                        ada = true;
                    }
                }
            } else if(strcmp(q2, "Attribute") == 0) {
                char val[100];
                scanf("%s", val);
                getchar();
                for(i=0; i<n; i++) {
                    if(strcmp(kartu[i].attribute, val) == 0)  {
                        printf("%s %s\n", kartu[i].nama, kartu[i].attribute);
                        ada = true;
                    }
                }
            } else if(strcmp(q2, "Type") == 0) {
                char val[100];
                gets(val);
                for(i=0; i<n; i++) {
                    if(strcmp(kartu[i].typemonster, val) == 0)  {
                        printf("%s %s\n", kartu[i].nama, kartu[i].typemonster);
                        ada = true;
                    }
                }
            }
            if(!ada) printf("Tidak Ada Data Yang Cocok\n");
        } else if(cmp(query, "FindOut")) {
            int k;
            char q5[50];
            scanf("%d %s", &k, q5);
            // puts(q5);
            getchar();
            if(cmp(q5, "Name")) {
                printf("%s\n", kartu[k].nama);
            } else if(cmp(q5, "Star")) {
                if(kartu[k].star != INT_MIN) printf("%d\n", kartu[k].star);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "Rank")) {
                if(kartu[k].rank != INT_MIN) printf("%d\n", kartu[k].rank);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "OverlayUnit")) {
                if(kartu[k].overlayunit != INT_MIN) printf("%d\n", kartu[k].overlayunit);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "Link")) {
                if(kartu[k].link != INT_MIN) printf("%d\n", kartu[k].link);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "Linkmarker")) {
                if(kartu[k].linkmarker[0] != '\0') printf("%s\n", kartu[k].linkmarker);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "Scale")) {
                if(kartu[k].scale != INT_MIN) printf("%d\n", kartu[k].scale);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "Defense")) {
                if(kartu[k].defense != INT_MIN) printf("%d\n", kartu[k].defense);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "Attack")) {
                if(kartu[k].attack != INT_MIN) printf("%d\n", kartu[k].attack);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "Attribute")) {
                if(kartu[k].attribute[0] != '\0') printf("%s\n", kartu[k].attribute);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            } else if(cmp(q5, "Linkmarker")) {
                if(kartu[k].typemonster[0] != '\0') printf("%s\n", kartu[k].typemonster);
                else printf("Kartu Tidak Memiliki Data Tersebut\n");
            }
        } else if(cmp(query, "Min")) {
            char q4[50];
            int min = INT_MAX;
            int minindex = 0;
            scanf("%s", q4);
            getchar();
            if(cmp(q4, "Star")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].star < min && kartu[i].star != INT_MIN) {
                        min = kartu[i].star;
                        minindex = i;
                    } else if(kartu[i].star == min && kartu[i].star != INT_MIN) {
                        if(more(kartu[i].nama ,kartu[minindex].nama)) {
                            min = kartu[i].star;
                            minindex = i;
                        }
                    }
                }
            } else if(cmp(q4, "Rank")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].rank < min && kartu[i].rank != INT_MIN) {
                        min = kartu[i].rank;
                        minindex = i;
                    } else if(kartu[i].rank == min && kartu[i].rank != INT_MIN) {
                        if(more(kartu[i].nama ,kartu[minindex].nama)) {
                            min = kartu[i].rank;
                            minindex = i;
                        }
                    }
                }
            } else if(cmp(q4, "Link")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].link < min && kartu[i].link != INT_MIN) {
                        min = kartu[i].link;
                        minindex = i;
                    } else if(kartu[i].link == min && kartu[i].link != INT_MIN) {
                        if(more(kartu[i].nama ,kartu[minindex].nama)) {
                            min = kartu[i].link;
                            minindex = i;
                        }
                    }
                }
            }  else if(cmp(q4, "Scale")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].scale < min && kartu[i].scale != INT_MIN) {
                        min = kartu[i].scale;
                        minindex = i;
                    } else if(kartu[i].scale == min && kartu[i].scale != INT_MIN) {
                        if(more(kartu[i].nama ,kartu[minindex].nama)) {
                            min = kartu[i].scale;
                            minindex = i;
                        }
                    }
                }
            } else if(cmp(q4, "Defense")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].defense < min && kartu[i].defense != INT_MIN) {
                        min = kartu[i].defense;
                        minindex = i;
                    } else if(kartu[i].defense == min && kartu[i].defense != INT_MIN) {
                        if(more(kartu[i].nama ,kartu[minindex].nama)) {
                            min = kartu[i].defense;
                            minindex = i;
                        }
                    }
                }
            } else if(cmp(q4, "Attack")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].attack < min && kartu[i].attack != INT_MIN) {
                        min = kartu[i].attack;
                        minindex = i;
                    } else if(kartu[i].attack == min && kartu[i].attack != INT_MIN) {
                        if(more(kartu[i].nama ,kartu[minindex].nama)) {
                            min = kartu[i].attack;
                            minindex = i;
                        }
                    }
                }
            }
            printf("%s %d\n", kartu[minindex].nama, min);
        } else if(cmp(query, "Max")) {
            char q4[50];
            int max = INT_MIN;
            int maxindex = 0;
            scanf("%s", q4);
            getchar();
            if(cmp(q4, "Star")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].star > max && kartu[i].star != INT_MIN) {
                        max = kartu[i].star;
                        maxindex = i;
                    } else if(kartu[i].star == max && kartu[i].star != INT_MIN) {
                        if(less(kartu[i].nama ,kartu[maxindex].nama)) {
                            max = kartu[i].star;
                            maxindex = i;
                        }
                    }
                }
            } else if(cmp(q4, "Rank")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].rank > max && kartu[i].rank != INT_MIN) {
                        max = kartu[i].rank;
                        maxindex = i;
                    } else if(kartu[i].rank == max && kartu[i].rank != INT_MIN) {
                        if(less(kartu[i].nama ,kartu[maxindex].nama)) {
                            max = kartu[i].rank;
                            maxindex = i;
                        }
                    }
                }
            } else if(cmp(q4, "Link")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].link > max && kartu[i].link != INT_MIN) {
                        max = kartu[i].link;
                        maxindex = i;
                    } else if(kartu[i].link == max && kartu[i].link != INT_MIN) {
                        if(less(kartu[i].nama ,kartu[maxindex].nama)) {
                            max = kartu[i].link;
                            maxindex = i;
                        }
                    }
                }
            } else if(cmp(q4, "Scale")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].scale > max && kartu[i].scale != INT_MIN) {
                        max = kartu[i].scale;
                        maxindex = i;
                    } else if(kartu[i].scale == max && kartu[i].scale != INT_MIN) {
                        if(less(kartu[i].nama ,kartu[maxindex].nama)) {
                            max = kartu[i].scale;
                            maxindex = i;
                        }
                    }
                }
            } else if(cmp(q4, "Defense")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].defense > max && kartu[i].defense != INT_MIN) {
                        max = kartu[i].defense;
                        maxindex = i;
                        // printf("Masuk1 %s %d\n", kartu[i].nama, kartu[i].defense);
                    } else if(kartu[i].defense == max && kartu[i].defense != INT_MIN) {
                        if(less(kartu[i].nama ,kartu[maxindex].nama)) {
                            max = kartu[i].defense;
                            maxindex = i;
                            // printf("Masuk2 %s %d\n", kartu[i].nama, kartu[i].defense);
                        }
                    }
                }
            } else if(cmp(q4, "Attack")) {
                for(i=0; i<n; i++) {
                    if(kartu[i].attack > max && kartu[i].attack != INT_MIN) {
                        max = kartu[i].attack;
                        maxindex = i;
                    } else if(kartu[i].attack == max && kartu[i].attack != INT_MIN) {
                        if(less(kartu[i].nama ,kartu[maxindex].nama)) {
                            max = kartu[i].attack;
                            maxindex = i;
                        }
                    }
                }
            }
            printf("%s %d\n", kartu[maxindex].nama, max);
        } else if(cmp(query, "Likely")) {
            bool tersebut = false;
            char s1[100];
            scanf("%s", s1);
            for(i=0; i<strlen(s1); i++) {
                if(s1[i] >= 'A' && s1[i] <='Z') s1[i] = s1[i] - 'A' +'a';
            }
            getchar();
            for(i=0; i<n; i++) {
                char temp[105];
                strcpy(temp, kartu[i].description);
                temp[strlen(kartu[i].description)] = '\0';
                int j;
                for(j=0; j<strlen(temp); j++) {
                     if(temp[j] >= 'A' && temp[j] <='Z') temp[j] = temp[j] - 'A' +'a';
                }
                // puts(temp);
                // puts(s1);
                // printf("%s", strstr(temp, s1));
                if(strstr(temp, s1) != NULL) {
                    // puts("mmmmm");
                    printf("%s\n%s\n", kartu[i].nama, kartu[i].description);
                }
            }
        } else if(cmp(query, "SortDB")) {
            char q3[100];
            scanf("%s", q3);
            getchar();
            if(cmp(q3, "Name")) sortbyname(kartu, n);
            else if(cmp(q3, "Star")) sortbystar(kartu, n);
            else if(cmp(q3, "Rank")) sortbyrank(kartu, n);
            else if(cmp(q3, "OverlayUnit")) sortbyou(kartu, n);
            else if(cmp(q3, "Link")) sortbylink(kartu, n);
            else if(cmp(q3, "Scale")) sortbyscale(kartu, n);
            else if(cmp(q3, "Defense")) sortbydef(kartu, n);
            else if(cmp(q3, "Attack")) sortbyatt(kartu, n);
            // for(i=0; i<n; i++) printf("After sorted %s: %s %d:\n", q3, kartu[i].nama, kartu[i].defense);
        }
    }
    
    return 0;
}