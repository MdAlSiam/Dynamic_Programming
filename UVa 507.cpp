#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1 << 28

ll kase = 0;

void printans(ll* ara, ll len){
    ll max_so_far = -inf;
    ll max_ending_here = 0;
    ll start = 0;
    ll stop = 0;
    ll tempstart = 0;

    ll maxlen = -inf;
    //ll finalstart = 0;
    //ll finalstop = 0;

    bool found = false;

    for(int i = 0; i < len; i++){

        max_ending_here += ara[i];

        if(max_so_far < max_ending_here && max_ending_here > 0){
            found = true;
            max_so_far = max_ending_here;
            start = tempstart;
            stop = i;
            maxlen = stop - start;


            /*if(stop - start > maxlen){
                maxlen = stop - start;
                finalstart = start;
                finalstop = stop;
            }*/
        }

        else if(max_so_far == max_ending_here && max_ending_here > 0){
            if(i - tempstart > maxlen){
                stop = i;
                start = tempstart;
            }
        }

        if(max_ending_here < 0){
            max_ending_here = 0;
            tempstart = i+1;
        }
    }

    if(found)
    printf("The nicest part of route %lld is between stops %lld and %lld\n", ++kase, start+1, stop+2);
    else printf("Route %lld has no nice parts\n", ++kase);

}

int main(){
    ll test;
    scanf("%lld", &test);

    while(test--){
        ll n;
        scanf("%lld", &n);
        ll ara[n+3];
        for(ll i = 0; i < n-1; i++)
            scanf("%lld", ara+i);
        printans(ara, n-1);
    }
}
