/*
Bubble Sort I Runtime: 0(n^2) average and worst case. Memory: 0(1).
In bubble sort, we start at the beginning of the array and swap the first two elements if the first is greater
than the second. Then, we go to the next pair, and so on, continuously making sweeps of the array until it is
sorted. In doing so, the smaller items slowly"bubble" up to the beginning of the list.
*/

#include <iostream>
using namespace std;

void swap(int &elem1, int & elem2)
{
	int temp = elem1; 
	elem1 = elem2;  
	elem2 = temp;
}


int * BubbleSort(int arr[],int size)
{
	for(int i = 0 ; i < size -1 ; i ++)
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	return arr;
}

int main()
{
	const int size = 10;
	int arr[size] = { 9,4,3,6,7,5,4,1,2,8 };
	BubbleSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}