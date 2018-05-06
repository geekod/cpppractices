#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> value_index_map;
        
        value_index_map[nums[0]] = 0;
        for (int i = 1; i < (int)nums.size(); i ++) 
        {

            int pair_value = target - nums[i];
            //unordered_map<int,int>::iterator 
            auto it = value_index_map.find(pair_value);
            if (it != value_index_map.end()) //m.count(pairValue) > 0
            {
                int arr[] = {it->second, i};
                vector<int> ret(arr, end(arr));
                return ret;
            } else {
                //m[nums[i]] = i;
                //unordered_map<int, int>::value_type
                value_index_map.insert(make_pair(nums[i], i));
            }
        }
        vector<int> ret;
        return ret;
    }
};

int main() 
{
    Solution s;
    int nums_arr[] = {9, 18, 2, 7};
    size_t nums_size = sizeof(nums_arr)/sizeof(nums_arr[0]);
    vector<int> nums(nums_arr, nums_arr + nums_size);
    vector<int> result(s.twoSum(nums, 9));
    std::copy(result.begin(), result.end(), 
        std::ostream_iterator<int>(std::cout, " "));
    cout << endl;

    return 0;
}