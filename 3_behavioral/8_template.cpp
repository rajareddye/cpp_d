/*
Template Method:
Template Method Pattern introduces a template in a superclass that defines the steps of an algorithm. 
These steps may include both common tasks shared among subclasses and specific tasks that need customization. 
Subclasses then implement or override these steps to modify the algorithm according to their specific needs.


*/

#include <iostream>

// Step 1: Template Method (Abstract Class)
class VehicleTemplate {
public:
	// Template method defines the algorithm structure
	void buildVehicle() {
		assembleBody();
		installEngine();
		addWheels();
		std::cout << "Vehicle is ready!\n";
	}

	// Abstract methods to be implemented by concrete classes
	virtual void assembleBody() = 0;
	virtual void installEngine() = 0;
	virtual void addWheels() = 0;
};

// Step 2: Concrete Classes
class Car : public VehicleTemplate {
public:
	void assembleBody() override {
		std::cout << "Assembling car body.\n";
	}

	void installEngine() override {
		std::cout << "Installing car engine.\n";
	}

	void addWheels() override {
		std::cout << "Adding 4 wheels to the car.\n";
	}
};

class Motorcycle : public VehicleTemplate {
public:
	void assembleBody() override {
		std::cout << "Assembling motorcycle frame.\n";
	}

	void installEngine() override {
		std::cout << "Installing motorcycle engine.\n";
	}

	void addWheels() override {
		std::cout << "Adding 2 wheels to the motorcycle.\n";
	}
};

// Step 3: Client Code
int main() {
	std::cout << "Building a Car:\n";
	Car car;
	car.buildVehicle();

	std::cout << "\nBuilding a Motorcycle:\n";
	Motorcycle motorcycle;
	motorcycle.buildVehicle();

	return 0;
}
