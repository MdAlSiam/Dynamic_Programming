#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1e12

ll n, k;
ll a[555];
ll dp[555][555];

ll explore(ll curr_pos, ll remaining){

    if(curr_pos == n) return 0;
    if(remaining == 0) return inf;

    if(dp[curr_pos][remaining] != -1 )
        return dp[curr_pos][remaining];

    ll mini = inf;

    ll ones, zeros;
    ones = zeros = 0;

    for(ll i = curr_pos; i < n; i++){
        if(a[i] == 0) zeros++;
        else ones++;
        mini = min(mini, zeros*ones+explore(i+1, remaining-1));
    }

    return dp[curr_pos][remaining] = mini;
}

int main(){

    memset(dp, -1, sizeof(dp));

    scanf("%lld %lld", &n, &k);

    for(ll i = 0; i < n; i++)
        scanf("%lld", a+i);

    ll ans = explore(0, k);

    printf("%lld\n", ans);
}
