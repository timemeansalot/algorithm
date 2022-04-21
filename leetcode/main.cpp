#include "headfile.h"
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {

        vector<int> diff(n); // 差分数组
        vector<int> nums(n);

        cout << nums.size() << " " << diff.size() << endl;
        // 计算差分数组
        for (int i = 0; i < bookings.size(); i++)
        {
            diff[bookings[i][0] - 1] += bookings[i][2];
            diff[bookings[i][1]] -= bookings[i][2];

            // print diff
            for (auto d : diff)
                cout << d << " ";
            cout << endl;
        }

        // 由差分数组计算nums数组
        nums[0] = diff[0];
        for (int i = 1; i < n; i++)
        {
            nums[i] = nums[i - 1] + diff[i];
        }

        return nums;
    }
};

int main()
{

    vector<vector<int>> bookings{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;

    Solution s;

    vector<int> nums = s.corpFlightBookings(bookings, n);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}