#include <bits/stdc++.h> 
using namespace std;

int main() {
    int t, sum = 0;
    cin>>t;
    int arr[t];
    for(int i=0; i<t; i++)
        cin>>arr[i], sum += arr[i];
    bool sudah[t+1][((sum+1) >> 1)];
    for (int i = 0; i <= t; i++) 
        sudah[i][0] = true;
    for (int i = 1; i <= (sum >> 1); i++) 
        sudah[0][i] = false; 
    for (int i=1; i<=t; i++) { 
        for (int j=1; j<=(sum/2); j++) {
            sudah[i][j] = sudah[i-1][j]; 
            if (arr[i-1] <= j) 
                sudah[i][j] |= sudah[i-1][j-arr[i-1]]; 
        } 
    } 

    int selisih = INT_MAX;
    for (int j=sum / 2; j>=0; j--) {
        if (sudah[t][j] == true) { 
            selisih = sum - (j * 2); 
            break; 
        } 
    }
    int n1 = (sum - selisih) / 2, n2 = sum - n1;
    cout<<n2<<' '<<n1<<'\n';
    return 0; 
} 