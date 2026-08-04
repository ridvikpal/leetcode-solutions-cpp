// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * Time complexity: O(n) where n = sum of length of linked lists list1 and list2
 * Space complexity: O(1)
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // first handle edge cases where we are given either 1 linked list
        // or no linked lists at all
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        } else if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        // init our head pointers for each linked list
        ListNode *head1 = list1;
        ListNode *head2 = list2;

        // init the current pointer which will hold the current node we are comparing
        ListNode *current = nullptr;

        // set the current node to the one which has the smallest value
        // between the two linked lists
        // and update the according head pointers
        if (head1->val < head2->val) {
            current = head1;
            head1 = head1->next;
        } else {
            current= head2;
            head2 = head2->next;
        }

        // create a head pointer to store the head of the linked list
        ListNode *head = current;

        // loop as long as there are nodes left to compare between the two linked lists
        while (head1 != nullptr && head2 != nullptr) {
            // set the current node to the one which has the smallest value
            // between the two linked lists
            // and update the according head pointers
            if (head1->val < head2->val) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }

            // update the current pointer to the next node we just added
            current = current->next;
        }

        // now check if either list 1 or 2 still has nodes
        // and if they do, simply append all the nodes to the current node list
        // we have so far
        if (head1 != nullptr) {
            current->next = head1;
        } else if (head2 != nullptr) {
            current->next = head2;
        }

        // finally return the head of the merged linked list
        return head;
    }
};
