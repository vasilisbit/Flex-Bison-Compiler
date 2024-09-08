
# OOP Language Compiler with Lex and Bison

## Overview
This project is a compiler for a simple object-oriented programming (OOP)
language, developed using **Lex** and **Bison**. The compiler handles
lexical analysis, syntax parsing, and semantic checking for class
declarations, method calls, variable assignments, and basic control
flow constructs.

The main goal is to demonstrate the creation of a basic compiler that
can process an OOP language, including parsing class declarations,
methods, variables, and basic expressions.

## Features
- Lexical analysis using Flex for tokenizing input.
- Syntax analysis using Bison to construct the syntax tree.
- Semantic checks for type matching and scope validation.
- Support for basic control flow (`if`, `while`, `for`), method calls,
  and object instantiation.

## Files in Repository
- **project.l**: Lex specification file for lexical analysis.
- **project.y**: Bison grammar file for syntax analysis.
- **Makefile**: Build script to compile the project.
- **input.txt**: Example input file containing a test OOP program.
- **output.txt**: The compiler's output file after processing the input.
- **project.tab.c**: Bison-generated C file for the parser.
- **project.tab.h**: Bison-generated header file.
- **lex.yy.c**: Flex-generated C file for the lexer.

## Directory Structure
```
Flex-Bison-Compiler/
|
├── Licence
├── Makefile
├── README.md
├── error.cpp
├── error.h
├── errors.txt
├── input.txt
├── lex.yy.c
├── myParser.exe
├── output.txt
├── parser_log.txt
├── project.l
├── project.tab.c
├── project.tab.h
├── project.y
├── Παραδοχές.txt
│   
```

## How to Build and Run
### Prerequisites
Ensure you have the following installed:
- **Flex**: Fast lexical analyzer generator
- **Bison**: Parser generator
- **GCC**: GNU Compiler Collection

### Steps to Build
1. Clone the repository:
    ```bash
    git clone https://github.com/your-repository-name.git
    cd your-repository-name
    ```

2. Compile the project using the Makefile:
    ```bash
    make
    ```

This command will:
- Generate `project.tab.c` and `project.tab.h` from the Bison grammar file.
- Generate `lex.yy.c` from the Lex file.
- Compile all generated C files and link them into an executable `myParser`.

### Running the Compiler
To run the compiler on a test program:
 ```bash
 ./myParser input.txt
 ```

This will process the `input.txt` file and generate an output in `output.txt`.

## Example Input
 ```cpp
 public class Test {
     public void main(int x, int y) {
         x = 0;
     }
 }
 ```

## Example Output
```text
Collected Assignments:
1) Variable x assigned with value 0

Input Program:
   1  | public class Test {
   2  |     public void main(int x, int y) {
   3  |         x = 0;
   4  |     }
   5  | }

Program is syntactically correct.
 ```

## Error Handling
- The compiler will print error messages with the line number if it
  encounters any syntax or semantic errors.
- Example error message:
    ```text
    Error at line 6: Unexpected character '!'
    ```

## License
 This project is licensed under the MIT License. See the LICENSE file for more details.

