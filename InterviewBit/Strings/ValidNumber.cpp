public class Solution {
    //Solution Approach
    public static int isNumberSolution(final String a) {
        if(a == null || a.length() == 0 || a.charAt(a.length()-1) == '.' )
            return 0;
        int i = 0;
        int dot = 0;
        int e = 0;
        int num = 0;
        char temp = a.charAt(i);
        //System.out.println(a.length());
        if(temp == '+' || temp == '-' || temp == ' ')
            i++;
        while(i < a.length()){
            temp = a.charAt(i);
            //System.out.print(temp + " ");
            if((temp >= '0' && temp <= '9') ){
                num++;                
            }
            else if(temp == '+' || temp == '-'|| temp == ' '){
                
            }
            else if(temp == '.' && i < a.length()-1 && (a.charAt(i+1) >= '0' && a.charAt(i+1) <= '9')){
                if(e > 0)
                    return 0;
                else
                    dot++;
            }
            else if(temp == 'e'){
                e++;
            }            
            else
                return 0;
            i++;
        }
        //System.out.println();
        //System.out.println(num + " " +  e + " " + dot);
        if(num < 1) return 0;
        if(dot > 1 || e > 1) return 0;
        
        return 1;
        
    }
    /*Using Regex = 
                (0 or more Spaces) 
    followed by (- or + sign )  
    followed by (0 to 9 numbers) 0 or more 
    followed by (.)  
    followed by (0 - 9 numbers) one or more  
    followed by (e)  
    followed by (- or + sign)  
    followed by (0 to 9 numbers) one or more
    followed by (0 or more spaces)
    */
    public int isNumber(final String A) {
        return (A.matches("\\s*[\\-\\+]?([0-9]*\\.?)?[0-9]+(e[\\-\\+]?[0-9]+)?\\s*")) ? 1 : 0;
    }
}
