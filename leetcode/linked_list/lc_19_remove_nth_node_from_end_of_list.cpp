// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * Time complexity: O(n) where n = length of linked list
 * Space complexity: O(1)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		// since we have to return a linked list, create a dummy head
		// and set it's head accordingly
        ListNode *dummyHead = new ListNode();
		dummyHead->next = head;

		// we will use slow and fast pointers to determine
		// when we are n nodes away from the end of the linked list
		// note we set slow to point to the dummy head since we want to remove
		// the n+1 node from the end, not the n node from the end
		ListNode *slow = dummyHead, *fast = head;

		// we will keep a set interval of n nodes between the slow and fast pointer
		// so move the fast pointer until it is n nodes away from the slow pointer
		for (int i = 0; i < n; ++i) {
			fast = fast->next;
		}

		// keep incrementing both pointers until the faster pointer reaches the end of the list
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}

		// now we know that the node to remove is after the slow pointer, so simply
		// update the next pointer to be the node after the one to remove
		// this removes the desired node from the linked list by skipping it.
		slow->next = slow->next->next;

		// finally return the head of the linked list
		return dummyHead->next;
    }
};
