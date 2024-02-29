/*
Proxy Pattern:
that provides a surrogate or placeholder for another object, allowing you to control access to it. 
This pattern can be particularly useful in situations where you need to add an extra layer of control, lazy loading,
 or remote access to objects.
In simple terms, the Proxy Pattern is like having a middle person (proxy) who decides when to get help from the 
real expert (real object) and when to handle things themselves. It’s a way to manage and control access to 
someone’s skills without bothering them unnecessarily.
*/

#include <bits/stdc++.h>

using namespace std;

class Image {
public:
	virtual void display() = 0;
};

class RealImage : public Image {
private:
	std::string filename;

public:
	RealImage(const std::string& filename) : filename(filename) {
		// Simulate loading the image (this can be a resource-intensive operation)
		std::cout << "Loading image: " << filename << std::endl;
	}

	void display() override {
		std::cout << "Displaying image: " << filename << std::endl;
	}
};

class ImageProxy : public Image {
private:
	RealImage* realImage; // Reference to the Real Object
	std::string filename;

public:
	ImageProxy(const std::string& filename) : filename(filename), realImage(nullptr) {}

	void display() override {
		// The Proxy checks if the Real Object is created and loads it if necessary
		if (realImage == nullptr) {
			realImage = new RealImage(filename);
		}
		realImage->display();
	}
};

int main() {
	// Create a proxy to an image
	Image* image = new ImageProxy("example.jpg");

	// Display the image (the Proxy will load the Real Object if necessary)
	image->display();

	// Displaying the image again (the Proxy won't reload it)
	image->display();

	delete image; // Clean up

	return 0;
}
