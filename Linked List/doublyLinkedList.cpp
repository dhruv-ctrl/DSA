// convert arr to Doubly Linked List

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1, Node* next1 , Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrToDLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {12,3,5,7};
    Node* head = convertArrToDLL(arr);
    print(head);
    return 0;
}

//function to delete head of a doubly linked list
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

// function to delete tail of a doubly linked list
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}



// function to delete kth element of a doubly linked list
Node* deleteKthElement(Node* head,int k){
    if(head==NULL) return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if(prev==NULL && front==NULL){
        return NULL;
    }
    else if(prev == NULL) return deleteHead(head);
    else if(front == NULL) return deleteTail(head);
    
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    
    return head;
}


// function to delete a given node of a doubly linked list
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
}



// function to insert before head of a doubly linked list
Node* insertBeforeHead(Node* head,int val){
    Node* newNode = new Node(val,head,nullptr);
    head->back = newNode;
    return newNode;
}


// function to insert after tail of a doubly linked list
Node* insertBeforeTail(Node* head, int val){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}



// function to insert before kth element of a doubly linked list
Node* insertBeforeKthElement(Node* head,int k,int val){
    if(k==1) return insertBeforeHead(head,val);
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(k==cnt) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    temp->back = newNode;
    prev->next = newNode;
    return head;
}



// function to insert before a given node of a doubly linked list
void insertBeforeNode(Node* node,int val){
    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next = newNode;
    node->back = newNode;
}




// function to reverse a doubly linked list
class Solution {
  public:
    Node *reverse(Node *head) {
        if(head==NULL || head->next == NULL) return head;
        Node* current = head;
        Node* prev = NULL;
        while(current){
            prev = current->back;
            current->back = current->next;
            current->next = prev;
            current = current->back;
        }
        return prev->back;
    }
};