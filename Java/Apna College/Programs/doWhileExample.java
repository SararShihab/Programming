import java.util.Scanner;

public class doWhileExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        do {
            System.out.print("Enter a number: ");
            n = sc.nextInt();
            
            System.out.println(n);
        } while (n >= 0);
        System.out.println("**THE END**");
        sc.close();
    }
    
}
