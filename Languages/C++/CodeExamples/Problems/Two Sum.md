Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Will contain the ordered indexes of two elements that sum to the target 
        vector<int> ans;
        // A mapping from container value to index
        map<int, int> d;
        // For each container element
        for (int i = 0; i < nums.size(); i++) {
            // determine the number needed to sum to the target
            int t = target - nums[i];
            // check for that element value existence in the map
            if (d.find(t) != d.end()) {
                // If it exists add that elements index, as it was iterated through previously
                ans.push_back(d[t]);
                ans.push_back(i);
                break;
            }
            // add the current element value and index to the map
            d[nums[i]] = i;
        }
        //return ans as it is a constraint that there is an answer
        return ans;
    }
};