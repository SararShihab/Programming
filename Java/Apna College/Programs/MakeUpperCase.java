import java.util.* ;
 
public class MakeUpperCase{
	public static String convertString(String str) {
            StringBuilder result = new StringBuilder(str.length());

            int capitalizeNext = 1;
            for (int j = 0; j < str.length(); j++) {
                char ch = str.charAt(j);
                if (capitalizeNext==1 && Character.isLetter(ch)) {
                    result.append(Character.toUpperCase(ch));
                    capitalizeNext = 0;
                } else {
                    result.append(ch);
                }
                if (ch == ' ') {
                    capitalizeNext = 1;
                }
            }
            
            return result.toString();
        }
    
   public static void main(String[] args)     
   {
       Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < T; i++) {
            String str = sc.nextLine();
            
            System.out.println(convertString(str));
        }
        sc.close();
    }
   

}