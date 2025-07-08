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
    inv += merge_count(a, buf, m+1, r);

    int i=l, j=m+1, k=l;
    while(i<=m && j<=r)
        if(a[i] <= a[j]) buf[k++] = a[i++];
        else { buf[k++] = a[j++]; inv += (m - i + 1); }

    while(i<=m) buf[k++] = a[i++];
    while(j<=r) buf[k++] = a[j++];

    for(int idx=l; idx<=r; ++idx) a[idx] = buf[idx];
    return inv;
}

long long insertionSort(vector<int> arr)
{
    if(arr.empty()) return 0;
    vector<int> buf(arr.size());
    long long shifts = merge_count(arr, buf, 0, arr.size()-1);
    return shifts;
}
