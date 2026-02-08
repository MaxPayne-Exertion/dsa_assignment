# Documentation for Question 1  
## Balanced Parentheses Checker Using Stack

---

## 1. Problem Overview

This program checks whether a given mathematical expression contains a **balanced number of parentheses**.  
The parentheses considered are:
- Round brackets: `()`
- Square brackets: `[]`
- Curly brackets: `{}`

The program uses a **stack-based approach** to ensure that:
- Every opening bracket has a corresponding closing bracket.
- Brackets are closed in the correct order.

The program is tested on the following expressions:
- `a + (b − c) ∗ (d`
- `m + [a − b ∗ (c + d ∗ {m)]`
- `a + (b − c)`

---

## 2. Data Structures Used

### Stack (`stack<char>`)

- A stack of characters is used to store **opening brackets** encountered while scanning the expression.
- The stack follows **Last In, First Out (LIFO)** order, which is ideal for matching nested brackets.
- Opening brackets `(`, `{`, `[` are pushed onto the stack.
- When a closing bracket is found, the top element of the stack is checked for a matching pair.

This ensures correct **nesting and order** of brackets.

---

## 3. Function Description

### `bool Balanced(string expression)`

**Purpose:**  
Checks whether the given expression has balanced parentheses.

**Logic:**
1. Traverse each character of the expression.
2. If the character is an opening bracket (`(`, `{`, `[`), push it onto the stack.
3. If the character is a closing bracket:
   - If the stack is empty → expression is unbalanced.
   - Pop the top element and check if it matches the type of closing bracket.
4. After processing the entire expression:
   - If the stack is empty → expression is balanced.
   - Otherwise → unbalanced.

**Return Value:**
- `true` → Expression is balanced
- `false` → Expression is not balanced

---

## 4. Overview of `main()` Function

The `main()` function performs the following steps:

1. Declares three test expressions as strings.
2. Prints each expression.
3. Calls the `Balanced()` function for each expression.
4. Displays whether the expression is **BALANCED** or **NOT BALANCED** based on the function’s return value.

This structure allows easy testing of multiple expressions in a single program run.

---

## 5. Sample Output

a+(b-c)*(d
NOT BALANCED

m+[a-b*(c+d*{)]
NOT BALANCED

a+(b-c)
IS BALANCED


---

## 6. Conclusion

- The program efficiently checks balanced parentheses using a stack.
- It correctly identifies missing or mismatched brackets.
- The approach is scalable and works for expressions containing multiple bracket types.

This implementation demonstrates a practical application of the **stack data structure** in syntax validation problems.

---
