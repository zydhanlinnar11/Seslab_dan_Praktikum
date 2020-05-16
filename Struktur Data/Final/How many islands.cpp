#include <bits/stdc++.h>
using namespace std;
int arr[12][12], stepx[] = {0, 0, 1, -1}, stepy[] = {-1, 1, 0, 0};

void markAll(int x, int y, int sizex, int sizey) {
    if(x < 0 || x >= sizex || y < 0 || y >= sizey)
        return;
    if(arr[y][x] == 0)
        return;
    arr[y][x] = 0;
    for(int i=0; i<4; i++)
        markAll(x + stepx[i], y + stepy[i], sizex, sizey);
}

int main() {
    int npulau = 0, sizex=0, sizey=0, tmp = 0;
    char c;
    while((c = getchar()) != EOF) {
        if(c == '1' || c == '0')
            arr[sizey][tmp] = c - '0', tmp++;
        if(c == '\n')
            sizey++, sizex = tmp, tmp = 0;
    }
    sizey++;
    for(int i=0; i<sizey; i++) {
        for(int j=0; j<sizex; j++) {
            if(arr[i][j] != 0) {
                npulau++;
                markAll(j, i, sizex, sizey);
            }
        }
    }
    cout<<npulau<<'\n';
    return 0;
}