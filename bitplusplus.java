import java.util.Scanner;
 
public class bitplusplus{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = 0;
        for (int i=0 ; i < n ; i++)
        {
            String now = sc.next();
            if (now.equals("++X") || now.equals("X++"))
                x++;
            else
                x--;
        }
        sc.close();
        System.out.println(x);
    }
}