# CoCo

This gives a base for your own civicc compiler.
Clone this repo: 
```bash
git clone git@github.com:CoCoNut-UvA/civicc-skeleton.git civicc
cd civicc
./configure.sh
```
If everything went correctly, a build-debug directory is created. 
Run
```bash
make -C build-debug
```
to build your compiler.

**IMPORTANT**: After cloning, you should change the remote to point to a **private** repo you control.
You can **not** achieve this via forking, because GitHub does not allow changing the visibility of a forked repo.

# Creating an archive
You can quickly create an archive for submitting to canvas as follows
```
make dist
```
this gets everything in your git repo and combines it with the used coconut version in one archive.
This should contain everything needed to hand in your assignments.
**NOTE** Always check the resulting archive if it contains everything and builds correctly.


program: stmts
         {
           parseresult = $1;
         }
         ;

a = (43-2);
b = (true*7);
c = ((a + b) - c);
d = ((7-7) * 0);
e = (c - c);







## Introduction
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

### Running flex:
- flex -d lexer.l
- clang -ll lex.yy.c -o scanner

### To create a diagram:
- brew install graphviz

### To check parser for conflicts:
- bison --verbose parser.y;
- bison --verbose -Wcounterexamples parser.y
