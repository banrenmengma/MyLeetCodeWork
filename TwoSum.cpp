#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mapping;
		std::vector<int> result;
		for (int i = 0; i < nums.size(); i++) mapping[nums[i]] = i;
		for (int i = 0; i < nums.size(); i++){
			const int gap = target - nums[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap] > i){
				result.push_back(i);
				result.push_back(mapping[gap]);
				
				cout << result[0] << '\t' << result[1]  << endl;
				break;
			}
		} 
		return result;
    }
};

int main(){
	int arr[5] = {2, 7, 11, 17, 3};
	std::vector<int> v(arr, arr + 5);
	Solution s1;
	s1.twoSum(v, 9);
	return 0;
}