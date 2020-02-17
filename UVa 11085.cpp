#include <bits/stdc++.h>
using namespace std;

#define inf 1 << 28

int position[10];
int table[92][8];
int tab_index = 0;

bool isSafe(int ro, int col){
    for(int kol = col; kol  > 0; kol--)
        if(position[kol] == ro) return false;

    for(int i = ro, j = col; i > 0 && j > 0; i--, j--)
        if(position[j] == i) return false;

    for(int i = ro, j = col; i > 0 && j > 0; i++, j--)
        if(position[j] == i) return false;

    return true;
}

void call(int col){
    if(col == 9){
        for(int i = 1; i <= 8; i++){
            table[tab_index][i-1] = position[i];
        }
        tab_index++;
        return;
    }

    for(int i = 1; i <= 8; i++){
        if(isSafe(i, col)){
            position[col] = i;
            call(col+1);
            position[col] = -1;
        }
    }
}

void precalculation(){
    memset(position, -1, sizeof position);
    call(1);
}

int main(){

    precalculation();
    int input[8], tc = 0;

    while(scanf("%d", &input[0]) == 1){
        for(int i = 1; i < 8; i++) scanf("%d", &input[i]);
        int ans = inf, curr;

        for(int i = 0; i < 92; i++){
            curr = 0;
            for(int j = 0; j < 8; j++){
                if(table[i][j] != input[j]) curr++;
            }
            ans = min(ans, curr);
        }

        printf("Case %d: %d\n", ++tc, ans);
    }
}
