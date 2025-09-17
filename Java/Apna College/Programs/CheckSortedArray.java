import java.util.Scanner;
public class CheckSortedArray {
    
        public static int isSorted(int n, int []a) {
            int s = a[0];
            boolean isSor = true;
            for(int i = 0; i < n; i++){
                if(s<a[i]){
                    isSor = true;
                }
                else{
                    isSor = false;
                }
            }
            if (isSor) {
                return 1;
            }
            else{
                return 0;
            }

        }
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            int[] a = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = sc.nextInt();
            }
            sc.close();
            System.out.println(isSorted(n, a));
        }
    
}
