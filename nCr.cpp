#include <bits/stdc++.h>
using namespace std;

int dp[5000][5000];

int find_nCr(int n, int r){
    if(r == n) return 1;
    if(r == 1) return n;

    int &ret = dp[n][r];
    if(ret != -1) return ret;

    ret = find_nCr(n-1, r) + find_nCr(n-1, r-1);

    return ret;
}


int main(){
    int n, r;
    while(cin >> n >> r){
        memset(dp, -1, sizeof(dp));
        cout << find_nCr(n, r) << endl;
    }
}
