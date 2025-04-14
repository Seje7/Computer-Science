package project2;

import java.util.*;

public class PostFixEvaluator {
    private Stack<Integer> stack;
    private String[] tokens;

    public PostFixEvaluator(String postfix) {
        stack = new Stack<Integer>();
        tokens = postfix.split(" ");
    }

    public int evaluate() {
        for (String token : tokens) {
            if (isOperand(token)) {
                stack.push(Integer.parseInt(token));
            } else { // Operator
                if (stack.isEmpty()) {
                    throw new IllegalArgumentException("Invalid postfix expression: SPACE OUT ALL INPUTS UNLESS I WON'T CALCULATE");
                }
                int operand2 = stack.pop();
                if (stack.isEmpty()) {
                    throw new IllegalArgumentException("Invalid postfix expression: empty stack");
                }
                int operand1 = stack.pop();
                int result = evaluateOperator(token, operand1, operand2);
                stack.push(result);
            }
        }

        if (stack.isEmpty()) {
            throw new IllegalArgumentException("Invalid postfix expression: empty stack");
        }

        return stack.pop();
    }

    private boolean isOperand(String token) {
        return token.matches("\\d+");
    }

    private int evaluateOperator(String operator, int operand1, int operand2) {
        switch (operator) {
            case "+":
                return operand1 + operand2;
            case "-":
                return operand1 - operand2;
            case "*":
                return operand1 * operand2;
            case "/":
                return operand1 / operand2;
            default:
                throw new IllegalArgumentException("Invalid operator: " + operator);
}
    }
    public Stack<Integer> getStack() {
        return stack;
    }
}