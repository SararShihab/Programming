import java.util.Scanner;

public class PrintSomethingForCharacter {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        char ch = input.next().charAt(0);
        input.close();

        if (ch >= 'a' && ch <= 'z') {
            System.out.println(0);
        } else if (ch >= 'A' && ch <= 'Z') {
            System.out.println(1);
        } else {
            System.out.println(-1);
        }

    }

}
