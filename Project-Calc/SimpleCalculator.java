// Import necessary libraries for GUI components and event handling
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

// Define the class SimpleCalculator that extends JFrame and implements ActionListener
public class SimpleCalculator extends JFrame implements ActionListener {
    
    // Declare GUI components
    private JTextField display; // Text field to show numbers and result
    private JButton btn0, btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9;
    private JButton btnAdd, btnSub, btnMul, btnDiv, btnEq, btnDot, btnClear;

    // Variables to store input numbers and operator
    private double num1 = 0, num2 = 0, result = 0;
    private char operator; // To store the selected operation (+, -, *, /)

    // A flag to know when to start a new number (after an operation or equals)
    private boolean startNewNumber = true;

    // Constructor: sets up the calculator window
    public SimpleCalculator() {

        // Set title of the window
        this.setTitle("Simple Calculator");

        // Set size of the window (width: 300px, height: 400px)
        this.setSize(300, 400);

        // Close the program when the window is closed
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Use BorderLayout to organize components (North, Center, etc.)
        this.setLayout(new BorderLayout());

        // Set background color of the frame to black
        this.getContentPane().setBackground(Color.BLACK);

        // Create the display text field
        display = new JTextField();

        // Set font style and size for the display
        display.setFont(new Font("Arial", Font.BOLD, 24));

        // Make it non-editable by user typing
        display.setEditable(false);

        // Align text to the right like normal calculators
        display.setHorizontalAlignment(JTextField.RIGHT);

        // Set background color of the display
        display.setBackground(Color.WHITE);

        // Set text color to black
        display.setForeground(Color.BLACK);

        // Show "0" initially in the display
        display.setText("0");

        // Create a panel to hold all the buttons
        JPanel panel = new JPanel(new GridLayout(5, 4, 5, 5)); // 5 rows, 4 columns, 5px gap

        // Initialize number buttons
        btn0 = new JButton("0");
        btn1 = new JButton("1");
        btn2 = new JButton("2");
        btn3 = new JButton("3");
        btn4 = new JButton("4");
        btn5 = new JButton("5");
        btn6 = new JButton("6");
        btn7 = new JButton("7");
        btn8 = new JButton("8");
        btn9 = new JButton("9");

        // Initialize operator and function buttons
        btnAdd = new JButton("+");
        btnSub = new JButton("-");
        btnMul = new JButton("*");
        btnDiv = new JButton("/");
        btnEq = new JButton("=");
        btnDot = new JButton(".");
        btnClear = new JButton("C");

        // Add buttons to the panel in calculator layout
        panel.add(btn7); panel.add(btn8); panel.add(btn9); panel.add(btnDiv);
        panel.add(btn4); panel.add(btn5); panel.add(btn6); panel.add(btnMul);
        panel.add(btn1); panel.add(btn2); panel.add(btn3); panel.add(btnSub);
        panel.add(btn0); panel.add(btnDot); panel.add(btnEq); panel.add(btnAdd);
        panel.add(btnClear); // Add clear button (not visible in grid because extra row not added)

        // Set background color of the panel
        panel.setBackground(Color.DARK_GRAY);

        // Register action listeners so buttons can respond to clicks
        btn0.addActionListener(this);
        btn1.addActionListener(this);
        btn2.addActionListener(this);
        btn3.addActionListener(this);
        btn4.addActionListener(this);
        btn5.addActionListener(this);
        btn6.addActionListener(this);
        btn7.addActionListener(this);
        btn8.addActionListener(this);
        btn9.addActionListener(this);
        btnAdd.addActionListener(this);
        btnSub.addActionListener(this);
        btnMul.addActionListener(this);
        btnDiv.addActionListener(this);
        btnEq.addActionListener(this);
        btnDot.addActionListener(this);
        btnClear.addActionListener(this);

        // Add the display at the top of the window
        this.add(display, BorderLayout.NORTH);

        // Add the button panel in the center
        this.add(panel, BorderLayout.CENTER);

        // Make the window visible
        this.setVisible(true);
    }

    // This method runs whenever a button is clicked
    @Override
    public void actionPerformed(ActionEvent e) {
        // Get the text from the clicked button
        String command = e.getActionCommand();

        // If the button is a digit or decimal point
        if (command.charAt(0) >= '0' && command.charAt(0) <= '9' || command.equals(".")) {
            // If we're starting a new number, replace current text
            if (startNewNumber) {
                display.setText(command);
                startNewNumber = false; // Next character is part of same number
            } else {
                // Otherwise, add to the existing number
                display.setText(display.getText() + command);
            }
        }

        // If the button is an operator (+, -, *, /)
        else if (command.equals("+") || command.equals("-") || command.equals("*") || command.equals("/")) {
            // Store the first number
            num1 = Double.parseDouble(display.getText());
            // Save the operator
            operator = command.charAt(0);
            // Prepare to accept second number
            startNewNumber = true;
        }

        // If the equals (=) button is pressed
        else if (command.equals("=")) {
            // Get the second number
            num2 = Double.parseDouble(display.getText());

            // Perform calculation based on operator
            switch (operator) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': 
                    if (num2 != 0)
                        result = num1 / num2; // Avoid division by zero
                    else
                        result = 0; // Display zero if dividing by zero
                    break;
            }

            // Show the result in the display
            display.setText(String.valueOf(result));
            // Next input will start a new number
            startNewNumber = true;
        }

        // If the clear (C) button is pressed
        else if (command.equals("C")) {
            // Reset display to 0
            display.setText("0");
            // Reset all stored values
            num1 = num2 = result = 0;
            // Next input will start a new number
            startNewNumber = true;
        }
    }
}
