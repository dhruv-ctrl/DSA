
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* segregate(Node* head) {
        Node* temp=head;
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        while(temp){
            if(temp->data==0) cnt0++;
            else if(temp->data == 1) cnt1++;
            else cnt2++;
            temp = temp->next;
        }
        Node* temp1 = head;
        while(temp1){
            if(cnt0){
               temp1->data = 0; 
               cnt0--; 
            }
            else if(cnt1){
                temp1->data = 1;
                cnt1--;
            } 
            else{
                temp1->data = 2;
                cnt2--;
            } 
            temp1 = temp1->next;
        }
        return head;
    }
};