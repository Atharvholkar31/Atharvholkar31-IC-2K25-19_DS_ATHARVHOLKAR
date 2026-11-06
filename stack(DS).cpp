#include <iostream>
using namespace std;
class myStack{
    private:
    int *arr;
    int capacity, top;
    public:
    // its constructor
    myStack(int cap){
        capacity = cap;
        arr= new int[capacity];
        top= -1;
    }
    // empty and full functions
    bool isempty(){
        return top == -1;
        cout<<"stack is empty";
    }
    bool isfull(){
        return top == capacity - 1;
         cout<<"stack is full\n";
    }
    // push then pop
    void push(int x){
       if (isfull()){ 
           cout<<"overflow stack\n";
           return;
        }
       arr[++top]= x;
       cout<<"we pushed a number\n\n";
    }

    int pop(){
        if (isempty()){
            cout<<"underflow stack\n";
            return -1;
        }
        return arr[top--];
        cout<<"we pulled a number\n";
    }

    // peek
    int peek(){
        if (isempty()){
            cout<<"underflow stack\n";
            return -1;
        }  
        return arr[top];
    }
    // display
void display(){
    if (isempty()){
            cout<<"underflow stack\n";
            return;
        }
else
        {cout<<"\nthe stack is: ";
    for(int i=0; i<=top; i++){
        cout<<arr[i]<<endl;}}}
};

    int main(){
        myStack s(4);
        s.push(23);
        s.push(25);
        s.push(24);
        s.push(26);
        s.push(66);;
        cout<<s.pop()<<endl;
        cout<<s.peek()<<endl;
        cout<<(s.isempty()? "yes": "no")<<endl;
        cout<<(s.isfull()? "yes": "no");
        s.display();
        return 0;

delete int[capacity];
}
