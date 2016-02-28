#include <iostream>
#include <cstddef>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string& s) {
        const int radix[] = {1000, 500, 100, 50, 10, 5, 1};
  		const char symbol[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
  		map<char, int> mapping;
  		for (int i = 0; i < 7; i++) mapping[symbol[i]] = radix[i];
  		int result = 0;	
  		for (size_t j = 0; j < s.length(); j++) {
  			if (mapping[s[j]] < mapping[s[j + 1]]) {
  				result += mapping[s[j + 1]] - mapping[s[j]];
  				j++;
  			} else {
  				result += mapping[s[j]];
  			}
  		}
  		return result;
    }
};

int main(){
	Solution s1;
	string Roman;
	cin >> Roman;
	int num = s1.romanToInt(Roman);
	cout << num;
	return 0;
}