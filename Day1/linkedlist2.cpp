#include <iostream>
using namespace std;

// Node structure
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList{
    Node *head = nullptr;
    
    public:
    LinkedList(int x){
        head = new Node(x);
    }

    void insert(int x){
        if (head==nullptr) {
            head = new Node(x);
        }
        else{
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; 
            }
            temp->next = new Node(x);
        }
    }
    void display(){
        if (head==nullptr) 
        {
            cout<<"LinkedList is empty 😂😂😂"<<endl;
        
        }
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout<<temp->data<<" ";
                temp =temp->next;
            }
        }
    }
    void search_and_update(int find,int replace){
        Node *temp = head;
        Node *follower = head;
        while (temp != nullptr)
        {
            if (temp->data == find)
            {
                temp->data=replace;
                
            }
            temp= temp->next;
        }
    }
    void delete_and_update(int find){
        Node *temp = head;
        Node *follower = nullptr;
        if (head->data == find){
            temp= head;
            head= head->next;
            delete temp;
            temp=head;
        }
        while (temp != nullptr)
        {
            if (temp->data == find)
            {
                follower->next = temp->next;
                delete temp;
                temp=follower->next;
                continue;;
            }
            follower = temp;
            temp= temp->next;
        
        }
    }
    void insert_at_middle(int find,int insert){
        Node *temp = head;
        Node *follower = nullptr;
        if (head->data == find){
            temp= head;
            head= head->next;
            delete temp;
            temp=head;
        }
        while (temp != nullptr)
        {
            if (temp->data == find)
            {
                follower->next = temp->next;
                delete temp;
                temp=follower->next;
                continue;;
            }
            follower = temp;
            temp= temp->next;
        
        }
    }

};
int main() {
    LinkedList 
}
