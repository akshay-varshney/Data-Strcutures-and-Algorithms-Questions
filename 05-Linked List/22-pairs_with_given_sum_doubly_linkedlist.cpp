// Linked List: Find pair with given sum in double linked list
//https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/

#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
};
void Print_Linked_list(Node *n){
    Node *PREV=n;
    while(n!=nullptr){
        cout<<n->data<<"-><-";
        PREV=n;
        n=n->next;
    }
    cout<<endl;
}

void Insert_start(Node *&head, int data){
    Node *newnode=new Node();
    newnode->data=data;
    newnode->next=head;
    newnode->prev=NULL;
    if(head!=NULL){
        head->prev=newnode;
    }
}


// Append nodes at the end of the linked list.
void append(Node *&head, int data){
    Node *newnode=new Node();
    newnode->next=NULL;
    newnode->data=data;
    Node *last=head;
    if(head==NULL){
        head=newnode;
        newnode->prev=NULL;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newnode;
    newnode->prev=last;
    return;
}

vector<pair<int, int>> find_sum(Node * &head, int x){
    Node *last=head;
    vector<pair<int, int>> ans;
    while(last->next!=NULL){
        last=last->next;
    }
    Node *temp=head;
    while(temp!=last){
        if((last->data+ temp->data)==x){
            ans.push_back(std::make_pair(temp->data, last->data));
            temp=temp->next;
        }
        else if((last->data+ temp->data)>x){
            last=last->prev;
        }
        else{
            temp=temp->next;
        }
    }
    if(ans.size()==0){
        return {};
    }
    return ans;
}


int main() {
    Node *head=new Node();
    head=NULL;
    append(head, 1);
    append(head, 2);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 7);
    append(head, 8);
    append(head, 9);
    Print_Linked_list(head);
    auto v2=find_sum(head, 7);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<it->first<<" ,"<<it->second<<endl;
    }
    
}
