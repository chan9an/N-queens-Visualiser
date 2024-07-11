#include <iostream>
#include <vector>
#include <unordered_set>
#include <windows.h> 
using namespace std;

void printboard(vector<string> &board){
    system("cls"); 
    int n = board.size();
    
 
    cout << "+";
    for (int i = 0; i < n; ++i)
        cout << "---+";
    cout << "\n";

 
    for(int i = 0; i < n; i++){
        cout << "|";
        for(int j = 0; j < n; j++){
            if (board[i][j] == 'Q')
                cout << " Q |"; 
            else
                cout << " . |"; 
        }
        cout << "\n";

        cout << "+";
        for (int j = 0; j < n; ++j)
            cout << "---+";
        cout << "\n";
    }
    cout << "\n";
    Sleep(60); 
}

void backtrack(int r, int n, unordered_set<int>& col, unordered_set<int>& posdiag, unordered_set<int>& negdiag, vector<string>& board, vector<vector<string>>& res) {
    if (r == n) {
        res.push_back(board);
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (col.count(c) || posdiag.count(r + c) || negdiag.count(r - c)) {
            continue;
        }

        col.insert(c);
        posdiag.insert(r + c);
        negdiag.insert(r - c);
        board[r][c] = 'Q';
        printboard(board); 
        backtrack(r + 1, n, col, posdiag, negdiag, board, res);
        col.erase(c);
        posdiag.erase(r + c);
        negdiag.erase(r - c);
        board[r][c] = '.';
        printboard(board); 
    }
}

vector<vector<string>> solveNQueens(int n) {
    unordered_set<int> col;
    unordered_set<int> posdiag; 
    unordered_set<int> negdiag; 

    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    printboard(board); 
    backtrack(0, n, col, posdiag, negdiag, board, res);
    return res;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<string>> ans = solveNQueens(n);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            for(int k = 0; k < ans[i][j].size(); k++) {
                if (ans[i][j][k] == 'Q')
                    cout << " Q "; 
                else
                    cout << " . "; 
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
