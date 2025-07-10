using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'insertionSort' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    private static long MergeCount(List<int> a, List<int> buf, int l, int r)
    {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        long inv = 0;

        inv += MergeCount(a, buf, l, m);
        inv += MergeCount(a, buf, m + 1, r);

        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r)
        {
            if (a[i] <= a[j])
            {
                buf[k++] = a[i++];
            }
            else
            {
                buf[k++] = a[j++];
                inv += (m - i + 1);
            }
        }

        while (i <= m) buf[k++] = a[i++];
        while (j <= r) buf[k++] = a[j++];

        for (int idx = l; idx <= r; ++idx)
        {
            a[idx] = buf[idx];
        }
        return inv;
    }


    public static long insertionSort(List<int> arr)
    {
        if (arr == null || arr.Count == 0) return 0;

        List<int> buf = new List<int>(new int[arr.Count]);

        long shifts = MergeCount(arr, buf, 0, arr.Count - 1);
        return shifts;
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int t = Convert.ToInt32(Console.ReadLine().Trim());

        for (int tItr = 0; tItr < t; tItr++)
        {
            int n = Convert.ToInt32(Console.ReadLine().Trim());

            List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

            long result = Result.insertionSort(arr);

            textWriter.WriteLine(result);
        }

        textWriter.Flush();
        textWriter.Close();
    }
}
