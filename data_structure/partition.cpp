# include <bits/stdc++.h>
using namespace std;

int RandomInRange(int start, int end)
{
	return rand() % (end - start + 1) + start;
}

void Swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int Partition(vector<int> &data, int start, int end)
{
	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);
	int small  = start - 1;
	for(index = start; index < end; ++index)
	{
		if(data[index] < data[end])
		{
			++small;
			if(small != index) Swap(&data[index], &data[small]);
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}

void QuickSort(vector<int> &data, int start, int end)
{
	int index = Partition(data, start, end);
	if(index < end) QuickSort(data, index + 1, end);
	if(index > start) QuickSort(data, start, index - 1);
}

int main()
{
	int arr[] = {2, 1, 4, 3, 5};
	vector<int> data(arr, arr + sizeof(arr) / sizeof(arr[0]));

	for(int i = 0; i < data.size(); ++i)
	{
		cout << data[i] << " ";
	}

	cout << endl;


	QuickSort(data, 0, data.size() - 1);
	for(int i = 0; i < data.size(); ++i)
	{
		cout << data[i] << " ";
	}

	cout << endl;
	return 0;
}