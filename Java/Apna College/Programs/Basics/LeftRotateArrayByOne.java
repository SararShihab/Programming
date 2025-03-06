import java.util.*;

public class LeftRotateArrayByOne {
    static int[] rotateArray(int[] arr, int n) {
        int first = arr[0];
        for (int i = 0; i < n; i++) {
            if (i < (n - 1)) {
                arr[i] = arr[i + 1];
            } else {
                arr[i] = first;
            }
        }
        return arr;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();
        int[] result = rotateArray(arr, n);
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
