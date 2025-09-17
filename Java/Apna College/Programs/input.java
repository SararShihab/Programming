import java.util.Scanner;

public class input {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = input.nextLine();
        System.out.println("Name: " + name);
        System.out.print("Enter an integer number: ");
        int a = input.nextInt();
        System.out.println("You entered: " + a);
        input.close();
    }
}
