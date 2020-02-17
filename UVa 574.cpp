#include <bits/stdc++.h>
using namespace std;

int target, num_of_data;
int num[200];
int occur[200];
int taken[1000];

bool noans;

void explore(int index, int now, int takingindex){
    if(now == 0){
        for(int i = 0; i < takingindex; i++)
            printf(i == 0 ? "%d" : "+%d", taken[i]);
        printf("\n");
        noans = false;
        return;
    }

    if(index >= num_of_data) return;

    if(now - num[index] >= 0 && occur[num[index]] > 0){
        taken[takingindex] = num[index];
        //cout << "taken[takingindex] = num[index]"
        //<< endl << taken[takingindex] << " " << num[index] << endl;
        occur[num[index]]--;
        explore(index+1, now-num[index], takingindex+1);
        occur[num[index]]++;
        while(num[index] == num[index+1]) index++;
    }

    explore(index+1, now, takingindex);
    //while(num[index] == num[index+1]) index++;
}

int main(){

    while(scanf("%d %d", &target, &num_of_data) == 2){
    if(num_of_data == 0) break;
    memset(occur, 0, sizeof occur);
    for(int i = 0; i < num_of_data; i++){
        scanf("%d", &num[i]);
        occur[num[i]]++;
    }
    noans = true;
    //for(int i = 0; i < num_of_data; i++){
    //   cout << ">>" << i << " " << num[i] << endl;
    //}
    printf("Sums of %d:\n", target);
    explore(0, target, 0);
    if(noans) printf("NONE\n");
    }
}
