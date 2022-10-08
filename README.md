# x86cc
x86 C Compiler

## Todo 
- [ ] Default configuration file in /usr/share/x86cc/x86cc.conf
- [ ] Read configuration file search for one in /etc/x86cc.conf or ~/.share/x86cc.conf.
- [ ] Lexical Analysis
- [ ] Abstract Syntax Tree
- [ ] Code Generation
- [ ] Linking

## Goal

The goal of this project is to create a C99 standard-compliant compiler for the x86 architecture.
If you wish this project to include a certain standard, be sure to implement it yourself. PRs are welcome!

## Building

It's built with cmake. You know how to compile this.

## Arguments
Usage:
    x86cc [options] input

Options:
    --std           Set the standard to use. (C99 default)
    --output        Set the output file. (a.out default)