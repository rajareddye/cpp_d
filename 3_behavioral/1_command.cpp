/*
Command Pattern:
focuses on encapsulating a request as an object, thereby decoupling the sender of the request from the receiver. 
This pattern allows you to parameterize objects with commands, delay or queue a request’s execution, and support undoable operations. 
It’s a fundamental pattern for implementing a wide range of functionality in software systems.
Problem statement: Design a system that demonstrates the use of the Command Pattern to decouple the sender and receiver of a request. 
The system should consist of several key components: Command, 
Concrete Command, Receiver, and Invoker.
*/


#include <iostream>
#include <vector>

// Receiver: Electronic Device
class ElectronicDevice {
private:
	std::string name;

public:
	ElectronicDevice(const std::string& n)
		: name(n)
	{
	}

	void turnOn()
	{
		std::cout << name << " is now ON." << std::endl;
	}

	void turnOff()
	{
		std::cout << name << " is now OFF." << std::endl;
	}
};

// Command interface
class Command {
public:
	virtual void execute() = 0;
};

// Concrete Command: Turn on
class TurnOnCommand : public Command {
private:
	ElectronicDevice& device;

public:
	TurnOnCommand(ElectronicDevice& dev)
		: device(dev)
	{
	}

	void execute() { device.turnOn(); }
};

// Concrete Command: Turn off
class TurnOffCommand : public Command {
private:
	ElectronicDevice& device;

public:
	TurnOffCommand(ElectronicDevice& dev)
		: device(dev)
	{
	}

	void execute() { device.turnOff(); }
};

// Invoker: Remote Control
class RemoteControl {
private:
	std::vector<Command*> commands;

public:
	void addCommand(Command* cmd)
	{
		commands.push_back(cmd);
	}

	void pressButton(int slot)
	{
		if (slot >= 0 && slot < commands.size()) {
			commands[slot]->execute();
		}
	}
};

int main()
{
	// Create electronic devices
	ElectronicDevice tv("TV");
	ElectronicDevice lights("Lights");

	// Create commands for turning devices on and off
	TurnOnCommand turnOnTV(tv);
	TurnOffCommand turnOffTV(tv);
	TurnOnCommand turnOnLights(lights);
	TurnOffCommand turnOffLights(lights);

	// Create a remote control
	RemoteControl remote;

	// Set commands for remote buttons
	remote.addCommand(&turnOnTV); // Button 0: Turn on TV
	remote.addCommand(&turnOffTV); // Button 1: Turn off TV
	remote.addCommand(
		&turnOnLights); // Button 2: Turn on Lights
	remote.addCommand(
		&turnOffLights); // Button 3: Turn off Lights

	// Press buttons on the remote
	remote.pressButton(0); // Turn on TV
	remote.pressButton(3); // Turn off Lights
	remote.pressButton(1); // Turn off TV
	remote.pressButton(2); // Turn on Lights

	return 0;
}



/*
Above is the step by step process to implement above problem statement:

Create an interface or base class Command that defines a execute method, which should be implemented by concrete commands.
Implement concrete command classes, such as TurnOnCommand and TurnOffCommand, to encapsulate specific actions for turning electronic devices on and off.
Create a receiver class ElectronicDevice for the electronic devices that need to be controlled. It should have methods to turn the device on and off.
Design an Invoker class RemoteControl to manage and execute the commands. It should provide the following features:
The ability to add commands to specific buttons on the remote control.
A method to press a button, which triggers the associated command’s execution.
Demonstrate the functionality by creating instances of electronic devices (e.g., TV, lights), concrete commands (turn on TV, turn off lights), and a remote control.
Users should be able to press the buttons on the remote control to turn electronic devices on and off.
Ensure that the system is flexible and extensible, allowing for easy addition of new electronic devices and commands without modifying existing code.
*/
