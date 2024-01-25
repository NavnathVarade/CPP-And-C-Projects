#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

// Calculator class
class Calculator {
public:
    // Constructor
    Calculator() : result(0.0), mem(0.0) {}

    // Operations
    void add();
    void subtract();
    void multiply();
    void divide();
    void square();
    void sqrt();
    void setMem();
    void printMem() const;

    // Utility functions
    double parseInput(const std::string&) const;
    virtual void welcome() const; // Virtual function for displaying welcome message
    virtual void parseOperation(const std::string&); // Virtual function for parsing user input

protected:
    double result; // Result of the operation
    double mem; // Memory storage
};

// Function to add two numbers
void Calculator::add() {
    std::string a, b;
    std::cout << "Enter the first number: ";
    std::cin >> a;
    std::cout << "Enter the second number: ";
    std::cin >> b;
    result = parseInput(a) + parseInput(b);
    std::cout << "The result is " << result;
}

// Function to subtract two numbers
void Calculator::subtract() {
    std::string a, b;
    std::cout << "Enter the first number: ";
    std::cin >> a;
    std::cout << "Enter the second number: ";
    std::cin >> b;
    result = parseInput(a) - parseInput(b);
    std::cout << "The result is " << result;
}

// Function to multiply two numbers
void Calculator::multiply() {
    std::string a, b;
    std::cout << "Enter the first number: ";
    std::cin >> a;
    std::cout << "Enter the second number: ";
    std::cin >> b;
    result = parseInput(a) * parseInput(b);
    std::cout << "The result is " << result;
}

// Function to divide two numbers
void Calculator::divide() {
    std::string a, b;
    std::cout << "Enter the first number: ";
    std::cin >> a;
    std::cout << "Enter the second number: ";
    std::cin >> b;
    result = parseInput(a) / parseInput(b);
    std::cout << "The result is " << result;
}

// Function to calculate square of a number
void Calculator::square() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    double parsedA = parseInput(a);
    result = parsedA * parsedA;
    std::cout << "The result is " << result;
}

// Function to calculate square root of a number
void Calculator::sqrt() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::sqrt(parseInput(a));
    std::cout << "The result is " << result;
}

// Function to set memory
void Calculator::setMem() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    mem = parseInput(a);
    std::cout << "The mem is " << mem;
}

// Function to print memory
void Calculator::printMem() const {
    std::cout << "The mem is " << mem;
}

// Function to parse input and handle 'result' and 'mem' keywords
double Calculator::parseInput(const std::string& input) const {
    if (input == "result") {
        return result;
    } else if (input == "mem") {
        return mem;
    } else {
        return std::stod(input);
    }
}

// Function to display welcome message
void Calculator::welcome() const {
    std::cout << "\n\nEnter an operation (+, -, /, *, sqrt, square, change, setmem, printmem) or exit\n";
}

// Function to parse user operation
void Calculator::parseOperation(const std::string& input) {
    if (input == "+" || input == "add" || input == "addition" || input == "sum") {
        add();
    } else if (input == "-" || input == "sub" || input == "subtraction" || input == "minus") {
        subtract();
    } else if (input == "/" || input == "divide" || input == "div") {
        divide();
    } else if (input == "*" || input == "mul" || input == "multiply" || input == "times") {
        multiply();
    } else if (input == "sqrt") {
        sqrt();
    } else if (input == "square") {
        square();
    } else if (input == "setmem") {
        setMem();
    } else if (input == "printmem") {
        printMem();
    }
}

// Scientific class derived from Calculator
class Scientific : public Calculator {
public:
    Scientific() : Calculator() {}

    // Overridden functions
    virtual void welcome() const override;
    virtual void parseOperation(const std::string& input) override;

    // Additional scientific functions
    void sin();
    void cos();
    void tan();
    void ln();
    void log();
    void abs();
    void pow();
};

// Function to display welcome message for scientific calculator
void Scientific::welcome() const {
    std::cout << "\n\nEnter one of:\n"
              << "+, -, /, *, sqrt, square, change, setmem, printmem, sin, cos, log, tan, ln, abs, pow\n"
              << "or exit\n";
}

// Function to parse user operation for scientific calculator
void Scientific::parseOperation(const std::string& input) {
    Calculator::parseOperation(input); // Call base class function

    if (input == "sin") {
        sin();
    } else if (input == "cos") {
        cos();
    } else if (input == "tan") {
        tan();
    } else if (input == "ln") {
        ln();
    } else if (input == "log") {
        log();
    } else if (input == "abs") {
        abs();
    } else if (input == "pow") {
        pow();
    }
}

// Function to calculate sine
void Scientific::sin() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::sin(parseInput(a));
    std::cout << "The result is " << result;
}

// Function to calculate cosine
void Scientific::cos() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::cos(parseInput(a));
    std::cout << "The result is " << result;
}

// Function to calculate tangent
void Scientific::tan() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::tan(parseInput(a));
    std::cout << "The result is " << result;
}

// Function to calculate natural logarithm
void Scientific::ln() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::log(parseInput(a));
    std::cout << "The result is " << result;
}

// Function to calculate logarithm with a given base
void Scientific::log() {
    std::string a, b;
    std::cout << "Enter the base: ";
    std::cin >> a;
    std::cout << "Enter a number: ";
    std::cin >> b;
    result = std::log(parseInput(b))/std::log(parseInput(a));
    std::cout << "The result is " << result;
}

// Function to calculate absolute value
void Scientific::abs() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    result = std::abs(parseInput(a));
    std::cout << "The result is " << result;
}

// Function to calculate power
void Scientific::pow() {
    std::string a, b;
    std::cout << "Enter the base: ";
    std::cin >> a;
    std::cout << "Enter the exponent: ";
    std::cin >> b;
    result = std::pow(parseInput(a), parseInput(b));
    std::cout << "The result is " << result;
}

int main() {
    Calculator calc;
    Scientific sci;
    Calculator* calcPtr = &calc;
    bool sciActive = false;

    // Display introductory message
    std::cout << "\n======= Welcome to my Calculator App =======\n\n";
    std::cout << "This calculator has two modes: normal and scientific. You can change modes by typing 'change'." << std::endl;
    std::cout << "Special keywords: 'result' stores the last result, 'mem' stores a value." << std::endl;
            
    // Display initial prompt
    calcPtr->welcome();
    std::cout << std::setprecision(15);

    std::string input = "";
    while (std::cin >> input && input != "exit") {
        if (input == "change") {
            if (sciActive) {
                calcPtr = &calc;
                sciActive = false;
                std::cout << "\nSimple Calculator Activated";
            } else {
                calcPtr = &sci;
                sciActive = true;
                std::cout << "\nScientific Calculator Activated";
            }
        }
        calcPtr->parseOperation(input); // Parse user input
        calcPtr->welcome(); // Display prompt again
    }

    return 0;
}
