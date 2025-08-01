#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);  // Found a valid combination
            return;
        }
        if (target < 0) {
            return;  // Exceeded target, stop
        }

        for (int i = start; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, combination, result); // Reuse same element
            combination.pop_back();  // Backtrack
        }
    }
};
