#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string& s) {
  		string left = "([{";
  		string right = ")]}";
  		stack<char> stk;

  		for (auto c : s) {
  			if (left.find(c) != string::npos) {
  				stk.push(c);
  			} else {
  				if (stk.empty() || stk.top() != left[right.find(c)])
  					return false;
  				else
  					stk.pop();
  			}
  		}    
  		return stk.empty();
    }
};

int main(){
	Solution s1;
	string s = "xg9a0ga9gaa(cga)ch";
	bool result = s1.isValid(s);
	cout << result;
	return 0;
}