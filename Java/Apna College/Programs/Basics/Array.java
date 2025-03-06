import java.util.Arrays;

public class Array {
    public static void main(String[] args) {
        int[] marks = new int[4];
        marks[0] = 97;
        marks[1] = 95;
        marks[2] = 80;
        marks[3] = 85;

        int[] age={21, 20, 18};

        int[][] data = {{1, 2, 3},{4, 5, 6}};

        System.out.println("Length: " + marks.length);

        System.out.println("Index 1 before sort: " + marks[1]);

        Arrays.sort(marks);
        System.out.println("Index 1 after sort: " + marks[1]);

        System.out.println(age.length);
        System.out.println(age[0]);

        System.out.println(data[1][2]);
    }
}
