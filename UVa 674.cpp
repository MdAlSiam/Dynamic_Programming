#include <bits/stdc++.h>
using namespace std;

int coins[] = {50, 25, 10, 5, 1};
int make; ///target amount
int dp[6][8000];

int call(int i, int amount){
    if(i >= 5){
        if(amount == 0) return 1;
        else return 0;
    }

    int& ret = dp[i][amount];
    if(ret != -1) return ret;

    int ret1 = 0, ret2 = 0;

    if(amount - coins[i] >= 0)
        ret1 = call(i, amount - coins[i]);
    ret2 = call(i+1, amount);

    return ret = ret1 + ret2;
}

int main(){
    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &make) == 1)
        printf("%d\n", call(0, make));
}
