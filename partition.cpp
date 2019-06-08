# include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> numbers, int start, int end)
{
    int pivot = numbers[0];
    int left = 0, right = end;
    while(left < right)
    {
        while(numbers[right] > pivot && left < right)
        {
            right--;
        }
        
        if(right > left)
        {
            numbers[left] = numbers[right];
            left++;
        }
        
        while(numbers[left] <= pivot && left < right)
        {
            left++;
        }
        
        if(right < left)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    
    if(left == right)
    {
        numbers[left] = pivot;
    }
    return left;
}

int main()
{
    int n;
    vector<int> numbers;
    int number;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> number;
        numbers.push_back(number);
    }

    int index = Partition(numbers, 0, n - 1);
    cout << index << endl;

    return 0;
}