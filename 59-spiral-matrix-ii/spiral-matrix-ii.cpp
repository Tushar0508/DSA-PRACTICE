class Solution {
public:
    void forward(int &n, vector<vector<int>> &res, int &i, int &j, int &count) {
        while(j < n) {
            if(res[i][j] != 0) return;
            res[i][j++] = count++;
        }
    }
    void downward(int &n, vector<vector<int>> &res, int &i, int &j, int &count) {
        while(i < n) {
            if(res[i][j] != 0) return;
            res[i++][j] = count++;
        }
    }
    void backward(int &n, vector<vector<int>> &res, int &i, int &j, int &count) {
        while(j >= 0) {
            if(res[i][j] != 0) return;
            res[i][j--] = count++;
        }
    }
    void upward(int &n, vector<vector<int>> &res, int &i, int &j, int &count) {
        while(i >= 0) {
            if(res[i][j] != 0) return;
            res[i--][j] = count++;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0, count = 1;
        while(count <= n*n) {
            forward(n, res, i, j, count);
            --j;
            ++i;
            downward(n, res, i, j, count);
            --i;
            --j;
            backward(n, res, i, j, count);
            ++j;
            --i;
            upward(n, res, i, j, count);
            ++i;
            ++j;
        }
        return res;
    }
};