/*
Factory Method Pattern in C++:
Real-World Example of the Factory Method in C++
Imagine you want to build different types of things, like toys. You have a general idea of how toys are made, 
but you want different people to make different kinds of toys

The Factory Method is like a plan for making toys, but it doesn’t specify exactly what kind of toy you’re making.
It lets you create a plan (a method) that says, This is how you make a toy, without saying which toy it is.
Other people (subclasses) can use your plan to make their own types of toys. 
They just have to follow your plan and fill in the details for their specific toy.
This way you can make various toys without knowing exactly which one you’re making. 
It also keeps things neat and organized because each type of toy has its own set of instructions (a class) to follow.
In simple terms, the Factory Method Pattern is like a recipe for making things, 
but it lets different chefs (subclasses) create their own unique versions of those things while sticking to the same basic cooking instructions 

In this client code, we first create instances of the concrete creators (circleFactory and squareFactory) 
and then use them to create instances of concrete products (cirlce and square). 
Finally, we call the draw() method on these objects, which produces the expected output.
*/

// Abstract product class
#include <bits/stdc++.h>
class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() {
	} // Virtual destructor for polymorphism
};
// Concrete product class - Circle
class Circle : public Shape {
public:
	void draw() override
	{
		std::cout << "Drawing a Circle" << std::endl;
	}
};

// Concrete product class - Square
class Square : public Shape {
public:
	void draw() override
	{
		std::cout << "Drawing a Square" << std::endl;
	}
};
// Abstract creator class
class ShapeFactory {
public:
	virtual Shape* createShape() = 0;
	virtual ~ShapeFactory() {
	} // Virtual destructor for polymorphism
};
// Concrete creator class - CircleFactory
class CircleFactory : public ShapeFactory {
public:
	Shape* createShape() override { return new Circle(); }
};

// Concrete creator class - SquareFactory
class SquareFactory : public ShapeFactory {
public:
	Shape* createShape() override { return new Square(); }
};
int main()
{
	ShapeFactory* circleFactory = new CircleFactory();
	ShapeFactory* squareFactory = new SquareFactory();

	Shape* circle = circleFactory->createShape();
	Shape* square = squareFactory->createShape();

	circle->draw(); // Output: Drawing a Circle
	square->draw(); // Output: Drawing a Square

	delete circleFactory;
	delete squareFactory;
	delete circle;
	delete square;

	return 0;
}
