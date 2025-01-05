class Solution {
public:
    char shift(char a, int n) {
        int i = a - 'a';
        i = (i + n) % 26;
        if (i < 0)
            i += 26;
        return 'a' + i;
    }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> totShift(n + 1, 0);

        for (auto& it : shifts) {
            if (it[2] == 0) {
                totShift[it[0]]--;
                totShift[it[1] + 1]++;
            } else {
                totShift[it[0]]++;
                totShift[it[1] + 1]--;
            }
        }

        for (int i = 1; i < totShift.size(); i++)
            totShift[i] += totShift[i - 1];

        for (int i = 0; i < n; i++)
            s[i] = shift(s[i], totShift[i]);

        return s;
    }
};