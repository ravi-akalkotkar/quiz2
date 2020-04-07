#include <iostream>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int set[] = {1, 8, 6, 4, 3};

bool SubsetSum(int x[], int n, int k, int v) {
    if(v==0 && k ==0) {
        return true;
    }
    if(v!=0 && k==0) {
        return false;
    }
    if(n==0) {
        return false;
    }
    int newarray[n-1];
    for(int i = 1; i < n; i++) {
        newarray[i-1] = x[i];
    }
    bool res1 = false;
    if(v>=x[0]) {
        res1 = SubsetSum(newarray, n-1, k-1, v-x[0]);
    }
    bool res2 = SubsetSum(newarray, n-1, k, v);
    return res1 + res2 > 0;
    }


int main(void) {
    if(SubsetSum(set, 5, 2, 9)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
