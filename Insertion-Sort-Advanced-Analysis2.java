import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'insertionSort' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    private static long gCount = 0;

    public static void merge(List<Integer> arr, int begin, int mid, int end) {
        int nL = mid - begin + 1;
        int nR = end - mid;

        List<Integer> L = new ArrayList<>(nL);
        List<Integer> R = new ArrayList<>(nR);

        for (int i = 0; i < nL; ++i)
            L.add(arr.get(begin + i));

        for (int j = 0; j < nR; ++j)
            R.add(arr.get(mid + 1 + j));

        int iL = 0, iR = 0, k = begin;

        while (iL < nL && iR < nR) {
            if (L.get(iL) <= R.get(iR)) {
                arr.set(k++, L.get(iL++));
            } else {
                arr.set(k++, R.get(iR++));
                gCount += (nL - iL);
            }
        }

        while (iL < nL) {
            arr.set(k++, L.get(iL++));
        }

        while (iR < nR) {
            arr.set(k++, R.get(iR++));
        }
    }

    public static void mergeSort(List<Integer> arr, int begin, int end) {
        if (begin < end) {
            int mid = begin + (end - begin) / 2;
            mergeSort(arr, begin, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, begin, mid, end);
        }
    }

    public static long insertionSort(List<Integer> arr) {
        gCount = 0;
        if (arr == null || arr.isEmpty()) return 0;
        mergeSort(arr, 0, arr.size() - 1);
        return gCount;
    }
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, t).forEach(tItr -> {
            try {
                int n = Integer.parseInt(bufferedReader.readLine().trim());

                List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                    .map(Integer::parseInt)
                    .collect(toList());

                long result = Result.insertionSort(arr);

                bufferedWriter.write(String.valueOf(result));
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
