class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<pair<int, int>> ordered; 


        int noOfGroups = nums.size();
        for(int i = 0; i<noOfGroups; i++)
        {
            for(auto n: nums[i])
            {
                ordered.push_back({n, i});
            }
        }

        sort(ordered.begin(), ordered.end());


        int group = 0;
        int i = 0;

        vector<int> ans;
        unordered_map<int, int> group_count;

        for(int j = 0; j<ordered.size(); j++)
        {
            if(!group_count[ordered[j].second]++) group++;

            if(group == noOfGroups)
            {
                while (group_count[ordered[i].second] > 1) --group_count[ordered[i++].second];

                if(ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first)
                ans = vector<int>{ordered[i].first, ordered[j].first};
            }
        }

        return ans;


    }
};