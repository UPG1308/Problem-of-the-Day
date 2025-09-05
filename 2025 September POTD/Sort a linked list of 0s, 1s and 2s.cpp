class Solution {
public:
    Node* segregate(Node* head) {
        if (!head) return nullptr;
        vector<int> values;
        Node* current = head;
        while (current) {
            values.push_back(current->data);
            current = current->next;
        }
        sort(values.begin(), values.end());
        current = head;
        int i = 0;
        while (current) {
            current->data = values[i++];
            current = current->next;
        }
        return head;
    }
};
