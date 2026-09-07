class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int start, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            if(i > start && candidates[i] == candidates[i - 1])
                continue;

            if(candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            solve(candidates, i + 1, target - candidates[i]);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        solve(candidates, 0, target);

        return ans;
    }
};