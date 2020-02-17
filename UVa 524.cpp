#include <bits/stdc++.h>
using namespace std;

#define maxnum 26

int lastnum;
int ansara[maxnum];
bool taken[maxnum];

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool isPrime(int n){
    int siz = sizeof(primes) / sizeof(int);
    for(int i = 0; i < siz; i++){
        if(primes[i] == n)
            return true;
    }
    return false;
}


void explore(int index){

    if(index == lastnum+1){
        if(isPrime(ansara[lastnum]+1)){
            printf("1");
            for(int i = 2; i < index; i++){
                printf(" %d", ansara[i]);
            }
            printf("\n");
        }
        return;
    }

    for(int i = 2; i <= lastnum; i++){
        if( isPrime(ansara[index-1]+i) && !taken[i]){
            ansara[index] = i;
            taken[i] = true;
            explore(index+1);
            taken[i] = false;
        }
    }
}

int main(){
    int kase = 0;
    bool first = true;

    while(scanf("%d", &lastnum) == 1){
        if(!first) printf("\n");
        first = false;
        printf("Case %d:\n", ++kase);
        memset(taken, false, sizeof(taken));
        ansara[1] = 1;
        explore(2);
    }
}
