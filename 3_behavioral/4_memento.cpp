/*

provides a mechanism for capturing an object’s internal state and restoring it to that state at a later time. 
This pattern is useful when we need to implement features like undo/redo functionality or 
when we want to save and restore an object’s state for various reasons.

*/

#include <iostream>
#include <string>
#include <vector>

// Originator: The object whose state needs to be saved and restored.
class Originator {
private:
	std::string state;

public:
	void SetState(const std::string& newState) {
		state = newState;
	}

	std::string GetState() const {
		return state;
	}

	// Memento: Inner class representing the state of the Originator.
	class Memento {
	private:
		std::string state;

	public:
		Memento(const std::string& originatorState) : state(originatorState) {}

		std::string GetSavedState() const {
			return state;
		}
	};

	// Create a Memento object to save the current state.
	Memento CreateMemento() const {
		return Memento(state);
	}

	// Restore the state from a Memento object.
	void RestoreState(const Memento& memento) {
		state = memento.GetSavedState();
	}
};

// Caretaker: Manages the Memento objects.
class Caretaker {
private:
	std::vector<Originator::Memento> mementos;

public:
	void AddMemento(const Originator::Memento& memento) {
		mementos.push_back(memento);
	}

	Originator::Memento GetMemento(int index) const {
		if (index >= 0 && index < mementos.size()) {
			return mementos[index];
		}
		throw std::out_of_range("Invalid Memento index");
	}
};

int main() {
	Originator originator;
	Caretaker caretaker;

	originator.SetState("State 1");
	caretaker.AddMemento(originator.CreateMemento());

	originator.SetState("State 2");
	caretaker.AddMemento(originator.CreateMemento());

	// Restore to the previous state
	originator.RestoreState(caretaker.GetMemento(0));
	std::cout << "Current state: " << originator.GetState() << std::endl;

	// Restore to an even earlier state
	originator.RestoreState(caretaker.GetMemento(1));
	std::cout << "Current state: " << originator.GetState() << std::endl;

	return 0;
}
