#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
  		 sort(nums.begin(), nums.end());
  		 int result = *nums.begin() + *(nums.begin() + 1) + *(nums.begin() + 2);
  		 auto last = nums.end() - 1;
  		 for (auto begin = nums.begin(); begin < last - 1; begin++) {
  		 	auto end = last;
  		 	auto i = begin + 1;
  		 	while (i < end) {
  		 		if (*begin + *i + *end < target) {
  		 			if (abs(*begin + *i + *end - target) < abs(result - target))
  		 			result = *begin + *i + *end;
  		 			i++;
  		 		} else if (*begin + *i + *end > target) {
  		 			if (abs(*begin + *i + *end - target) < abs(result - target))
  		 			result = *begin + *i + *end;
  		 			end--;
  		 		} else {
  		 			return result = target;
  		 		}
  		 	}
  		 }
  		 return result;
    }
};

int main() {
	Solution s1;
	int array[] = {-1, 2, 1, -4};
	int target = 1;
	std::vector<int> v(array, array + 4);
	int result = s1.threeSumClosest(v, target);
	cout << result;
	return 0; 
}