class Solution {
private:
    bool isValid(vector<vector<int>>& board){
        bool chk1 = board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3;
        bool chk2 = board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0;

        return chk1 && chk2;
    }
    
    string boardToString(vector<vector<int>>& board){
        string tmp = "";
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                tmp += to_string(board[i][j]);
            }
        }
        return tmp;
    }

    unordered_map<string, int> memo;
    int ans = INT_MAX;

    void solve(vector<vector<int>>& board, int move, int indx, int indy){
        if(isValid(board)){
            ans = min(ans, move);
            return;
        }

        string converted = boardToString(board);
        if(memo.find(converted) != memo.end() && memo[converted] <= move){ 
            return;
        }
        memo[converted] = move;

        // Possible moves:
        // down
        if(indx + 1 < 2){
            swap(board[indx][indy], board[indx + 1][indy]);
            solve(board, move + 1, indx + 1, indy);
            swap(board[indx][indy], board[indx + 1][indy]);
        }
        // up
        if(indx - 1 >= 0){
            swap(board[indx][indy], board[indx - 1][indy]);
            solve(board, move + 1, indx - 1, indy);
            swap(board[indx][indy], board[indx - 1][indy]);
        }
        // right
        if(indy + 1 < 3){
            swap(board[indx][indy], board[indx][indy + 1]);
            solve(board, move + 1, indx, indy + 1);
            swap(board[indx][indy], board[indx][indy + 1]);
        }
        // left
        if(indy - 1 >= 0){
            swap(board[indx][indy], board[indx][indy - 1]);
            solve(board, move + 1, indx, indy - 1);
            swap(board[indx][indy], board[indx][indy - 1]);
        }
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int indx = 0, indy = 0;
        // track the move-able piece i.e. 0 
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 0){
                    indx = i;
                    indy = j;
                    break;
                }
            }
        }

        solve(board, 0, indx, indy);

        return (ans == INT_MAX) ? -1 : ans;
    }
};