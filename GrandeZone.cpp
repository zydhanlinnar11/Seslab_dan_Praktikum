#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack>
#define ull unsigned long long
using namespace std;

ull getluas(ull * height, ull n) {
    stack<ull> s;
    ull topval, area, max = 0;
    
    int i = 0;
    while (i < n) {
        if(s.empty() || height[s.top()] <= height[i]) s.push(i++);
        else {
            topval = s.top();
            s.pop();
            area = height[topval] * (s.empty() ? i : i - s.top() - 1);
            if (max < area) max = area;
        }
    }
    while (!s.empty()) {
        topval = s.top();
        s.pop();
        area = height[topval] * (s.empty() ? i : i - s.top() - 1);
        if (max < area) max = area;
    }
    return max;
}

int main() {
    ull n, i;
    while(scanf("%llu", &n) != EOF) {
        ull *height = (ull *) malloc(n*sizeof(ull));
        for (i=0; i<n; i++) scanf("%llu", &height[i]);
        printf("%llu\n", getluas(height, n));
    }
    return 0;
}