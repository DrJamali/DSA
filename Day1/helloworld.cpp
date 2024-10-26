#include<iostream>
using namespace std;
#define MAX = 100
class stack{
    int top;
    int *arr;
    int capacity;
    public:
    stack(int n){
        capacity = n;
        arr = new int[capacity];
        top=-1;
    }
    void push(int x){
        if (top >= capacity-1)
        {
            cout<<"stack overflow"<<endl;
            return;
        }
        arr[++top] = x;
        cout<<"Value entered: "<<arr[top]<<endl;

    }
    int peek(){
        if (top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else{
            cout<<"Value of top is"<<top<<endl;
            return arr[top];
        }
        
    }
    void pop(){
        if(top == -1){
            cout<<"stack underflow"<<endl;
            return;
        }
        top--;
    }
    void empty(){
        top == -1? cout<<"Stack is empty"<<endl : cout<<"Stack is not empty"<<endl;
    }

};
int main(){
    stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);

    s.empty();
}