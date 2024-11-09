class Solution {
public:
    long long minEnd(int n, int x) {
        string s, sx;
        int temp = --n;
        while (temp > 0) {
            s += (temp % 2) + '0';
            temp /= 2;
        }
        temp = x;
        while (temp > 0) {
            sx += (temp % 2) + '0';
            temp /= 2;
        }
        cout << s << ' ' << sx << endl;
        long long i = 0;
        for (char c : s) {
            while (i < sx.size() && sx[i] == '1') ++i;
            if (i < sx.size()) sx[i] = c;
            else sx += c;
            ++i;
        }
        cout << sx;
        long long ans = 0;
        for (long long i = 0; i < sx.size(); ++i) {
            ans += (sx[i] - '0') * pow(2, i);
        }
        return ans;
    }
};