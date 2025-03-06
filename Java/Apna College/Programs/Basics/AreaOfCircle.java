import java.util.Scanner;

public class AreaOfCircle {
    public static void main(String[] args) {
        float pi = 3.1416F;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the radius: ");
        float r = sc.nextFloat();
        System.out.println("The area of the circle is " + pi * r * r);
        sc.close();
    }
}
