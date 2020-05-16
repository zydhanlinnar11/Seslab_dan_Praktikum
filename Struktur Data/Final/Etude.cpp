#include <bits/stdc++.h>
using namespace std;
int pos1[] = {3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18, 19, 20, 21,
         22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33, 34, 35, 36, 37};
int pos2[] = {0, 0, 1, 0, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 0, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 0, 27, 28, 29, 30, 31};
int power[32];

void etude() {
    int a, bit = 0, bitsalah = 0, p1 = 0, p2 = 0, p4 = 0, p8 = 0, p16 = 0, bilangan = 0;
    cin>>hex>>a;
    vector<int> compute(31, 0);
    for(int i=30; a > 0; i--) {
        compute[i] = (a % 2);
        a >>= 1;
        // cout<<compute[i];
        if(i == 30)
            p1 += compute[i];
        else if(i == 29)
            p2 += compute[i];
        else if(i == 28)
            p4 += compute[i];
        else if(i == 27)
            p8 += compute[i];
        else if(i == 26)
            p16 += compute[i];
        // cout<<(30 - i)<<" : "<<compute[i]<<'\n';
        if(i <= 25) {
            if((pos1[bit] & 1) == 1)
                p1 += compute[i];
            if((pos1[bit] & 2) == 2)
                p2 += compute[i];
            if((pos1[bit] & 4) == 4)
                p4 += compute[i];
            if((pos1[bit] & 8) == 8)
                p8 += compute[i];
            if((pos1[bit] & 16) == 16)
                p16 += compute[i];
            // cout<<"Bit ke-"<<pos1[bit]<<'\n';
            bilangan += compute[i] * power[bit];
            bit++;
        }
    }
    // cout<<'\n';
    if((p1 % 2) != 0)
        bitsalah += 1;
    if((p2 % 2) != 0)
        bitsalah += 2;
    if((p4 % 2) != 0)
        bitsalah += 4;
    if((p8 % 2) != 0)
        bitsalah += 8;
    if((p16 % 2) != 0)
        bitsalah += 16;
    // printf("p1 = %d, p2 = %d, p4 = %d, p8 = %d, p16 = %d\n", p1, p2, p4, p8, p16);
    // cout<<"bitsalah "<<bitsalah<<'\n';
    if(bitsalah > 2 && bitsalah != 4 && bitsalah != 8 && bitsalah != 16) {
        int bitindex = 26 - pos2[bitsalah - 1], bitke = 25 - bitindex;
        // printf("Bit yang salah %d, 2^%d\n", bitsalah, )
        bilangan -= compute[bitindex] * power[bitke];
        bilangan += (!compute[bitindex]) * power[bitke];
    }
    cout<<hex<<bilangan;
    cout<<'\n';
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    power[0] = 1;
    for(int i=1; i<32; i++) {
        power[i] = power[i - 1] * 2;
        // printf("2^%d = %d\n", i, power[i]);
    }
    cin>>t;
    while(t--)
        etude();
    return 0;
}