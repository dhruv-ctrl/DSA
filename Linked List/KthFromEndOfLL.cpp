 struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

class Solution {
public:
    int getKthFromLast(Node* head, int k) {
        Node* fast = head;
        Node* slow = head;
        for(int i = 0; i < k; i++){
            if(fast == nullptr) return -1; // safety
            fast = fast->next;
        }

        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }
};