#include <bits/stdc++.h>
using namespace std;

int position[10];
///     Will store the position of row for each column
/// where any queen exist safely

int kount = 0;
/// for counting how many combinations exist

bool isSafe(int ro, int col){
    /// To check the queen at position (ro, col) is safe or not
    /// First check risks created by the previous queens

    /// If any queen exist already in the same row
    for(int kol = col; kol > 0; kol--)
        if(position[kol] == ro) return false;

    /// If any queen already in the primary diagonal
    for(int i = ro, j = col; i > 0 && j > 0; i--, j--)
        if(position[j] == i) return false;

    /// If any queen already in the secondary diagonal
    for(int i = ro, j = col; i > 0 && j > 0; i++, j--)
        if(position[j] == i) return false;

    return true;

}

void call(int col){

    if(col == 9){
        ///     Eight queens are already placed safely for a combination
        /// Dam da dam da dam!
        /// Print this

        for(int i = 1; i <= 8; i++){
            if(i == 1) cout << "{ " << position[i] << ", ";
            else if (i == 8) cout << position[i] << " },\n";
            else cout  << position[i] << ", ";
        }

        kount++; /// A new combination found.

        return;

    }


    /// Traverse all combinations
    for(int i = 1; i <= 8; i++){
        if(isSafe(i, col)){
            ///     If the position is safe
            /// then place a queen here and move to the next column
            position[col] = i;
            call(col+1);
            position[col] = -1; ///backtrack (remove used queen to check another combination)
        }
    }
}

int main(){

    //freopen("F:\Out.txt", "w", stdout);
    memset(position, -1, sizeof position);
    /// Initially there is no queen in any row for any column
    call(1);
    /// Will start calculate from the first column
    cout << "Total = " << kount << endl;
}
