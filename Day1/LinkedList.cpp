#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    string data;
    Node *next;

    Node(string data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
    Node *head = nullptr;

public:
    LinkedList(string x)
    {
        head = new Node(x);
    }

    void insert(string x)
    {
        if (head == nullptr)
        {
            head = new Node(x);
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node(x);
        }
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "LinkedList is empty 😂😂😂" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " 🔗 ";
                temp = temp->next;
            }
        }
    }
    void search_and_update(string find, string replace)
    {
        Node *temp = head;
        Node *follower = head;
        while (temp != nullptr)
        {
            if (temp->data == find)
            {
                temp->data = replace;
            }
            temp = temp->next;
        }
    }
    void delete_and_update(string find)
    {
        Node *temp = head;
        Node *follower = nullptr;
        if (head->data == find)
        {
            temp = head;
            head = head->next;
            delete temp;
            temp = head;
        }
        while (temp != nullptr)
        {
            if (temp->data == find)
            {
                follower->next = temp->next;
                delete temp;
                temp = follower->next;
                continue;
                ;
            }
            follower = temp;
            temp = temp->next;
        }
    }
    void insert_node_at_middle(string find, string insert)
    {
        Node *node = new Node(insert); // New node to insert
        Node *temp = head;
        Node *follower = nullptr;

        // Traverse the list
        while (temp != nullptr)
        {
            if (temp->data == find)
            {
                // Inserting the node after the current node
                node->next = temp->next;
                temp->next = node;
                temp = node->next;
                continue;
            }
            follower = temp;
            temp = temp->next;
        }
    }
};
int main()
{
    cout << "Created List" << endl;
    LinkedList list("❤️❤️❤️❤️❤️");
    list.insert("Hafiz");
    list.insert("Sibghat");
    list.insert("Ullah");
    list.insert("Jamali");
    list.insert("❤️❤️❤️❤️❤️");

    // Traverse and display the list

    cout << "LinkedList elements: ";
    list.display();
    cout << endl;
    cout << "Updated List" << endl;
    list.search_and_update("❤️❤️❤️❤️❤️", "💓💓💓💓💓");
    cout << "LinkedList elements: ";
    list.display();
    cout << endl;
    cout << "Deleted List" << endl;
    list.delete_and_update("💓💓💓💓💓");
    cout << "LinkedList elements: ";
    list.display();
    cout << "Inserted List" << endl;
    list.insert_node_at_middle("Hafiz", "Hazrat");
    cout << "LinkedList elements: ";
    list.display();
    return 0;
}
