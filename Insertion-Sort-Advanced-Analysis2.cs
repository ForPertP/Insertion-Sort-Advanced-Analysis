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

    static long g_count = 0;

    static void Merge(List<int> arr, int begin, int mid, int end)
    {
        int nL = mid - begin + 1;
        int nR = end - mid;

        List<int> L = new List<int>(nL);
        List<int> R = new List<int>(nR);

        for (int i = 0; i < nL; ++i)
            L.Add(arr[begin + i]);

        for (int j = 0; j < nR; ++j)
            R.Add(arr[mid + 1 + j]);

        int iL = 0, iR = 0, k = begin;

        while (iL < nL && iR < nR)
        {
            if (L[iL] <= R[iR])
            {
                arr[k] = L[iL];
                iL++;
            }
            else
            {
                arr[k] = R[iR];
                iR++;
                g_count += (nL - iL);
            }
            k++;
        }

        while (iL < nL)
        {
            arr[k] = L[iL];
            iL++;
            k++;
        }

        while (iR < nR)
        {
            arr[k] = R[iR];
            iR++;
            k++;
        }
    }

    static void MergeSort(List<int> arr, int begin, int end)
    {
        if (begin < end)
        {
            int mid = begin + (end - begin) / 2;
            MergeSort(arr, begin, mid);
            MergeSort(arr, mid + 1, end);
            Merge(arr, begin, mid, end);
        }
    }

    public static long insertionSort(List<int> arr)
    {
        g_count = 0;
        if (arr == null || arr.Count == 0) return 0;
        MergeSort(arr, 0, arr.Count - 1);
        return g_count;
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
