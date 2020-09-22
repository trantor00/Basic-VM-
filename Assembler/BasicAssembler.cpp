#include "Interpreter.h"

int main() {
	std::string filename = "sourcefile";
	readfile(filename);
	readARGS();
	assembler();
	writeAssembledfile();
	std::cout << "Source file is compiled. " << std::endl;

	return 0;
}

void readfile(std::string filename) {
	std::fstream FILE;
	FILE.open(filename, std::ios::in | std::ios::binary);
	while (FILE) {
		std::string newline;
		std::getline(FILE,newline);
		ARGS.push_back(newline);
	}
	FILE.close();
}

void readARGS() {
	if (!(ARGS.at(0).compare("execute:"))) {
		std::cout << "Error at line 1 -> execute: isn't found!" << std::endl;
		return;
	}
	std::cout << "Given source file : \n" << std::endl;
	for (std::vector<std::string>::iterator it = ARGS.begin(); it != ARGS.end();it++) {
		std::cout << *it << std::endl;
		std::string temparg = *it;
		int directive=READ;
			std::string code;
			int temp = 0;
				for (int i = 0; i < temparg.length(); i++) {
					if (temparg[i] == NEWLINE) {
						break;
					}
					else if (temparg[i] == SPACE) {
						code += " ";
						continue;
					}
					else if (temparg[i] == COMMENT && temparg[i+1] == COMMENT) {
						break;
					}
					else if (temparg[i] == COMMAND) {
						codes.push_back(code+";");
					}
					else {
						code+= temparg[i];
					}		
		}
	}
	
}

void assembler() {
	std::string datatypes[4] = {
		"int",
		"char",
		"string",
		"void"
	};
	for (std::vector<std::string>::iterator it = codes.begin(); it != codes.end(); it++) {
		std::string line = *it;
		std::string assembledcode;
		for (int x = 0; x < 4; x++) {   // DATA DECLARATION
			if (line.find(datatypes[x]) != std::string::npos) {
				for (int j = datatypes[x].length(); j < line.length(); j++) {
					if (line[j] == SPACE) {
						continue;
					}
					else if (line[j] == EQUALITION) {
						assembledcodes.push_back("PUSH");
						for (int i = j + 1; i < line.length(); i++) {
							if (line[i] == SPACE) {
								continue;
							}
							else if (line[i] == COMMAND) {
								assembledcodes.push_back(assembledcode);
								j = line.length();  // for halting the loop
								break;
							}
							else {
								assembledcode += line[i];
							}
						}
					}

				}break;
			}
		}
		if (line.find(ECHO) != std::string::npos) {  //echo
			assembledcodes.push_back("PRINT");
			for (int i = 4; i < line.length(); i++) {
				if (line[i] == SPACE) {
					continue;
				}
				else if (line[i] == COMMAND) {
					if (!(assembledcode[0] >= 48 && assembledcode[0] <= 57)) {
						int charvalue = assembledcode[0];
						assembledcodes.push_back(std::to_string(charvalue));
					}
					else {
						assembledcodes.push_back(assembledcode);
					}
					break;
				}
				else if (line[i] == '"') {
					i++;
					while (line[i] != '"') {
						assembledcode += line[i];
						i++;
					}
					int stringvalue = 0;
					for (int j = assembledcode.length() - 1; j > 0; j--) {
						stringvalue += (int)pow(assembledcode[j], assembledcode.length() - j);
					}
					assembledcodes.push_back(std::to_string(stringvalue));
					break;
				}
				else {
					assembledcode += line[i];
				}
			}
		}
	}
	assembledcodes.push_back("HALT");

}
void writeAssembledfile() {
	std::string filename = "assembledfile";
	std::fstream FILE;
	FILE.open(filename, std::ios::out | std::ios::binary);
	for (std::vector<std::string>::iterator it = assembledcodes.begin(); it != assembledcodes.end(); it++) {
		FILE << *it << std::endl;
	}
	FILE.close();
}






