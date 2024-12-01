class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<float, bool> hash;
        for (float i: arr) {
            if (hash.find(i*2) != hash.end() || hash.find(i/2) != hash.end()) {
                return true;
            } else {
                hash[i] = true;
            }
        }
        return false;
    }
};