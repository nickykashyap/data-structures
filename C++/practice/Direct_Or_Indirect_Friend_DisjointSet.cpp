/**Direct Or Indirect Friend : Union-Find Algorithm**/

#include <iostream> 
using namespace std; 

//Disjoint Set Data Structure
class DisjointSet { 
	int *parent, *size, n; 
	
	void makeSingleSet() { 
		for (int i = 0; i < n; i++) { 
			parent[i] = i;
			size[i] = 1;
		} 
	}

public: 
	DisjointSet(int n) { 
		parent = new int[n];
		size = new int[n]; 
		this->n = n;
		makeSingleSet(); 
	} 

	int Find(int x) { 
		if (parent[x] != x) {
			parent[x] = Find(parent[x]);
		}
		return parent[x]; 
	}

	void Union (int x, int y) { 
		int xparent = Find(x); 
		int yparent = Find(y); 

		if (xparent == yparent)
			return;

		if (size[xparent] > size[yparent]) { 
			parent[yparent] = xparent;
			size[xparent] += size[yparent];
		} else { 
			parent[xparent] = yparent; 
			size[yparent] += size[xparent]; 
		}
	} 
}; 

int main() { 
	DisjointSet obj(8);
	
	//Adding new friendship relations
	obj.Union(0, 2); 
	obj.Union(4, 2);
	obj.Union(2, 5); 
	obj.Union(3, 1);
	obj.Union(0, 1);
	obj.Union(6, 7);
	
	//Finding whether x is a direct or indirect friend of y
	if (obj.Find(0) == obj.Find(3)) 
		cout << "0 is a friend of 3" << endl;
	else
		cout << "0 is not a friend of 3" << endl;
	
	return 0; 
} 
