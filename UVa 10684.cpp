#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1 << 28

void printans(ll* ara, ll len){
    ll max_so_far = -inf;
    ll max_ending_here = 0;
    ll start = 0;
    ll stop = 0;
    ll tempstart = 0;

    bool found = false;

    for(ll i = 0; i < len; i++){
        /*if(ara[i] < 0){
            max_ending_here = 0;
            tempstart = i+1;
            continue;
        }*/

        max_ending_here += ara[i];

        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
            start = tempstart;
            stop = i;
            found = true;
        }

        if(max_ending_here < 0){
            max_ending_here = 0;
            tempstart = i+1;
        }
    }

    //cout << "Start = " << start << " Stop = " << stop << endl;

    if(found && max_so_far > 0) printf("The maximum winning streak is %lld.\n", max_so_far);
    else printf("Losing streak.\n");
}

int main(){
    ll n;
    while(scanf("%lld", &n) == 1){
        if(n == 0) break;
        ll ara[n+3];
        for(ll i = 0; i < n; i++) scanf("%lld", ara+i);
        printans(ara, n);
    }
}
