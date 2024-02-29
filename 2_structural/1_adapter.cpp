/*
used to make two incompatible interfaces work together. It acts as a bridge between two incompatible interfaces, 
allowing them to collaborate without modifying their source code. 
This pattern is particularly useful when integrating legacy code or third-party libraries into your application.

Suppose you have a legacy printer class that only understands commands in uppercase, 
and a modern computer class that sends commands in lowercase. 
You need to make the modern computer work with the legacy printer without modifying the existing printer class.
*/
#include <iostream>
#include <string>

// Legacy Printer (Adaptee)
class LegacyPrinter {
public:
	void printInUppercase(const std::string& text)
	{
		std::cout << "Printing: " << text << std::endl;
	}
};

// Modern Computer (Client)
class ModernComputer {
public:
	void sendCommand(const std::string& command)
	{
		std::cout << "Sending command: " << command
				<< std::endl;
	}
};

// Adapter class to make the LegacyPrinter compatible with
// ModernComputer
class PrinterAdapter {
private:
	LegacyPrinter legacyPrinter;

public:
	void sendCommand(const std::string& command)
	{
		// Convert the command to uppercase and pass it to
		// the LegacyPrinter
		std::string uppercaseCommand = command;
		for (char& c : uppercaseCommand) {
			c = std::toupper(c);
		}
		legacyPrinter.printInUppercase(uppercaseCommand);
	}
};

int main()
{
	ModernComputer computer;
	PrinterAdapter adapter;

	computer.sendCommand("Print this in lowercase");
	adapter.sendCommand(
		"Print this in lowercase (adapted)");

	return 0;
}
