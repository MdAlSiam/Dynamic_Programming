#include <bits/stdc++.h>
using namespace std;

#define maxi 1000

int value[] = {-200, -100, 5, 0, 9, 2, 7, 3, 4};
int n = sizeof(value) / sizeof(int);
int dp[maxi], dir[maxi];

int longestfrom(int u){

    int& ret = dp[u];
    if(ret != -1) return ret;

    int maxlen = 0;
    for(int v = u+1; v < n; v++){
        if(value[v] > value[u]){
            if(longestfrom(v) > maxlen){
                maxlen = longestfrom(v);
                dir[u] = v;
            }
        }
    }

    return ret = 1+maxlen;
}

int main(){
    memset(dp, -1, sizeof(dp));
    memset(dir, -1, sizeof(dir));

    int start, LIS_len = 0;

    for(int i = 0; i < n; i++){
        if(longestfrom(i) > LIS_len){
            LIS_len = longestfrom(i);
            start = i;
        }
    }

    cout << "Length of LIS: " << LIS_len << endl;
    int curr = start;

    while(1){
        cout << value[curr] << " ";
        curr = dir[curr];
        if(dir[curr] == -1){
            cout << value[curr] << " ";
            break;
        }
    }
}
