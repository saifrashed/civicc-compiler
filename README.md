## Civicc Compiler
Civicc Compiler is a compiler for the Civicc programming language. The compiler uses Flex for lexical analysis and Bison for parsing. The compiler is designed to generate assembly code for the x86 architecture.

## Requirements
To run the Civicc Compiler, the following software must be installed on your system:

Flex
Bison
Clang (or any C compiler that supports the x86 architecture)
Graphviz (for creating a diagram)

## Installation

1. Download or clone the Civicc Compiler source code from the repository.
2. Install Flex, Bison, and Clang on your system.
3. Install Graphviz using Homebrew: brew install graphviz

## Additional commands

### Running compiler:
- cd build-debug/
- make
- ./civicc ../test/test1.cvc

### Running flex:
- flex -d lexer.l
- clang -ll lex.yy.c -o scanner

### To create a diagram:
- brew install graphviz

### To check parser for conflicts:
- bison --verbose parser.y;
- bison --verbose -Wcounterexamples parser.y
