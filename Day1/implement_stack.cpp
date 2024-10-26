#include<iostream>
using namespace std;
class Stack{
    int size;
    int top;
    char *arr;

    public:
    Stack(int size){
        this->size = size;
        this->top = -1;
        this->arr =  new char[size];
    }
    void push(char x){
        if (top==size-1)
        {
            this->arr[++top]=x;
        }
        else{
            cout<<"Stack Overflow 😫😫"<<endl;
        }
    }
    int pop(){
        if (top==-1){
            cout<<"Stack is already empty 😂😂😂😂😂😂"<<endl;
            return 0;
        }
        else{
            char x= this->arr[top--];
            return x;
        }
    }
    void peek(int pos){
        if(top-pos+1<0){

        }
    }

};
int main(int args,char **kwargs){

    Stack s(5);
    s.pop();

}
