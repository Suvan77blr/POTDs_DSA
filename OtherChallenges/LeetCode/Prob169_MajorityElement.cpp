
// 080325
/*
   169. Majority Element.

   Given an array nums of size n, return the majority element.

	The majority element is the element that appears more than [n / 2] times. 
	You may assume that the majority element always exists in the array.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
	public:
		int majorityElement(vector<int>& nums)
		{
			int n=nums.size();
			int majLevel = n/2;

			unordered_map<int, int> ump;
			for(const int ele : nums)
			{
				if(ump[ele] >= majLevel) {
					return ele;
				}
				ump[ele]++;
			}
			return -1;
		}
};

int main(void) {
	int n;
	cout << "Enter array size : ";
	cin >> n;

	vector<int> nums(n);
	cout << "Enter the " << n << " elements : ";
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}

	int majorityElement = Solution().majorityElement(nums);
	cout << "Majority Element : " << majorityElement << endl;

	return 0;
}

/*
	TCs:-
	1) Input: nums = [3,2,3]
	   Output: 3

	2) IP: [2,2,1,1,1,2,2]
	   OP: 2

*/
