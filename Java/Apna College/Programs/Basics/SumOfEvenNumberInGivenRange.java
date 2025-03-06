import java.util.Scanner;
public class SumOfEvenNumberInGivenRange {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the starting point: ");
        int start = sc.nextInt();
        System.out.print("Enter the end point: ");
        int end = sc.nextInt();
        sc.close();
        int sum=0;
        for(int i = start; i<= end; i++){
            if(i%2==0){
                sum+=i;
            }
        }
        System.out.println("The sum of the even numbers from "+start+" to "+ "End is "+sum);
    }
}
