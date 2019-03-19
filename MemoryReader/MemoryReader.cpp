#include<iostream>
#include<Windows.h>
#include<string>
#include <sstream>

using namespace std;
void errorGen(string errorType, int exitType);
string convertToHex(int number);
int main()
{
	cout << "Please enter  program" << endl;
	string programName;
	getline(cin, programName);
	HWND hwnd = FindWindowA(NULL, programName.c_str());

	if (hwnd == NULL)
	{
		errorGen("Could not find program", -2); // -2 = Failed to find program name
	}
	cout << "Program Found!" << endl;
	DWORD procID;
	GetWindowThreadProcessId(hwnd, &procID);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
	if (procID == NULL)
	{
		errorGen("Could not find process ID", -3); // -3 = failed procces ID
	}
	return 0;
}

string convertToHex(int number)
{	
	stringstream ss;
	ss << hex << number;
	return "0x" + ss.str();
}

void errorGen(string errorType, int exitType)
{
	cout << errorType << endl; // outputs text then outputs an end line
	Sleep(3000);
	exit(exitType); // exits program with error type
}