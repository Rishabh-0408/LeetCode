class Solution {
public:
    void toCheck(int col,int n, vector<string>& board,vector<vector<string>>& ans, vector<int>& leftrows,vector<int>& upperDiagonal, vector<int>& lowerDiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
       for(int row = 0; row < n; row++){
        if(leftrows[row] == 0 && upperDiagonal[n-1+col-row] == 0 && lowerDiagonal[row+col] == 0){
            board[row][col] = 'Q';
            leftrows[row] = 1;
            upperDiagonal[n-1+col-row] = 1;
            lowerDiagonal[row+col] = 1;

            toCheck(col+1,n,board,ans,leftrows,upperDiagonal,lowerDiagonal);

            board[row][col] = '.';
            leftrows[row] = 0;
            upperDiagonal[n-1+col-row] = 0;
            lowerDiagonal[row+col] = 0;

        }
       }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        vector<int> leftrows(n,0);
        vector<int> lowerDiagonal(2*n-1,0);
        vector<int> upperDiagonal(2*n-1,0);
        toCheck(0,n,board,ans,leftrows,upperDiagonal,lowerDiagonal);
        return ans;
    }
};