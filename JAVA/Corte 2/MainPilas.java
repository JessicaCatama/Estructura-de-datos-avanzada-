import java.util.Stack;

public class MainPilas {

    static boolean balanced(String s) {
        Stack<Character> st = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(') st.push(c);
            else if (c == ')') {
                if (st.isEmpty()) return false;
                st.pop();
            }
        }
        return st.isEmpty();
    }

    static void result(boolean i) {
        if (i) {
            System.out.println("Si cumple");
        } else {
            System.out.println("No cumple");
        }
    }
    
    public static void main(String[] args) {
        System.out.println(balanced("(a+b)*(c+d)"));
        System.out.println(balanced("((a+b)"));
        System.out.println(balanced("(a+b)-(c+d)-(e+f)"));
    }
}