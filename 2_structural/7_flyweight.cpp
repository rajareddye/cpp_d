/*
Flyweight Pattern:
used to optimize memory usage and performance when dealing with a large number of objects that share some common characteristics. 
It achieves this by separating an object’s intrinsic state (shared among multiple objects) 
from its extrinsic state (unique to each object) and storing the intrinsic state externally, 
typically within a Flyweight factory. This pattern is particularly useful when you need to create a 
significant number of similar objects and want to minimize the memory footprint.

*/

#include <iostream>
#include <unordered_map>

// Flyweight class
class Character {
public:
	Character(char intrinsicState) : m_intrinsicState(intrinsicState) {}

	void draw(int extrinsicState) {
		std::cout << "Drawing character '" << m_intrinsicState << "' at position " << extrinsicState << std::endl;
	}

private:
	char m_intrinsicState;
};

// Flyweight factory
class CharacterFactory {
public:
	Character* getCharacter(char key) {
		if (m_characters.find(key) == m_characters.end()) {
			m_characters[key] = new Character(key);
		}
		return m_characters[key];
	}

private:
	std::unordered_map<char, Character*> m_characters;
};

int main() {
	CharacterFactory characterFactory;

	// Extrinsic state
	int position = 0;

	// Drawing characters 'A', 'B', 'C' at different positions
	characterFactory.getCharacter('A')->draw(position++);
	characterFactory.getCharacter('B')->draw(position++);
	characterFactory.getCharacter('C')->draw(position++);

	return 0;
}
