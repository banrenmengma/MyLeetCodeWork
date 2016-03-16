#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	if (nums.size() <= 1) return;
    	for (int i = nums.size() - 1; i > 0; i--) {
    		int j = i - 1;
    		int k = nums.size() - 1;
    		if (nums[j] < nums[i]) {
    			while (nums[k] <= nums[j]) {
    				k--;
    			}
    			swap(nums[j], nums[k]);
    			reverse(nums.begin() + i, nums.end());
    			return;
    		}
    	}
    	reverse(nums.begin(), nums.end());
    }
};

int main() {
	int array[] = {1, 1};
	std::vector<int> v(begin(array), end(array));
	Solution s1;
	s1.nextPermutation(v);
	for (auto i = v.begin(); i != v.end(); i++) 
		cout << *i << '\t';
	return 0;
}