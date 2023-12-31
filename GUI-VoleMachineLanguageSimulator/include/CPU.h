#pragma once
#include "Byte.h"
#include<string>

class CPU
{
private:
	std::string m_validInstructions[11];

	// Take a Hexadecimal number and convert it to decimal number
	int ToDecimal(std::string HEX);

	// Take a decimal number and convert it to Hexadecimal number
	std::string ToHEX(int number);

	// Add two Byte number in twoscomplement format
	Byte add(Byte b1, Byte b2);

	// Bitwise AND between two byte
	Byte AND(Byte b1, Byte b2);

	// Bitwise OR between two byte
	Byte OR(Byte b1, Byte b2);

public:
	Byte cpuRegister[16];
	std::string IR="0000";
	bool isHalt = false;
	int programCounter{};
	CPU();

	// Take instruction and put it in IR
	void FetchInstruction(Byte mainMemory[]);

	// Check if instruction in IR is valid or not
	bool IsValidInstruction();

	// Excute instruction and make changes in main memory and register
	void ExecuteInstruction(Byte mainMemory[], char& screen);

	// Make all values in register equal 0
	void ResetCPU();

};

