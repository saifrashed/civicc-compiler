## Civicc Compiler
Civicc Compiler is a compiler for the Civicc programming language. The compiler uses Flex for lexical analysis and Bison for parsing. The compiler is designed to generate assembly code for the x86 architecture.

## Requirements
To run the Civicc Compiler, the following software must be installed on your system:

Bison. Bison requires a modern version (>=3). Default on macOS Monterey is too old.
Flex
Cmake (> 3.13)
GCC or Clang. Clang needs the zero-variadic-macro-arguments extension and you might need to supress warnings for functions with variadic arguments.
Graphviz is required if you want to turn the generated dot diagram into an image via make dot

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

### To run civicc tool chain:
civas test
civvm civ.out

To create a assembly file  ./civicc ../test/arrays/check_success/scopes.cvc -o test  - in build-debug for own
To create a assembly file  ../civcc ../test/arrays/check_success/test.cvc -o test    - in bin for reference