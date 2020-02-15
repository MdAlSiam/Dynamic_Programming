#include <bits/stdc++.h>
using namespace std;

#define inf 1 << 28

int mat[256][112];
int dp[256][112];
int n;

int call(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];

    int ret = -inf;

    if(i == 2*n-2) return mat[i][0];

    else if(i < n-1){
        ret = max(ret, mat[i][j]+call(i+1, j));
        ret = max(ret, mat[i][j]+call(i+1, j+1));
    }
    else if(j == 0){
        ret = max(ret, mat[i][j]+call(i+1, 0));
    }
    else if(mat[i+1][j] == 0){
        ret  = max(ret, mat[i][j]+call(i+1, j-1));
    }
    else{
        ret = max(ret, mat[i][j]+call(i+1, j-1));
        ret = max(ret, mat[i][j]+call(i+1, j));
    }

    return dp[i][j] = ret;
}

int main(){
    int test, tc = 0;
    scanf("%d", &test);

    while(test--){

        scanf("%d", &n);

        memset(dp, -1, sizeof (dp));
        memset(mat, 0, sizeof (mat));

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                scanf("%d", &mat[i][j]);
                //cout << "taken for " << i << " " << j << " = " << mat[i][j] << endl;
            }
        }

        for(int i = n; i < 2*n-1; i++){
            for(int j = 0; j < 2*n -1 - i; j++){
                scanf("%d", &mat[i][j]);
                //cout << "taken for " << i << " " << j << " = " << mat[i][j] << endl;
            }
        }

        ///print
        /*for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                printf("%d ", mat[i][j]);
            }
            cout << endl;
        }

        for(int i = n; i < 2*n-1; i++){
            for(int j = 0; j < 2*n -1 - i; j++){
                printf("%d ", mat[i][j]);
            }
            cout << endl;
        }

        cout << "Printed\n";*/

        printf("Case %d: %d\n", ++tc, call(0, 0));
    }
}
