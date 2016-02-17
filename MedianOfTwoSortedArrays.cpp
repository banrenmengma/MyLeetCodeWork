#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  		const int m = nums1.size();
  		const int n = nums2.size();
  		const int total = m + n;
  		if (total % 2 == 1)
  			return find_kth(nums1.begin(), m, nums2.begin(), n, total/2 + 1);
  		else
  			return (find_kth(nums1.begin(), m, nums2.begin(), n, total/2) + find_kth(nums1.begin(), m, nums2.begin(), n, total/2 + 1))/2.0;

    }

private:
	static int find_kth(std::vector<int>::iterator index1, int m, std::vector<int>::iterator index2, int n, int k){
		if (m > n) return find_kth(index2, n, index1, m, k);
		if (m == 0) return *(index2 + k - 1);
		if (k == 1) return min(*index1, *index2);

		int a = min(k/2, m), b = k - a;
		if (*(index1 + a - 1) < *(index2 + b - 1)) {
			return find_kth(index1 + a, m - a, index2, n, k - a);
		}
		else if (*(index1 + a - 1) > *(index2 + b - 1)) {
			return find_kth(index1, m, index2 + b, n - b, k - b);
		}
		else
			return index1[a - 1];
	}
};

int main(){
	int array1[] = {3, 4, 6, 8, 9, 10};
	int array2[] = {2, 5, 6, 7, 11};
	std::vector<int> v1(array1, array1 + 6);
	std::vector<int> v2(array2, array2 + 5);
	Solution s1;
	double mid = s1.findMedianSortedArrays(v1, v2);
	cout << mid << endl;
	return 0;
}