# Documentation for Question 2  
## Infix to Postfix Conversion and Evaluation Using Stack

---

## 1. Problem Overview

This program converts a **mathematical expression written in infix notation** into **postfix notation** (Reverse Polish Notation) and then evaluates the result.

Infix notation:  
3 + 4 - 1
Postfix notation:  

The program uses **stack data structures** for both:
- Converting infix to postfix
- Evaluating the postfix expression

---

## 2. Data Structures Used

### 1. Stack of Characters (`stack<char>`)
- Used during the **conversion** from infix to postfix.
- Stores operators and parentheses temporarily.
- Ensures correct handling of operator precedence and associativity.

### 2. Stack of Doubles (`stack<double>`)
- Used during **evaluation** of the postfix expression.
- Stores numeric operands.
- Operators pop operands from the stack, compute the result, and push it back.

---

## 3. Class: `ExpressionConverter`

This class encapsulates all logic required for:
- Operator identification
- Precedence handling
- Infix to postfix conversion
- Postfix evaluation

---

## 4. Function Descriptions

### a) `bool isOperator(char c)`
**Purpose:**  
Checks whether a character is a valid mathematical operator (`+`, `-`, `*`, `/`, `^`).

---

### b) `int precedence(char opt)`
**Purpose:**  
Returns the precedence level of operators.

| Operator | Precedence |
|----------|------------|
| `^`      | 3 (highest) |
| `*`, `/` | 2 |
| `+`, `-` | 1 |

---

### c) `double useopt(double a, double b, char opt)`
**Purpose:**  
Performs the actual mathematical operation between two operands.

- Handles addition, subtraction, multiplication, division, and exponentiation.
- Throws an error if division by zero occurs.

---

### d) `string toPostfix(const string& infix)`
**Purpose:**  
Converts an infix expression into postfix notation.

**Process:**
1. Traverse the infix expression character by character.
2. If the character is a number, append it to the postfix string.
3. If an opening parenthesis `(` is found, push it to the stack.
4. If a closing parenthesis `)` is found, pop operators until `(` is encountered.
5. If an operator is found:
   - Pop operators from the stack while they have higher or equal precedence.
   - Push the current operator to the stack.
6. After traversal, pop all remaining operators from the stack to postfix.

---

### e) `double evaluate(const string& postfix)`
**Purpose:**  
Evaluates the postfix expression.

**Process:**
1. Traverse the postfix expression.
2. If a number is encountered, push it to the value stack.
3. If an operator is encountered:
   - Pop two values.
   - Perform the operation.
   - Push the result back to the stack.
4. The final value in the stack is the result.

---

### f) `double evaluateInfix(const string& infix)`
**Purpose:**  
Combines both steps:
1. Converts infix to postfix.
2. Evaluates the postfix expression.

---

## 5. Overview of `main()` Function

The `main()` function:

1. Creates an object of `ExpressionConverter`.
2. Defines three infix expressions:
   - `3+4-1`
   - `(4*4)/3`
   - `(2^7)*9`
3. Converts the first expression to postfix.
4. Evaluates the expression using `evaluateInfix()`.
5. Displays the postfix form and result.
6. Uses exception handling to catch runtime errors.

---

## 6. Sample Output

Expression
3+4-1 postfix:3 4 + 1 - result:6
(Other expressions can be tested similarly.)

---

## 7. Conclusion

- The program demonstrates how stacks can be used for expression parsing and evaluation.
- It correctly handles operator precedence and parentheses.
- The modular class design improves readability and reusability.

This implementation is a practical example of applying **stack data structures** to solve real computational problems in expression evaluation.

---
