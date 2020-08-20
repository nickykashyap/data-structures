/**Stack Implementation**/

#include <iostream>
#define MAX_SIZE 1000
using namespace std; 

class Stack { 
    int a[MAX_SIZE], top;

public: 
    Stack() { top = -1; } 
    void push(int); 
    void pop(); 
    int peek(); 
    bool isEmpty(); 
}; 
  
void Stack::push(int x) { 
    if (top >= (MAX_SIZE - 1)) 
        cout << "Stack Overflow!"; 
    else
        a[++top] = x;
} 
  
void Stack::pop() { 
    if (top < 0)
        cout << "Stack Underflow!";
    else
        top--;
}

int Stack::peek() { 
    if (top < 0) { 
        cout << "Stack is Empty!"; 
        return 0; 
    } else 
        return a[top];
} 
  
bool Stack::isEmpty() { 
    return (top < 0); 
} 

int main() { 
    Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    s.pop();
    cout << s.peek() << endl;
    return 0; 
} 
