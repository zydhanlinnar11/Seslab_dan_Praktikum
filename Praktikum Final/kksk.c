#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define sleding printf("Masih saya pantau, nanti kami double sleding kalian satu-satu\n")

typedef struct card {
    char nama[120], type[50];
    int link, level, rank, scale, attack, defend;
}Card;

void swap(Card * a, Card * b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, i;
    Card monster[120];
    char s1[50];
    scanf("%d %s", &n, s1);
    for(i=0; i<n; i++) {
        // printf("i: %d\n", i);
        getchar();
        gets(monster[i].nama);
        scanf("%s", monster[i].type);
        if(strcmp(monster[i].type, "Fusion") == 0) {
            scanf("%d", &monster[i].level);
            scanf("%d %d", &monster[i].attack, &monster[i].defend);
            monster[i].link = INT_MIN;
            monster[i].rank = INT_MIN;
            monster[i].scale = INT_MIN;
        } else if(strcmp(monster[i].type, "Synchro") == 0) {
            scanf("%d", &monster[i].level);
            scanf("%d %d", &monster[i].attack, &monster[i].defend);
            monster[i].link = INT_MIN;
            monster[i].rank = INT_MIN;
            monster[i].scale = INT_MIN;
        } else if(strcmp(monster[i].type, "XYZ") == 0) {
            scanf("%d", &monster[i].rank);
            scanf("%d %d", &monster[i].attack, &monster[i].defend);
            monster[i].link = INT_MIN;
            monster[i].level = INT_MIN;
            monster[i].scale = INT_MIN;
        } else if(strcmp(monster[i].type, "Pendulum") == 0) {
            scanf("%d", &monster[i].level);
            scanf("%d", &monster[i].scale);
            monster[i].link = INT_MIN;
            monster[i].rank = INT_MIN;
            scanf("%d %d", &monster[i].attack, &monster[i].defend);
        } else if(strcmp(monster[i].type, "Link") == 0) {
            scanf("%d", &monster[i].link);
            scanf("%d", &monster[i].attack);
            monster[i].defend = INT_MIN;
            monster[i].level = INT_MIN;
            monster[i].scale = INT_MIN;
            monster[i].rank = INT_MIN;
        }
    }
    if(strcmp(s1, "Defend")==0) {
        bool urut = false;
        while(!urut) {
            urut = true;
            for(i=0; i<n-1; i++) {
                if(monster[i].defend < monster[i+1].defend) {
                    urut = false;
                    swap(&monster[i], &monster[i+1]);
                } else if (monster[i].defend == monster[i+1].defend) {
                    if(strcmp(monster[i].nama, monster[i+1].nama) > 0) {
                        urut = false;
                        swap(&monster[i], &monster[i+1]);
                    }
                }
            }
        }
    } else if(strcmp(s1, "Attack")==0) {
        bool urut = false;
        while(!urut) {
            urut = true;
            for(i=0; i<n-1; i++) {
                if(monster[i].attack < monster[i+1].attack) {
                    urut = false;
                    swap(&monster[i], &monster[i+1]);
                } else if (monster[i].attack == monster[i+1].attack) {
                    if(strcmp(monster[i].nama, monster[i+1].nama) > 0) {
                        urut = false;
                        swap(&monster[i], &monster[i+1]);
                    }
                }
            }
        }
    } else if(strcmp(s1, "Link")==0) {
        bool urut = false;
        while(!urut) {
            urut = true;
            for(i=0; i<n-1; i++) {
                if(monster[i].link < monster[i+1].link) {
                    urut = false;
                    swap(&monster[i], &monster[i+1]);
                } else if (monster[i].link == monster[i+1].link) {
                    if(strcmp(monster[i].nama, monster[i+1].nama) > 0) {
                        urut = false;
                        swap(&monster[i], &monster[i+1]);
                    }
                }
            }
        }
    } else if(strcmp(s1, "Scale")==0) {
        bool urut = false;
        while(!urut) {
            urut = true;
            for(i=0; i<n-1; i++) {
                if(monster[i].scale < monster[i+1].scale) {
                    urut = false;
                    swap(&monster[i], &monster[i+1]);
                } else if (monster[i].scale == monster[i+1].scale) {
                    if(strcmp(monster[i].nama, monster[i+1].nama) > 0) {
                        urut = false;
                        swap(&monster[i], &monster[i+1]);
                    }
                }
            }
        }
    } else if(strcmp(s1, "Rank")==0) {
        bool urut = false;
        while(!urut) {
            urut = true;
            for(i=0; i<n-1; i++) {
                if(monster[i].rank < monster[i+1].rank) {
                    urut = false;
                    swap(&monster[i], &monster[i+1]);
                } else if (monster[i].rank == monster[i+1].rank) {
                    if(strcmp(monster[i].nama, monster[i+1].nama) > 0) {
                        urut = false;
                        swap(&monster[i], &monster[i+1]);
                    }
                }
            }
        }
    } else if(strcmp(s1, "Level")==0) {
        bool urut = false;
        while(!urut) {
            urut = true;
            for(i=0; i<n-1; i++) {
                if(monster[i].level < monster[i+1].level) {
                    urut = false;
                    swap(&monster[i], &monster[i+1]);
                } else if (monster[i].level == monster[i+1].level) {
                    if(strcmp(monster[i].nama, monster[i+1].nama) > 0) {
                        urut = false;
                        swap(&monster[i], &monster[i+1]);
                    }
                }
            }
        }
    }
    int m;
    scanf("%d", &m);
    for(i=0; i<m; i++) {
        char s2[50];
        scanf("%s", s2);
        if(strcmp(s2, "Data") == 0) {
            int o;
            char s4[50];
            scanf("%d %s", &o, s4);
            if(strcmp(s4, "Name")==0) printf("%s\n", monster[o-1].nama);
            else if(strcmp(s4, "Types")==0) printf("%s\n", monster[o-1].type);
            else if(strcmp(s4, "Level")==0) {
                if((strcmp(monster[o-1].type, "XYZ") == 0) || (strcmp(monster[o-1].type, "Link") == 0)) sleding;
                else printf("%d\n", monster[o-1].level);
            } else if(strcmp(s4, "Rank")==0) {
                if(!(strcmp(monster[o-1].type, "XYZ") == 0)) sleding;
                else printf("%d\n", monster[o-1].rank);
            } else if(strcmp(s4, "Scale")==0) {
                if(!(strcmp(monster[o-1].type, "Pendulum") == 0)) sleding;
                else printf("%d\n", monster[o-1].scale);
            } else if(strcmp(s4, "Link")==0) {
                if(!(strcmp(monster[o-1].type, "Link") == 0)) sleding;
                else printf("%d\n", monster[o-1].link);
            } else if(strcmp(s4, "Attack")==0) {
                printf("%d\n", monster[o-1].attack);
            } else if(strcmp(s4, "Defend")==0) {
                if(strcmp(monster[o-1].type, "Link") == 0) sleding;
                else printf("%d\n", monster[o-1].defend);
            }
        } else if(strcmp(s2, "Maks") == 0) {
            char s3[50];
            scanf("%s", s3);
            if(strcmp(s3, "Level") == 0) {
                int max = INT_MIN;
                int maxindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if((monster[j].level > max) && (monster[j].level != INT_MIN)) {
                        max = monster[j].level;
                        maxindex = j;
                    }
                }
                if(max==INT_MIN) sleding;
                else printf("%s %d\n", monster[maxindex].nama, max);
            } else if(strcmp(s3, "Rank") == 0) {
                int max = INT_MIN;
                int maxindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if((monster[j].rank > max) && (monster[j].rank != INT_MIN)) {
                        max = monster[j].rank;
                        maxindex = j;
                    }
                }
                if(max==INT_MIN) sleding;
                else printf("%s %d\n", monster[maxindex].nama, max);
            } else if(strcmp(s3, "Link") == 0) {
                int max = INT_MIN;
                int maxindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if((monster[j].link > max) && (monster[j].link != INT_MIN)) {
                        max = monster[j].link;
                        maxindex = j;
                    }
                }
                if(max==INT_MIN) sleding;
                else printf("%s %d\n", monster[maxindex].nama, max);
            } else if(strcmp(s3, "Attack") == 0) {
                int max = INT_MIN;
                int maxindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if((monster[j].attack > max) && (monster[j].attack != INT_MIN)) {
                        max = monster[j].attack;
                        maxindex = j;
                    }
                }
                if(max==INT_MIN) sleding;
                else printf("%s %d\n", monster[maxindex].nama, max);
            } else if(strcmp(s3, "Defend") == 0) {
                int max = INT_MIN;
                int maxindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if((monster[j].defend > max) && (monster[j].defend != INT_MIN)) {
                        max = monster[j].defend;
                        maxindex = j;
                    }
                }
                if(max==INT_MIN) sleding;
                else printf("%s %d\n", monster[maxindex].nama, max);
            } else if(strcmp(s3, "Scale") == 0) {
                int max = INT_MIN;
                int maxindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if((monster[j].scale > max) && (monster[j].scale != INT_MIN)) {
                        max = monster[j].scale;
                        maxindex = j;
                    }
                }
                if(max==INT_MIN) sleding;
                else printf("%s %d\n", monster[maxindex].nama, max);
            }
        } else if(strcmp(s2, "Min") == 0) {
            char s3[50];
            scanf("%s", s3);
            if(strcmp(s3, "Level") == 0) {
                int min = monster[0].level;
                int minindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if(monster[j].level < min) {
                        min = monster[j].level;
                        minindex = j;
                    }
                }
                if(min==INT_MIN) sleding;
                else printf("%s %d\n", monster[minindex].nama, min);
            } else if(strcmp(s3, "Rank") == 0) {
                int min = monster[0].rank;
                int minindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if(monster[j].rank < min) {
                        min = monster[j].rank;
                        minindex = j;
                    }
                }
                if(min==INT_MIN) sleding;
                else printf("%s %d\n", monster[minindex].nama, min);
            } else if(strcmp(s3, "Link") == 0) {
                int min = monster[0].link;
                int minindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if(monster[j].link < min) {
                        min = monster[j].link;
                        minindex = j;
                    }
                }
                if(min==INT_MIN) sleding;
                else printf("%s %d\n", monster[minindex].nama, min);
            } else if(strcmp(s3, "Attack") == 0) {
                int min = monster[0].attack;
                int minindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if(monster[j].attack < min) {
                        min = monster[j].attack;
                        minindex = j;
                    }
                }
                if(min==INT_MIN) sleding;
                else printf("%s %d\n", monster[minindex].nama, min);
            } else if(strcmp(s3, "Defend") == 0) {
                int min = monster[0].defend;
                int minindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if(monster[j].defend < min) {
                        min = monster[j].defend;
                        minindex = j;
                    }
                }
                if(min==INT_MIN) sleding;
                else printf("%s %d\n", monster[minindex].nama, min);
            } else if(strcmp(s3, "Scale") == 0) {
                int min = monster[0].scale;
                int minindex = 0;
                int j;
                for(j=0; j<n; j++) {
                    if(monster[j].scale < min) {
                        min = monster[j].scale;
                        minindex = j;
                    }
                }
                if(min==INT_MIN) sleding;
                else printf("%s %d\n", monster[minindex].nama, min);
            }
        }
    }
    return 0;
}