#include <iostream>
#include <cstddef>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
  		const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  		const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

  		string Roman;
  		for (size_t i = 0; num > 0; ++i) {
  			int count = num / radix[i];
  			num %= radix[i];
  			for (; count > 0; --count) Roman += symbol[i];
  		}
  	return Roman;
    }
};

int main(){
	Solution s1;
	int num;
	cin >> num;
	string Roman = s1.intToRoman(num);
	cout << Roman;
	return 0; 
}