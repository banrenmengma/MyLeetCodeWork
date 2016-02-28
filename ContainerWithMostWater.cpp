#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
  		int begin = 0;
  		int end = height.size() - 1;
  		int result = 0;
  		int WaterTemp;

  		while (begin < end) {
  			WaterTemp = min(height[begin], height[end]) * (end - begin);
  			result = max(result, WaterTemp);
  			if (height[begin] < height[end]) {
  				begin++;
  			} else {
  				end--;
  			}
  		}      
  		return result;
    }
};

int main(){
	int array[] = {4, 5, 6, 3, 7, 1, 6, 8, 9, 13, 4, 6};
	std::vector<int> v(array, array + 12);
	Solution s1;
	int result = s1.maxArea(v);
	cout << result;
	return 0;
}