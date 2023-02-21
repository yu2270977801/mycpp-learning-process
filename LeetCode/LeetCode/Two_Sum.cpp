/*
* 题目：两数之和
* 描述：
* 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
* 
* 题目链接：https://leetcode.cn/problems/two-sum/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int num[];
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();

        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++)
            {
                if (nums[i] + nums[j] == target)
                    return { i,j };
            }
        }
        return {};
    }
};

int main()
{
    vector<int> nums;
    int target;
    int len_nums;   //数组长度
    cout << "请输入数组长度：" << endl;
    cin >> len_nums;
    cout << "请输入数组：" << endl;
    for (int i = len_nums; i > 0; i--)
    {
        int x = 0;
        cin >> x;
        nums.push_back(x);
    }
    cout << "请目标值：" << endl;
    cin >> target;
    Solution solution;
    vector<int> numss = solution.twoSum(nums,target);
    cout << "数组下标值为：";
    for (vector<int>::iterator it = numss.begin(); it != numss.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
