#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<string>& board,int row,int col){
    int x = row;
    int y = col;

    for (int i = x; i >= 0;i--){
        if(board[i][y] == 'Q'){
            return false;
    }
    }

    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    for (int i = x, j = y; i >= 0 && j < 8; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
    
}


void solve(vector<string> &board, int row, ll &cnt) {
    if (row == 8) {
        cnt++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if(board[row][col] == '.' && check(board,row,col)){
            board[row][col] = 'Q';
            solve(board, row + 1, cnt);
            board[row][col] = '.';
        }
    }

    return;
}

int main(){
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    ll cnt = 0;
    solve(board, 0, cnt);   
    cout << cnt << "\n";
    return 0;
}