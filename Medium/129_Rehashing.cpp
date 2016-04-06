/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int new_capacity = hashTable.size() * 2;
        vector<ListNode*> new_hash_table(new_capacity, NULL);

        for (int i = 0; i < hashTable.size(); i++) {
            ListNode* node = hashTable[i];
            while (node != NULL) {
                int index = hashcode(node->val, new_capacity);

                new_hash_table[index] = add_node(new_hash_table[index], node->val);

                node = node->next;
            }
        }

        return new_hash_table;
    }
private:
    int hashcode(int key, int capacity) {
        if (key < 0) {
            return (key % capacity + capacity) % capacity;
        }
        return key % capacity;
    }

    ListNode* add_node(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* node = &dummy;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new ListNode(val);

        return dummy.next;
    }
};
