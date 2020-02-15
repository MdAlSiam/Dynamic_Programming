#include <bits/stdc++.h>
using namespace std;

#define mod 100000007

int n, make;
int coins[56], usepermit[56], memtab[56][1024];

int call(int i, int amount){
    if(i > n || amount > make){
        if(amount == make) return 1;
        return 0;
    }

    if(memtab[i][amount] != -1) return memtab[i][amount];

    int ret = 0;

    for(int k = 1; k <= usepermit[k]; k++){
        ret += call(i+1, amount + k*coins[i]);
        ret %= mod;
    }

    return memtab[i][amount] = ret;
}

int main(){
    int test, tc = 0;
    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &make);
        for(int i = 1; i <= n; i++) scanf("%d", &coins[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &usepermit[i]);
        memset(memtab, -1, sizeof(memtab));
        printf("Case %d: %d\n", ++tc, call(1, 0));
    }
}
