#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

vector<int> getFloorAndCeil(vector<int> nums, int x)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = 0;
    vector<int> ans(2,-1); 
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (x == nums[mid])
        {
            ans[0]=nums[mid]; // If x is found, both floor and ceil are x
            ans[1]=nums[mid];
            return ans;
        }
        if (x > nums[mid])
        {
            ans[0] = nums[mid]; // Update floor
            s = mid + 1;
        }
        else
        {
            ans[1] = nums[mid]; // Update ceil
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3,4,4,7,8,10};
    int x = 5;
    vector<int> result = getFloorAndCeil(nums, x);
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;
    return 0;
}
