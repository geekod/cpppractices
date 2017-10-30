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
        unordered_map<int,int> m;
        
        m[nums[0]] = 0;
        for (int i = 1; i < (int)nums.size(); i ++) 
        {

            int pairValue = target - nums[i];
            if (m.find(pairValue) != m.end()) //m.count(pairValue) > 0
            {
                int arr[] = {m[pairValue], i};
                vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
                return v;
            } else {
                //m[nums[i]] = i;
                m.insert(unordered_map<int, int>::value_type(nums[i], i));
            }
        }
        vector<int> v;
        return v;
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