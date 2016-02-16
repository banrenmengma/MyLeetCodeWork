#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		ListNode MyHead(1);
		ListNode *ptrnow = &MyHead;
		int carry = 0;
		for (ListNode *p1 = l1, *p2 = l2; p1 != nullptr || p2 != nullptr; p1 = p1 == nullptr ? nullptr : p1 -> next, p2 = p2 == nullptr ? nullptr : p2 -> next, ptrnow = ptrnow -> next) {
			const int v1 = p1 == nullptr ? 0 : p1 -> val;
			const int v2 = p2 == nullptr ? 0 : p2 -> val;
			const int value =  (v1 + v2 + carry) % 10;
			carry = (v1 + v2 + carry) / 10;
			ptrnow -> next = new ListNode(value);
		}
		if (carry > 0){
			ptrnow -> next = new ListNode(carry);
		}
		return MyHead.next;
	}
};

ListNode *createList(vector<int> vec){
	ListNode vecHead(1);
	ListNode *vecptr = &vecHead;
		for (int i = 0; i < vec.size(); i++, vecptr = vecptr -> next){
			vecptr -> next = new ListNode(vec[i]);
		}
		return vecHead.next;
	}

int main(){
	int arr1[] = {2, 4, 3};
	int arr2[] = {5, 6, 4};
	std::vector<int> vec1(arr1, arr1 + 3);
	std::vector<int> vec2(arr2, arr2 + 3);

	ListNode *l1 = createList(vec1);
	ListNode *l2 = createList(vec2);

	Solution s1;
	ListNode* s1show = s1.addTwoNumbers(l1, l2);
	cout << s1show->val << (*s1show->next).val << (*((s1show->next)->next)).val <<endl;
	return 0;
}