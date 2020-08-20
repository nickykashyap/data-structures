/**Deque Implementation**/

#include <iostream>
#define MAX_SIZE 100
using namespace std; 

class Deque {
    int  front, back, arr[MAX_SIZE];
	
public: 
    Deque() { 
        front = -1;
        back = -1;
    } 

    void push_front(int); 
    void push_back(int); 
    void pop_front(); 
    void pop_back();
    int get_front(); 
    int get_back();
	bool isEmpty();
}; 

void Deque::push_front(int key) {
    if ((front == 0 && back == MAX_SIZE - 1)|| front == back + 1) { 
        cout << "Overflow!" << endl;
        return;
    } 

    if (front == -1) {
        front = 0;
        back = 0;
    } else if (front == 0)
        front = MAX_SIZE - 1;
    else
        front = front - 1;

    arr[front] = key; 
}

void Deque::push_back(int key) { 
    if ((front == 0 && back == MAX_SIZE - 1)|| front == back + 1) {
        cout << "Overflow!" << endl; 
        return; 
    }

    if (back == -1) { 
        front = 0; 
        back = 0; 
    } else if (back == MAX_SIZE - 1) 
        back = 0;
    else
        back = back + 1; 

    arr[back] = key ; 
} 

void Deque::pop_front() {
    if (front == -1) { 
        cout << "Underflow!" << endl; 
        return ; 
    } 

    if (front == back) { 
        front = -1; 
        back = -1; 
    } else if (front == MAX_SIZE - 1) 
        front = 0;
		
    else
        front = front + 1; 
} 

void Deque::pop_back() { 
    if (back == -1) { 
        cout << "Underflow!" << endl; 
        return ; 
    } 

    if (front == back) { 
        front = -1; 
        back = -1; 
    } else if (back == 0) 
        back = MAX_SIZE - 1; 
    else
        back = back - 1; 
} 
 
int Deque::get_front() {
    if (front == -1) { 
        cout << "Underflow!" << endl; 
        return -1 ; 
    } 
    return arr[front]; 
} 

int Deque::get_back() {
    if(back == -1) { 
        cout << " Underflow!" << endl; 
        return -1 ; 
    } 
    return arr[back]; 
}

bool Deque::isEmpty() { 
    return (front == -1); 
}

int main() { 
    Deque dq;
    dq.push_front(5); 
    dq.push_back(10);
	dq.push_back(15);
    dq.pop_front();  
    dq.pop_back();
	
	cout << dq.get_front() << " " << dq.get_back() << endl;
    return 0; 
} 
