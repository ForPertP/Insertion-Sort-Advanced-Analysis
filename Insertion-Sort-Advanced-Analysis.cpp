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

long long merge_count(vector<int>& a, vector<int>& buf, int l, int r)
{
    if (l >= r) return 0;

    int m = l + (r - l) / 2;
    long long inv = 0;

    inv += merge_count(a, buf, l, m);
    inv += merge_count(a, buf, m + 1, r);

    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r)
        if (a[i] <= a[j]) buf[k++] = a[i++];
        else { buf[k++] = a[j++]; inv += (m - i + 1); }

    while (i <= m) buf[k++] = a[i++];
    while (j <= r) buf[k++] = a[j++];

    for (int idx = l; idx <= r; ++idx) a[idx] = buf[idx];

    return inv;
}

long long insertionSort(vector<int> arr)
{
    if (arr.empty()) return 0;

    vector<int> buf(arr.size());
    long long shifts = merge_count(arr, buf, 0, arr.size() - 1);
    return shifts;
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

        long long result = insertionSort(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

