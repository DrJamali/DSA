#include <iostream>
using namespace std;

class Queue
{
    int size, head, tail;
    string *queue;
    public:
    Queue(int size){
        this->size = size;
        queue = new string[size];
        head = tail = -1;
    }
    void enqueue(string x){
        if (tail>size-1)
        {
            cout<<"Queue is full ⚠️⚠️⚠️"<<endl;
            return;
        }
        if (head == -1) head = 0;
        queue[++tail] = x;        
    }
    string dequeue(){
        if (head == -1 || head > tail){
            // cout<<"Queue is empty 🪹🪹🪹"<<endl;
            return "empty";
        }
        return queue[head++];
    }
};
int main(){
    Queue q(6);
    q.enqueue("My");
    q.enqueue("Name");
    q.enqueue("is");
    q.enqueue("Sibghat");
    q.enqueue("Ullah");
    q.enqueue("Jamali");
    string x;
    while (x!="empty")
    {
        x=q.dequeue();
        if (x=="empty")
        {
            break;
        }
        
        cout<<x<<" 🛳️ ";

    }
    

    return 0;
}
//Imporovements by Chatgpt
// Your code is almost perfect, but there's a small issue with the condition inside the `enqueue` function and the `dequeue` loop. Let me explain:

// ### 1. **Enqueue Condition Fix:**
// In the `enqueue` function, you should check if the queue is full by comparing the `tail` value to `size - 1`. However, the current check is comparing `tail` to `size - 1` after incrementing, which can cause unexpected behavior. Here's the correction:

// ```cpp
// if (tail == size - 1) {
//     cout << "Queue is full ⚠️⚠️⚠️" << endl;
//     return;
// }
// ```

// This will correctly check if the queue is full before attempting to add another element.

// ### 2. **`dequeue` Loop Fix:**
// The condition in the `while` loop to exit is fine but slightly inefficient because you can avoid the second `if` check by simply placing the dequeue call within the loop condition directly.

// ### Corrected Code:
// ```cpp
// #include <iostream>
// using namespace std;

// class Queue
// {
//     int size, head, tail;
//     string *queue;

// public:
//     Queue(int size)
//     {
//         this->size = size;
//         queue = new string[size];
//         head = tail = -1;
//     }

//     void enqueue(string x)
//     {
//         if (tail == size - 1)
//         {
//             cout << "Queue is full ⚠️⚠️⚠️" << endl;
//             return;
//         }
//         if (head == -1)
//             head = 0;
//         queue[++tail] = x;
//     }

//     string dequeue()
//     {
//         if (head == -1 || head > tail)
//         {
//             return "empty";
//         }
//         return queue[head++];
//     }
// };

// int main()
// {
//     Queue q(6);
//     q.enqueue("My");
//     q.enqueue("Name");
//     q.enqueue("is");
//     q.enqueue("Sibghat");
//     q.enqueue("Ullah");
//     q.enqueue("Jamali");

//     string x;
//     while ((x = q.dequeue()) != "empty")
//     {
//         cout << x << " 🛳️ ";
//     }

//     return 0;
// }
// ```

// ### Key Changes:
// - **Fixed the `enqueue` condition** to correctly check if the queue is full.
// - **Simplified the loop condition** in `main` by directly checking if the dequeue result is `"empty"` in the `while` condition.

// Now the code should work as expected! Let me know if you have more questions or further refinements!