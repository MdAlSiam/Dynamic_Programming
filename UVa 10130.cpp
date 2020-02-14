#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int weight[1010], cost[1010], dp[1010][40];
int number_of_items, capacity;

int knapsac(int i, int w){
    if(i >= number_of_items) return 0;
    int &ret = dp[i][w];
    if(ret != -1) return ret;

    int profit1 = 0, profit2 = 0;

    if(w + weight[i] <= capacity){
        profit1 = cost[i] + knapsac(i+1, w+weight[i]);
    }

    profit2 = knapsac(i+1, w);

    ret = max(profit1, profit2);

    return ret;
}

int main(){
    int test, number_of_persons, sum;

    scanf("%d", &test);

    while(test--){
        int sum = 0;

        scanf("%d", &number_of_items);

        for(int i = 0; i < number_of_items; i++){
            scanf("%d %d", &cost[i], &weight[i]);
        }

        scanf("%d", &number_of_persons);

        for(int i = 0; i < number_of_persons; i++){
            scanf("%d", &capacity);
            memset(dp, -1, sizeof(dp));
            sum += knapsac(0, 0);
        }

        printf("%d\n", sum);
    }
}

