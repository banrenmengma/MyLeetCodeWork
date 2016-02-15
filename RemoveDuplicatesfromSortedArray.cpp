#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// class Solution
// {
// public:
// 	int RemoveDuplicates(std::vector<int>& nums){
// 		if (nums.empty()) return 0;

// 		int index = 0;
// 		for (int i = 0; i < nums.size(); i++) {
// 			if (nums[index] != nums[i])
// 				nums[++index] = nums[i];
// 		}
// 		return index + 1;
// 	}
// };

class Solution {
public:
int RemoveDuplicates(vector<int>& nums) {
return distance(nums.begin(), unique(nums.begin(), nums.end()));
}
};

int main(){
	int arr[3] = {1, 1, 2}; 
	std::vector<int> v(arr, arr + 3);
	Solution s1;
	//s1.RemoveDuplicates(v);
	cout << v[0] << v[1] << v[2] << endl; 
	return 0;
}