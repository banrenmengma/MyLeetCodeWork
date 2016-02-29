#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() < 3) return result;

        auto last = nums.end() - 1;
        for (auto begin = nums.begin(); begin < last - 1; begin++) {
        	auto i = begin + 1;
        	if (begin > nums.begin() && *begin == *(begin - 1)) continue;
        	auto end = last;
        	while (i < end) {
        		int gap = 0 - *begin - *end;
        		if (*i < gap) {
        			++i;
        			while (*i == *(i - 1) && i < end) ++i;
        		} else if(*i > gap) {
        			--end;
        			while (*end == *(end + 1) && i < end) --end;	
        		} else {
        			result.push_back({*begin, *i, *end});
        			++i;
        			--end;
        			while (*i == *(i - 1) && *end == *(end + 1) && i < end) ++i;
        		}
        	}
        }
        return result;
    }
};

int main(){
	Solution s1;
	int array[] = {-1, 0, 1, 2, -1, -4};
	std::vector<int> v(array, array + 6);
	vector<vector<int>> result = s1.threeSum(v);
	for (int i = 0; i < result.size(); i++)
		for (int j = 0; j < 3; j++)
			if ((j + 1) % 3 != 0) {
				cout << result[i][j] << '\t';
			} else {
				cout << result[i][j] << '\t' << endl;
			}
	return 0;
}