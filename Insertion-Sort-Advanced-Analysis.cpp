template <typename T>
void insertion_sort(T& arr)
{
    int n = arr.size();

    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j;

        for (j = i-1; j >= 0 && arr[j] > key; --j)
        {
            arr[j+1] = arr[j];
        }

        arr[j+1] = key;
    }
}


int insertionSort(vector<int> arr)
{
    int result = 0;
    
    int n = arr.size();

    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j;

        for (j = i-1; j >= 0 && arr[j] > key; --j)
        {
            arr[j+1] = arr[j];
        }

        arr[j+1] = key;
    }    
    
    return result;
}

