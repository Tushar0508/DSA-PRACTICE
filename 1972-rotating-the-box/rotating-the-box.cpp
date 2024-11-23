class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<char>>res(n,vector<char>(m,'.'));
        for(int i=0;i<n;i++){
            int mostright=m-1;
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='.'){
                    
                    res[i][j]='.';
                }
                else if(box[i][j]=='*'){
                    mostright=j-1;
                    res[i][j]='*';
                }
                else{
                    res[i][j]='.';
                    res[i][mostright]='#';
                    mostright--;
                }
            }
        }
        vector<vector<char>>ans(m,vector<char>(n,'0'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][n-i-1]=res[i][j];
            }
        }
        return ans;
        
    }
};