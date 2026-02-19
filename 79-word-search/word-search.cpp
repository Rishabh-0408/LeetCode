class Solution {
public:

    bool dfs(int ind,int i, int j, vector<vector<char>>& board, string word){
        if(ind==word.size()){
            return true;
        }
        if(i<0 || j<0 || i >= board.size() || j >=board[0].size() || board[i][j] != word[ind]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(ind+1,i+1,j,board,word) || dfs(ind+1,i-1,j,board,word) || 
                     dfs(ind+1,i,j+1,board,word) || dfs(ind+1,i,j-1,board,word);
        board[i][j] = temp; 
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dfs(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};