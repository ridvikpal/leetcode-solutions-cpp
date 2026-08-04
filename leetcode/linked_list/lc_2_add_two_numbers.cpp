// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * Time complexity: O(n) where n = max(length of l1, length of l2)
 * Space complexity: O(n) where n = sum of length l1 and l2
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// first create a dummy head because we will have to return a new linked list
        ListNode* dummyHead = new ListNode();
		// set the current pointer to the dummy head
		ListNode* current = dummyHead;

		// keep an overflow counter in case
		bool overflow = false;

		// loop as long as we are not through processing both linked lists and the overflow counter
		while (l1 != nullptr || l2 != nullptr || overflow) {
			// init the result for each digit's sum.
			int result = 0;

			// if we still have digits in the first linked list
			// then add it's value to the result and move it's pointer
			// to the next digit in the first linked list
			if (l1 != nullptr) {
				result += l1->val;
				l1 = l1->next;
			}

			// if we still have digits in the second linked list
			// then add it's value to the result and move it's pointer
			// to the next digit in the second  linked list
			if (l2 != nullptr) {
				result += l2->val;
				l2 = l2->next;
			}

			// if we have an overflow, then increment the result
			// and reset the overflow counter
			if (overflow) {
				++result;
				overflow = false;
			}

			// if the result is greater than 10, set the overflow counter
			// and decrement the result
			if (result >= 10) {
				overflow = true;
				result = result-10;
			}

			// create a new linked list node with the result
			// and add to the next pointer of the current linked list
			current->next = new ListNode(result);
			// move the current pointer to this newly created linked list node
			current = current->next;
		}

		// finally, return the head of the resultant linked list
		return dummyHead->next;
    }
};
