// C++ implementation of Radix Sort 
#include<iostream> 
#include <vector>
using namespace std;

// A utility function to get maximum value in arr[] 
int getMax(vector<int> &arr)
{
	int mx = arr[0];
	for (int i = 1; i < arr.size(); i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}


// A utility function to print an array 
void print(vector<int> arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl;
}

void RadixSort2(std::vector<int> &nums)
{
	int maxNum, div;
	vector<vector<int> > buckets;

	if (nums.empty())
		return;

	buckets.resize(10);
	maxNum = getMax(nums);

	int i = 1;
	while (maxNum != 0)
	{
		// Move numbers into appropriate buckets
		for (auto num : nums)
		{
			if (num<0)
				throw std::domain_error("For radix sort , array cannot contain negative value. ");

			int remainder = (num / i) % 10;
			buckets[remainder].push_back(num);
		}

		// Now, move numbers from bucket to original array
		nums.clear();
		for (auto bucket1 : buckets)
		{
			for (auto bucket2 : bucket1)
			{
				nums.push_back(bucket2);
			}

		}
		for (int j = 0; j<10; j++)
		{
			buckets[j].clear();
		}

		maxNum /= 10;
		i *= 10;
	}
}

// Driver program to test above functions 
int main()
{
	vector<int> arr= { 170, 45, 75, 90, 802, 24, 2, 66 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	RadixSort2(arr);
	print(arr, arr.size());
	return 0;
}