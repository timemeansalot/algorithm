#include "headfile.h"
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {

        vector<int> diff(10);
        vector<int> nums(10);

        // 构造diff数组
        for (int i = 0; i < trips.size(); i++)
        {
            if (trips[i][1] - 1 >= 0)
                diff[trips[i][1] - 1] -= trips[i][0];
            else
                diff[0] -= trips[i][0];

            if (trips[i][2] < diff.size())
                diff[trips[i][2]-1] += trips[i][0];

            // print diff
            for (auto d : diff)
                cout << d << " ";
            cout << endl;
        }

        // 计算nums数组
        nums[0] = capacity+diff[0];
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = diff[i] + nums[i - 1];
            if (nums[i] < 0)
                    return false;
        }
        return true;
    }
};

int main()
{

    vector<vector<int>> bookings{{3,5,9}, {4,2,5},{3,4,6},{9,1,4},{5,6,8},{5,4,6}};
    int n = 14;

    Solution s;

    bool p = s.carPooling(bookings, n);
    cout << p << endl;
    return 0;
}