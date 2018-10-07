

/*
Merge Sort I Runtime: O( n log (n) ) average and worst case. Memory: Depends.
Merge sort divides the array in half, sorts each of those halves, and then merges them back together. Each
of those halves has the same sorting algorithm applied to it. Eventually, you are merging just two singleelement
arrays. It is the "merge" part that does all the heavy lifting.
*/


#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &arr, int low, int high)
{
	for (int i = 0; i < arr.size() && i < low; ++i)
	{
		cout << "  ";
	}

	for (int i = low; i < arr.size() && i <= high; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void merge(vector<int> &arr, int low, int mid1, int mid2, int high)
{
	vector<int> target;
	target.resize(arr.size());
	int current = low;
	int leftIndex = low;
	int rightIndex = mid2;


	cout << "Merge:   >>>>>    ";
	display(arr, low, mid1);
	cout << "           ";
	display(arr, mid2, high);
	cout << endl;

	while (leftIndex <= mid1 && rightIndex <= high)
	{
		if (arr[leftIndex] <= arr[rightIndex])
		{
			target[current] = arr[leftIndex];
			leftIndex++;
		}
		else if (arr[leftIndex] > arr[rightIndex])
		{
			target[current] = arr[rightIndex];
			rightIndex++;

		}
		current++;
	}
	if (leftIndex == mid2)
	{
		while (rightIndex <= high)
		{
			target[current] = arr[rightIndex];
			current++;
			rightIndex++;
		}
	}
	else
	{
		while (leftIndex <= mid1)
		{
			target[current] = arr[leftIndex];
			current++;
			leftIndex++;
		}
	}

	for (int i = low; i <= high; ++i)
	{
		arr[i] = target[i];
	}

	cout << "         ";
	display(arr, low, high);
	cout << endl;
}

void MergeSort(vector<int> & arr, int low, int high)
{
	if (low < high)
	{
		int mid1 = (low + high) / 2;
		int mid2 = mid1 + 1;

		cout << "Spilt:   ";
		display(arr, low, high);
		cout << "           ";
		display(arr, low, mid1);
		cout << "           ";
		display(arr, mid2, high);
		cout << endl;

		MergeSort(arr, low, mid1);
		MergeSort(arr, mid2, high);
		merge(arr, low, mid1, mid2, high);
	}

}

void swap(int & elem1, int &elem2)
{
	int temp = elem1;
	elem1 = elem2;
	elem2 = temp;
}



void QuickSort(vector<int> &arr, int left, int right) {

	int low = left, high = right;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (low <= high) {
		while (arr[low] < pivot)
			low++;

		while (arr[high] > pivot)
			high--;

		if (low <= high) {
			swap(arr[low], arr[high]);
			low++;
			high--;
		}
	}

/* recursion */
	if (left < high)
		QuickSort(arr, left, high);

	if (low < right)
		QuickSort(arr, low, right);

}

void main()
{

	const int size = 10;
	vector<int> arr = { 30,47,22,67,79,18,60,78,26,54 };
	//MergeSort(arr, 0, arr.size() - 1);
	QuickSort(arr, 0, arr.size() - 1);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}