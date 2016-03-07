#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> result;
        string s;
        if (n > 0) generate(n, s, result, 0, 0);
        return result;
    }

    void generate(int n, string s, vector<string>& result, int l, int r) {
    	if (l == n) {
    		result.push_back(s.append(n - r, ')'));
    		return; 
    	}

    	//s.push_back('(');
    	generate(n, s + '(', result, l + 1, r);
    	//s.pop_back();

    	if (l > r) {
    		//s.push_back(')');
    		generate(n, s + ')', result, l, r + 1);
    		//s.pop_back();
    	}
    }
};

int main(){
	Solution s1;
	int n = 100;
	std::vector<string> result = s1.generateParenthesis(n);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\t';
	}
	return 0;
}