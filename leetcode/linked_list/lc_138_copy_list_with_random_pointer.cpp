#include <cstddef>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/**
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * Time complexity: O(n) where n = length of linked list to copy
 * Space complexity: O(n) where n = length of linked list to copy
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
		// we will use a hashmap to keep track of which
		// old nodes have been deep copied to a matching new node
        std::unordered_map<Node*, Node*> oldToNew;

		// init our current old pointer to be the head node
		Node* current = head;

		// loop as long as we have not gone through the entire linked list
		while (current != nullptr) {
			// if the old node does not have a deep copy of the current node
			// then create a new deep copy of the node for it and store it in the hashmap
			if (!oldToNew.contains(current)) {
				Node* newCurrent = new Node(current->val);
				oldToNew[current] = newCurrent;
			}

			// if the next node for the current old pointer exists
			// then check if we have a deep copy of that next node
			// if not, then create that deep copy of the next node and store it in the hashmap
			// and set the new current's next node to be the new next node
			if (current->next != nullptr) {
				if (!oldToNew.contains(current->next)) {
					Node* newNext = new Node(current->next->val);
					oldToNew[current->next] = newNext;
				}

				oldToNew[current]->next = oldToNew[current->next];
			}

			// if the random node for the current old pointer exists
			// then check if we have a deep copy of that random node
			// if not, then create that deep copy of the random node and store it in the hashmap
			// and set the new current's random node to the new random node
			if (current->random != nullptr) {
				if (!oldToNew.contains(current->random)) {
					Node *newRandom = new Node(current->random->val);
					oldToNew[current->random] = newRandom;
				}

				oldToNew[current]->random = oldToNew[current->random];
			}

			// finally, move the current old node to the next one
			current = current->next;
		}

		// finally return the new deep copied head.
		return oldToNew[head];
    }
};
