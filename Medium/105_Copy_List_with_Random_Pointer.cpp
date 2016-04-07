/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// O(1) space
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        copy_next(head);
        copy_random(head);
        return split(head);
    }
private:
    void copy_next(RandomListNode* head) {
        while (head != NULL) {
            RandomListNode* new_node = new RandomListNode(head->label);
            new_node->next = head->next;
            head->next = new_node;
            head = new_node->next;
        }
    }

    void copy_random(RandomListNode* head) {
        while (head != NULL) {
            RandomListNode* new_node = head->next;
            if (head->random != NULL) {
                new_node->random = head->random->next;
            }
            head = head->next->next;
        }
    }

    RandomListNode *split(RandomListNode* head) {
        RandomListNode dummy(0);
        RandomListNode* node = &dummy;

        while (head != NULL) {
            node->next = head->next;
            head->next = head->next->next;
            node = node->next;
            head = head->next;
        }

        return dummy.next;
    }
};

// Hash Table
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        hash.clear();
        RandomListNode* new_head = copy_next(head);
        copy_random(head);

        return new_head;
    }
private:
    unordered_map<RandomListNode *, RandomListNode *> hash;

    RandomListNode *copy_next(RandomListNode* head) {
        RandomListNode dummy(0);
        RandomListNode* node = &dummy;

        while (head != NULL) {
            RandomListNode* new_node = new RandomListNode(head->label);
            hash[head] = new_node;
            node->next = new_node;
            node = node->next;
            head = head->next;
        }
        hash[NULL] = NULL;

        return dummy.next;
    }

    void copy_random(RandomListNode* head) {
        while (head != NULL) {
            RandomListNode* new_node = hash[head];
            new_node->random = hash[head->random];
            head = head->next;
        }
    }
};
