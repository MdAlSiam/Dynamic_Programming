#include <bits/stdc++.h>
using namespace std;

#define mod 10000007

#define ll long long int

ll ara[10111], n;

int main(){
    ll test, kase = 0;
    scanf("%lld", &test);
    while(test--){
    scanf("%lld %lld %lld %lld %lld %lld %lld", &ara[0], &ara[1], &ara[2], &ara[3], &ara[4], &ara[5], &n);
    for(ll i = 6; i <= n; i++){
        ara[i] = ara[i-1] + ara[i-2] + ara[i-3] + ara[i-4] + ara[i-5] + ara[i-6];
        ara[i] %= mod;
    }
    ara[n] %= mod;
    printf("Case %lld: %lld\n", ++kase, ara[n]);
    } 
}
