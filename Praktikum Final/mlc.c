#include <stdio.h>
#define ll long long
 
int main() {
    int cube[200][200][200], n, i;
    ll sum = 0;
    ll sumx[200][200] = {0}, sumy[200][200] = {0}, sumz[200][200] = {0};
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        int j;
        for(j=0; j<n; j++) {
            int k;
            for(k=0; k<n; k++) {
                scanf("%d", &cube[i][j][k]);
                sum += cube[i][j][k];
                sumx[j][k] += cube[i][j][k];
                sumy[i][k] += cube[i][j][k];
                sumz[i][j] += cube[i][j][k];
            }
        }
    }
    int q;
    scanf("%d", &q);
    for(i=0; i<q; i++) {
        short command;
        scanf("%hd", &command);
        if(command == 1) {
            int x, y, z, a;
            scanf("%d %d %d %d", &x, &y, &z, &a);
            sum -= cube[x][y][z];
            sumx[y][z] += a;
            sumy[x][z] += a;
            sumz[x][y] += a;
            sumx[y][z] -= cube[x][y][z];
            sumy[x][z] -= cube[x][y][z];
            sumz[x][y] -= cube[x][y][z];
            sum += a;
            cube[x][y][z] = a;
        } else if(command == 2) {
            int x1, y1, z1, x2, y2, z2;
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            int tmp = cube[x1][y1][z1];
            cube[x1][y1][z1] = cube[x2][y2][z2];
            sumx[y1][z1] += cube[x2][y2][z2];
            sumy[x1][z1] += cube[x2][y2][z2];
            sumz[x1][y1] += cube[x2][y2][z2];
            sumx[y2][z2] -= cube[x2][y2][z2];
            sumy[x2][z2] -= cube[x2][y2][z2];
            sumz[x2][y2] -= cube[x2][y2][z2];
            cube[x2][y2][z2] = tmp;
            sumx[y2][z2] += tmp;
            sumy[x2][z2] += tmp;
            sumz[x2][y2] += tmp;
            sumx[y1][z1] -= tmp;
            sumy[x1][z1] -= tmp;
            sumz[x1][y1] -= tmp;
        } else {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            int j;
            printf("%lld\n", sum + (2 * cube[x][y][z]) - sumx[y][z] -sumy[x][z] -sumz[x][y]);
        }
    }
    return 0;
}