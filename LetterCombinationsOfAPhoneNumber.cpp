#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

class Solution {
public:
	const std::vector<string> keyboard {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", 
		"tuv", "wxyz"};

    vector<string> letterCombinations(string& digits) {
         std::vector<string> result;
         if (digits.empty()) return result;
         dfs(digits, 0, "", result);
         return result;
    }

    void dfs(const string &digits, size_t cur, string path, std::vector<string> &result) {
    	if (cur == digits.size()) {
    		result.push_back(path);
    		return;
    	}
    	for (auto c : keyboard[digits[cur] - '0']) {
    		dfs(digits, cur + 1, path + c, result);
    	}
    }
};

int main() {
	Solution s1;
	string digits;
	cin >> digits;
	std::vector<string> result = s1.letterCombinations(digits);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\t'; 
 	return 0;
}