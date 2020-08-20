/**Rain Water Trapping Problem**/

#include<iostream>
using namespace std;

int maxWater(int height[], int n) { 
	int temp[n], result = 0, maxUptoHere = 0, i;

	for (i = 0; i < n; i++) {
		temp[i] = maxUptoHere;
		maxUptoHere = (height[i] > maxUptoHere) ? height[i] : maxUptoHere;
	}

	maxUptoHere = 0;

	for (i = n-1; i >=0 ; i--) {
		temp[i] = min (maxUptoHere , temp[i]);
		maxUptoHere = (height[i] > maxUptoHere) ? height[i] : maxUptoHere;
		result = (temp[i] > height[i]) ? result + (temp[i] - height[i]) : result;
	}

	return result;
}

int main() {
	int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(height)/sizeof(height[0]);
	cout << maxWater(height, n) << endl;
	return 0;  
}
