#include <iostream>

extern "C" {
    void appFunction() {
        std::cout << "Hello from the application!" << std::endl;
    }
}