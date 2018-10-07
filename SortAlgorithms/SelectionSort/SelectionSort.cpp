#include <iostream>
using namespace std;

void swap(int & elem1, int &elem2)
{
	int temp = elem1; 
	elem1 = elem2;
	elem2 = temp;
}


void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size-1 ; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

int main()
{
	const int size = 10;
	int arr[size] = { 9,7,5,3,1,8,6,4,2,10 };
	SelectionSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}

	cout << endl;
	return 0;
}