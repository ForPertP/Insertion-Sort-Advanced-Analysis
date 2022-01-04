template <typename T>
void merge(T& arr, int begin, int mid, int end)
{
    int nL = mid - begin + 1;
    int nR = end - mid;

    vector<int> L(nL);
    vector<int> R(nR);

    for (int i = 0; i < nL; ++i)
        L[i] = arr[begin + i];

    for (int j = 0; j < nR; ++j)
        R[j] = arr[mid + 1 + j];


    int i = 0;
    int j = 0;
    int k = begin;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < nL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < nR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void merge_sort(T& arr, int begin, int end)
{
    if (begin < end)
    {
        int mid = begin + (end - begin) / 2;
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

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
