import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
// I1 Dsouza - 9601
// Exp2
public class Exp2 {

    private static final String[] KEYWORDS = {"auto", "double", "int", "struct", "break", "else", "long", "switch",
            "case", "enum", "register", "typedef", "char", "extern", "return", "union", "const", "float", "short",
            "unsigned", "continue", "for", "signed", "void", "default", "goto", "sizeof", "volatile", "do", "if",
            "static", "while"};

    private static final String[] OPERATORS = {"+", ">", "~", "%=", "-", "<", "&", "<<=", "*", ">=", "^", ">>=",
            "/", "<=", "|", "&=", "%", "&&", "=", "^=", "++", "||", "+=", "|=", "--", "!", "-=", "==", "<<", "*=",
            "!=", ">>", "/="};

    private static final String[] SPECIAL_SYMBOLS = {"[", "]", "{", "}", ",", ";", ":", "(", ")"};

    private static boolean keyword(String word) {
        for (String keyword : KEYWORDS) {
            if (keyword.equals(word)) {
                return true;
            }
        }
        return false;
    }

    private static boolean operator(String word) {
        for (String operator : OPERATORS) {
            if (operator.equals(word)) {
                return true;
            }
        }
        return false;
    }

    private static boolean constant(String word) {
        for (char ch : word.toCharArray()) {
            if (ch == '.') continue;
            if (!Character.isDigit(ch)) {
                return false;
            }
        }
        return true;
    }

    private static boolean special(String word) {
        for (String symbol : SPECIAL_SYMBOLS) {
            if (symbol.equals(word)) {
                return true;
            }
        }
        return false;
    }

    private static boolean literal(String word) {
        int length = word.length();
        return (length > 1 && ((word.charAt(0) == '"' && word.charAt(length - 1) == '"') ||
                (word.charAt(0) == '\'' && word.charAt(length - 1) == '\'')));
    }

    public static void main(String[] args) {
        String fileName = "input.txt";
        try (Scanner scanner = new Scanner(new File(fileName))) {
            while (scanner.hasNext()) {
                String word = scanner.next();
                if (keyword(word)) {
                    System.out.println(word + " is a keyword");
                } else if (operator(word)) {
                    System.out.println(word + " is an operator");
                } else if (constant(word)) {
                    System.out.println(word + " is a constant");
                } else if (special(word)) {
                    System.out.println(word + " is a special symbol");
                } else if (literal(word)) {
                    System.out.println(word + " is a literal");
                } else {
                    System.out.println(word + " is an identifier");
                }
            }
        } catch (FileNotFoundException e) {
            System.err.println("Can't open " + fileName + " for reading.");
        }
    }
}
