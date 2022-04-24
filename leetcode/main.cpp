#include "headfile.h"

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        // left most item
        int left = 0, right = nums.size() - 1, mid = 0;
        vector<int> res;
        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        if (left >= nums.size())
            res.push_back(-1);
        else if (nums[left] != target)
            res.push_back(-1);
        else
            res.push_back(left);

        // right most target
        left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                left = mid + 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (target < nums[mid])
                right = mid - 1;
        }

        if (right < 0)
            res.push_back(-1);
        else if (nums[left-1] != target)
            res.push_back(-1);
        else
            res.push_back(left-1);

        return res;
    }
};

int main()
{

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution s;
    vector<int> res = s.searchRange(nums, target);
    cout << res[0] << " " << res[1] << endl;
}

//-214748364
//-2147483648
