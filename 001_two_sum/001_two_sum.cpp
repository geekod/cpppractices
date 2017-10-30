#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ret(2);
        for (int i = 0; i < nums.size(); i ++)
        {
            for (int j = 0; j < i; j ++)
            {
                if (target == nums[i] + nums[j]) {
                    ret[0] = j;
                    ret[1] = i;
                    return ret;
                }
            }
        }
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