import java.util.Scanner;

public class StringManipulation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name1 = new String("Shihab");
        System.out.println("Your name is " + name1);
        System.out.println("The length of you name is " + name1.length());
        String name2 = new String("Sarar");
        String name3 = "Md. " + name1 + " " + name2;
        System.out.println("Your full name is " + name3);
        System.out.print("Enter the index: ");
        int a = sc.nextInt();
        System.out.println("The character on index " + a + " is " + name3.charAt(a));
        String name4 = new String(name3.replace('a', 'b'));
        System.out.println("Replaced name: " + name4);
        System.out.println(name3.substring(4, 10)); // we have to write n+1 th index to get till n th index
        sc.close();
    }
}