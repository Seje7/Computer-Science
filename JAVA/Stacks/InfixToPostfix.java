package project2;

import java.util.*;

public class InfixToPostfix {
    private Stack<String> stack;
    private String[] tokens;
    private String postfix;

    public InfixToPostfix(String infix) {
        stack = new Stack<String>();
        tokens = infix.split(" ");
        postfix = "";
    }

    public String convert() {
        for (String token : tokens) {
            if (isOperand(token)) {
                postfix += token + " ";
            } else if (token.equals("(")) {
                stack.push(token);
            } else if (token.equals(")")) {
                while (!stack.peek().equals("(")) {
                    postfix += stack.pop() + " ";
                }
                stack.pop(); // Discard the opening parenthesis
            } else { // Operator
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(token)) {
                    postfix += stack.pop() + " ";
                }
                stack.push(token);
            }
        }

        while (!stack.isEmpty()) {
            postfix += stack.pop() + " ";
        }

        return postfix.trim();
    }

    private boolean isOperand(String token) {
        return token.matches("\\d+");
    }

    private int precedence(String operator) {
        switch (operator) {
            case "+":
            case "-":
                return 1;
            case "*":
            case "/":
                return 2;
            default:
                return 0;
        }
    }
}

