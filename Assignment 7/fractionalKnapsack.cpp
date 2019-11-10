#include <bits/stdc++.h> 

using namespace std; 

struct Item 
{ 
	int value, weight; 

	Item(int value, int weight) : value(value), weight(weight) {} 
}; 

bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 
 
void fractionalKnapsack(int Weight, struct Item array[], int n) 
{ 
	sort(array, array + n, cmp); 

	int currentWeight = 0; 
	double finalvalue = 0.0;

	for (int i = 0; i < n; i++) 
	{ 
		if (currentWeight + array[i].weight <= Weight) 
		{ 
			currentWeight += array[i].weight; 
			finalvalue += array[i].value; 
            cout << "{" << array[i].value << ", " << array[i].weight << "} taken fully \n";
		} 

		else
		{ 
			int remain = Weight - currentWeight; 
			finalvalue += array[i].value * ((double) remain / array[i].weight); 
            cout << "{" << array[i].value << ", " << array[i].weight << "} taken partially " << remain << "/" << array[i].weight << " th part \n";
			break; 
		} 
	} 

	cout << "Maximum value = " << finalvalue;
}

int main() 
{ 
	int Weight = 100; 
	Item array[] = {{50, 10}, {90, 20}, {120, 30}, {100, 40}}; 

	int n = sizeof(array) / sizeof(array[0]); 
    cout << "Weight of the sack : " << Weight <<endl;
	fractionalKnapsack(Weight, array, n); 
	return 0; 
} 
