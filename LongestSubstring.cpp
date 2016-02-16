#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		const int ACSII_Max = 255;
		int str_index[ACSII_Max];
		int start = 0;
		int max_len = 0;
		fill(str_index, str_index + ACSII_Max, -1);
		for (int i = 0; i < s.size(); i++){
			if (str_index[s[i]] >= start){
				max_len = max(max_len, i - start);
				start = str_index[s[i]] + 1;
			}
			str_index[s[i]] = i;
		}  		      
		return max(max_len, (int)s.size() - start);
    }
};

int main(){	
	string s("abcdef");
	Solution s1;
	int max_len = s1.lengthOfLongestSubstring(s);
	cout << max_len << endl;
	return 0;
}