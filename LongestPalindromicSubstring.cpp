#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string prProcess(string s){
		int Len = s.length();
		if (Len == 0) return "^$";
		string ret = "^";
		for (int i = 0; i < Len; i++){
			ret += "#" + s.substr(i, 1);
		}
		ret += "#$";
		return ret;
	}

    string longestPalindrome(string s) {
  		string T = prProcess(s);
  		int Len = T.length();
  		int *P = new int[Len];
  		int C = 0, R = 0;
  		for (int i = 1; i < Len - 1; i++){
  			int i_mirror = 2*C - i;
  			P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

  			while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
  				P[i]++;

  			if (i + P[i] > R){
  				C = i;
  				R = i + P[i];
  			}
  		}

  		int maxLen = 0;
  		int centerIndex = 0;
  		for (int i = 1; i < Len - 1; i++){
  			if (P[i] > maxLen){
  				maxLen = P[i];
  				centerIndex = i;
  			}
  		}
  		delete[] P;

  		return s.substr((centerIndex - 1 - maxLen)/2, maxLen); 
    }
};

int main(){
	Solution s1;
	string s("lkajogaojgoajhhanihiajgojoajhiahgojaljgoahgoa");
	string longestSubstring = s1.longestPalindrome(s);
	cout << longestSubstring << endl;
	return 0;
}