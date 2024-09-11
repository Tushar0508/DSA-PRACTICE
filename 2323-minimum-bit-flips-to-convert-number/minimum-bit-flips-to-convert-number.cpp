class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int xorr = start ^ goal;

        while(xorr != 0){
            ans += xorr & 1;
            xorr >>= 1;
        }

        return ans;
    }
};