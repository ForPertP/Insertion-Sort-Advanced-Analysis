#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'insertionSort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 
long int g_count = 0;
 
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
            
            g_count += nL - i;
        }
        
        k++;
    }

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
 

long int insertionSort(vector<int> arr)
{
    g_count = 0;
    
    int index = std::distance(arr.begin(), arr.end());
    merge_sort(arr, 0, index - 1);
    
    return g_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long int result = insertionSort(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
