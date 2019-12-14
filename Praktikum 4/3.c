#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ull unsigned long long

struct Stack {
    ull n;
    struct Stack * bottomPtr;
};

typedef struct Stack stack;
typedef stack *stackPtr;

void push(ull, stackPtr *);
void pop(stackPtr *);
bool empty(stackPtr);
ull top(stackPtr);
ull max(ull *, ull);

int main() {
    ull n, i;
    scanf("%llu", &n);
    ull *height = (ull *) malloc(n*sizeof(ull));
    for (i=0; i<n; i++) {
        scanf("%llu", &height[i]);
    }
    printf("%llu\n", max(height, n));
    return 0;
}

void push(ull n, stackPtr * s) {
    stackPtr newPtr;
    newPtr = (stackPtr) malloc(sizeof(stack));
    newPtr->bottomPtr = *s;
    newPtr->n = n;
    *s = newPtr;
}

void pop(stackPtr * s) {
    if(!empty(*s)) {
        stackPtr tmp;
        tmp = *s;
        *s = (*s)->bottomPtr;
        free(tmp);
    }
}

bool empty(stackPtr s) {
    return s == NULL;
}

ull top(stackPtr s) {
    if(s != NULL) return s->n;
}

ull max(ull * height, ull n) {
    stackPtr s = NULL;
    ull topval, area, max = 0;
    
    int i = 0;
    while (i < n) {
        if(empty(s) || height[top(s)] <= height[i]) {
            push(i++, &s);
        } else {
            topval = top(s);
            pop(&s);
            area = height[topval] * (empty(s) ? i : i - top(s) - 1);
            if (max < area) max = area;
        }
    }
    while (!empty(s)) {
        topval = top(s);
        pop(&s);
        //printf("top: %llu, empty: %d, max = %llu\n", topval, empty(s), max);
        area = height[topval] * (empty(s) ? i : i - top(s) - 1);
        if (max < area) max = area;
    }
    return max;
}