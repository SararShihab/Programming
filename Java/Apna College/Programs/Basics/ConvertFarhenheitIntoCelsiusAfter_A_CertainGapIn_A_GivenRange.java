import java.util.* ;

public class ConvertFarhenheitIntoCelsiusAfter_A_CertainGapIn_A_GivenRange {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int S = sc.nextInt();
        int E = sc.nextInt();
        int W = sc.nextInt();
        sc.close();
        for (int i = S; i <= E; i += W) 
        {
            System.out.print(i+" ");
            float F = ((i-32)*5)/9;
            if(F>=0){
                int D = (int)(Math.ceil(F));
                System.out.println(D);
            }
            else
            {
                int D = (int)(Math.floor(F));
                System.out.println(D);
            }
            
        }
    }
}
