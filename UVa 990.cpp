#include <bits/stdc++.h>
using namespace std;

int capacity, w; ///costing capacity

int cost[32], profit[32];
int costtrack[32];

int n;

int dp[32][1002];
bool taken[32][1002];
bool x[32];

int explore(int index, int capacity){

    if(index == n || capacity == 0) return 0;

    if(dp[index][capacity] != -1) return dp[index][capacity];

    int ret1, ret2;

    if(capacity - cost[index] >= 0){
        ret1 = profit[index] + explore(index+1, capacity - cost[index]);
    }
    else ret1 = 0;

    ret2 = explore(index+1, capacity);

    if(ret1 >= ret2){
        taken[index][capacity] = true;
        dp[index][capacity] = ret1;
        return ret1;
    }
    else{
        taken[index][capacity] = false;
        dp[index][capacity] = ret2;
        return ret2;
    }
}

int main(){
    bool first = true;
    while(scanf("%d %d", &capacity, &w) == 2){
        if(!first) {scanf("\n");printf("\n");}
        first = false;

        memset(dp, -1, sizeof(dp));
        memset(taken, false, sizeof(taken));
        memset(x, false, sizeof(x));

        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d %d", &cost[i], &profit[i]);
            costtrack[i] = cost[i];
            cost[i] = cost[i]*w*3;
        }

        int ans = explore(0, capacity);

        printf("%d\n", ans);

        int tempcapacity = capacity, kount = 0;
        for(int i = 0; i < n; i++){
            if(taken[i][tempcapacity]){
                kount++;
                x[i] = true;
                tempcapacity -= cost[i];
            }
        }

        printf("%d\n", kount);
        for(int i = 0; i < n; i++){
            if(x[i]){
                printf("%d %d\n", costtrack[i], profit[i]);
            }
        }
    }
}
