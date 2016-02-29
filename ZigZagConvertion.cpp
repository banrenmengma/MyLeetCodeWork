#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
  		if (numRows == 1 || s.length() <= 1) return s;
  		string result;
  		for (int i = 0; i < numRows; i++){
  			for (int j = 0, index = i; index < s.length(); j++, index = 2*(numRows - 1)*j + i){
  				result.append(1, s[index]);
  				if (i == 0 || i == numRows - 1) continue;
  				if (index + 2*(numRows - 1 - i) < s.length())
  					result.append(1, s[index + 2*(numRows - 1 - i)]);
  			}
  		}      
  		return result;
    }
};

int main(){
	string s("PAYPALISHIRING");
	Solution s1;
	string result = s1.convert(s, 3);
	cout << result <<endl;
	return 0;
}