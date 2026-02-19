class Solution {
public:
    bool isSafe(int col,int row, vector<string>& board, int n){
        for(int j=0; j<col; j++){
            //checking each col of the same row 
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            //checking for the upper diagonal
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=row,j=col;i<n && j>=0;i++,j--){
            //checking for the lower diagonal
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void toCheck(int col,int n, vector<string>& board,vector<vector<string>>& ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(col,row,board,n)){
                board[row][col] = 'Q';
                toCheck(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        toCheck(0,n,board,ans);
        return ans;
    }
};