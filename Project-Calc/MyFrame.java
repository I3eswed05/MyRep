import java.awt.*;
import java.awt.event.*;
import java.util.Stack;
import javax.swing.*;

public class MyFrame extends JFrame implements ActionListener {
    private final JTextField display; // Display area for input and results
    private final JButton[] buttons; // Array of calculator buttons
    private final JPanel panel; // Panel to hold buttons
    private final JPanel displayPanel; // Panel to hold the display
    private final StringBuilder expression = new StringBuilder(); // Stores the input expression
    private boolean isNewCalculation = false; // Flag to check if last result was calculated

    public MyFrame() {
        // Define button labels
        buttons = new JButton[17];
        String[] buttonTexts = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", ".", "=", "+", "C"};
        
        // Create button panel with a grid layout
        panel = new JPanel(new GridLayout(5, 4));
        panel.setBackground(new Color(50, 50, 50)); // Dark gray background
        Font buttonFont = new Font("Arial", Font.BOLD, 18);

        // Define realistic color scheme
        Color numberColor = new Color(200, 200, 200); // Light gray for numbers
        Color operatorColor = new Color(255, 165, 0); // Orange for operators
        Color textColor = Color.BLACK;
        Color backgroundColor = new Color(30, 30, 30); // Dark background

        // Initialize buttons and add them to the panel
        for (int i = 0; i < buttons.length; i++) {
            buttons[i] = new JButton(buttonTexts[i]);
            buttons[i].setFocusable(false);
            buttons[i].setFont(buttonFont);
            buttons[i].setForeground(textColor);
            buttons[i].setBackground(buttonTexts[i].matches("[0-9]") ? numberColor : operatorColor); // Numbers gray, operators orange
            buttons[i].setBorder(BorderFactory.createLineBorder(Color.BLACK)); // Add a border
            buttons[i].addActionListener(this);
            panel.add(buttons[i]);
        }

        // Create the display field
        display = new JTextField();
        display.setEditable(false);
        display.setFont(new Font("Arial", Font.PLAIN, 24));
        display.setText("0"); // Default display value
        display.setHorizontalAlignment(JTextField.RIGHT);
        display.setBackground(backgroundColor);
        display.setForeground(Color.WHITE);

        // Create display panel to hold the display field
        displayPanel = new JPanel(new BorderLayout());
        displayPanel.add(display, BorderLayout.CENTER);
        displayPanel.setPreferredSize(new Dimension(300, 100));
        displayPanel.setBackground(backgroundColor);

        // Frame settings
        this.setTitle("Calculator");
        this.setSize(350, 450);
        this.setResizable(false);
        this.setLayout(new BorderLayout());
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.add(displayPanel, BorderLayout.NORTH);
        this.add(panel, BorderLayout.CENTER);
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String buttonText = ((JButton) e.getSource()).getText(); // Get button text

        // Handle number input
        if (buttonText.matches("[0-9]") || buttonText.equals(".")) {
            if (isNewCalculation) {
                expression.setLength(0); // Clear previous result
                isNewCalculation = false;
            }
            expression.append(buttonText);
            display.setText(expression.toString());
        } 
        // Handle operators
        else if (buttonText.matches("[+\\-*/]") && expression.length() > 0) {
            if (!expression.toString().matches(".*[+\\-*/]$")) { // Prevent duplicate operators
                expression.append(buttonText); // No extra spaces
                display.setText(expression.toString());
                isNewCalculation = false;
            }
        }
        // Handle evaluation
        else if (buttonText.equals("=")) {
            try {
                if (expression.length() == 0 || expression.toString().matches(".*[+\\-*/]$")) {
                    display.setText("Error"); // Prevent evaluating incomplete expressions
                    return;
                }
                double result = evaluateExpression(expression.toString());
                display.setText(String.valueOf(result));
                expression.setLength(0);
                expression.append(result);
                isNewCalculation = true;
            } catch (Exception ex) {
                display.setText("Error");
                expression.setLength(0);
            }
        }
        // Handle clear button
        else if (buttonText.equals("C")) {
            expression.setLength(0); // Clear expression
            display.setText("0"); // Reset display
        }
    }

    // Method to evaluate the expression using a manual parser
    private double evaluateExpression(String expression) {
        Stack<Double> numbers = new Stack<>();
        Stack<Character> operators = new Stack<>();
        String num = "";

        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (Character.isDigit(c) || c == '.') {
                num += c; // Build number string
            } else {
                if (!num.isEmpty()) {
                    numbers.push(Double.parseDouble(num));
                    num = "";
                }
                while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(c)) {
                    numbers.push(applyOperation(operators.pop(), numbers.pop(), numbers.pop()));
                }
                operators.push(c);
            }
        }
        if (!num.isEmpty()) numbers.push(Double.parseDouble(num));
        while (!operators.isEmpty()) numbers.push(applyOperation(operators.pop(), numbers.pop(), numbers.pop()));
        return numbers.pop();
    }

    private int precedence(char op) {
        return (op == '+' || op == '-') ? 1 : 2;
    }

    private double applyOperation(char op, double b, double a) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return b == 0 ? 0 : a / b;
            default: return 0;
        }
    }
}