/**Deque Implementation**/

class Deque { 
    static final int MAX_SIZE = 100; 
    int front, back, arr[];
      
    public Deque() { 
        arr = new int[MAX_SIZE]; 
        front = -1; 
        back = -1;
    } 

    void push_front(int key) {
		if ((front == 0 && back == MAX_SIZE - 1)|| front == back + 1) { 
			System.out.println("Overflow!");
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

	void push_back(int key) { 
		if ((front == 0 && back == MAX_SIZE - 1)|| front == back + 1) {
			System.out.println("Overflow!");
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

	void pop_front() {
		if (front == -1) { 
			System.out.println("Underflow!"); 
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

	void pop_back() { 
		if (back == -1) { 
			System.out.println("Underflow!"); 
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
 
	int get_front() {
		if (front == -1) { 
			System.out.println("Underflow!");
			return -1 ; 
		} 
		return arr[front]; 
	} 

	int get_back() {
		if(back == -1) { 
			System.out.println("Underflow!");
			return -1 ; 
		} 
		return arr[back]; 
	}

	boolean isEmpty() { 
		return (front == -1); 
	}

    public static void main(String args[]) { 
          
        Deque dq = new Deque();
		dq.push_front(5); 
		dq.push_back(10);
		dq.push_back(15);
		dq.pop_front();  
		dq.pop_back();
		
        System.out.println(dq.get_front() + " " + dq.get_back());
    } 
}
