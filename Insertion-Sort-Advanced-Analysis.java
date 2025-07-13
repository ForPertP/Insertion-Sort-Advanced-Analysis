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

    private static long mergeCount(List<Integer> a, List<Integer> buf, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        long inv = 0;

        inv += mergeCount(a, buf, l, m);
        inv += mergeCount(a, buf, m + 1, r);

        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r) {
            if (a.get(i) <= a.get(j)) {
                buf.set(k++, a.get(i++));
            } else {
                buf.set(k++, a.get(j++));
                inv += (m - i + 1);
            }
        }

        while (i <= m) buf.set(k++, a.get(i++));
        while (j <= r) buf.set(k++, a.get(j++));

        for (int idx = l; idx <= r; ++idx) {
            a.set(idx, buf.get(idx));
        }
        return inv;
    }

    public static long insertionSort(List<Integer> arr) {
        if (arr == null || arr.isEmpty()) return 0;

        List<Integer> buf = new ArrayList<>(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            buf.add(0);
        }

        long shifts = mergeCount(arr, buf, 0, arr.size() - 1);
        return shifts;
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
