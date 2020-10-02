#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

std::vector<std::string> ARGS;
std::vector<std::string> codes;
std::vector<std::string> assembledcodes;

#define SPACE ' '
#define NEWLINE '\n'
#define TAB '\t'
#define COMMENT '/'
#define COMMAND ';'

#define EQUALITION '='
#define ADDITION '+'
#define SUBTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'
#define ECHO "echo"
#define RETURN "return"

enum directives {
	READ,
	READKEY,
	STOP  };


//prototypes
extern "C" void readfile(std::string filename);
extern "C" void readARGS();
extern "C" void assembler();
extern "C" void writeAssembledfile(std::string filename);
