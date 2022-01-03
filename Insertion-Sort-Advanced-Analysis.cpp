int insertionSort(vector<int> arr)
{
    int count = 0;
    
    int n = arr.size();

    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j;

        for (j = i-1; j >= 0 && arr[j] > key; --j)
        {
            arr[j+1] = arr[j];
            count++;
        }

        arr[j+1] = key;
    }
    
    return count;
}
