#include <stdio.h>
#include <string.h>

int main() {
    int l[1023] = {0}, r[1023] = {0};
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        char s[101];
        char lorr;
        scanf("%s %c", s, &lorr);
        //printf("%s %c", s, lorr);
        int j;
        if(lorr=='R') {
            int anjay=0;
            for(j=0; j<strlen(s); j++) {
                if(s[j]>='0' && s[j]<='9') {
                    anjay = (anjay*10) + (s[j]-'0');
                }
            }
            r[anjay-1]++;
        } else {
            int anjay=0;
            for(j=0; j<strlen(s); j++) {
                if(s[j]>='0' && s[j]<='9') {
                    anjay = (anjay*10) + (s[j]-'0');
                }
            }
            l[anjay-1]++;
        }
    }
    int sum=0;
    for(i=0; i<1023; i++) {
        if(l[i]<=r[i]) sum +=l[i];
        else if(r[i]<l[i]) sum += r[i];
    }
    printf("%d\n", sum);
    return 0;
}