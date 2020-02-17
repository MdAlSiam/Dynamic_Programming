#include <bits/stdc++.h>
using namespace std;

int tracks[26];
int mat[26][100005];
int total_length, number_of_tracks;

int makematrix(){
    for(int i = 0; i <= number_of_tracks; i++){
        for(int j = 0; j <= total_length; j++){
            if(i == 0 || j == 0) mat[i][j] = 0;
            else if(j < tracks[i]) mat[i][j] = mat[i-1][j];
            else mat[i][j] = max(mat[i-1][j], tracks[i] + mat[i-1][j-tracks[i]]);
        }
    }
    return mat[number_of_tracks][total_length];
}

void traverse_print(){
    int taken[22], index = 0;
    int xp = number_of_tracks, yp = total_length;
    while(1){
        if(xp == 0 || yp == 0){break;}
        else if(mat[xp-1][yp] == mat[xp][yp]) xp--;
        else{
            taken[index++] = tracks[xp];
            yp -= tracks[xp];
            xp--;
        }
    }
    for(int i = index-1; i >= 0; i--) printf("%d ", taken[i]);
}

int main(){
    while(scanf("%d %d", &total_length, &number_of_tracks) == 2){
        for(int i = 1; i <= number_of_tracks; i++) scanf("%d", &tracks[i]);
        int ans = makematrix();
        traverse_print();
        printf("sum:%d\n",ans);
    }
    return 0;
}
