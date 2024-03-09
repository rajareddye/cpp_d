#include <iostream>
#include <dlfcn.h>

typedef void (*AppFunction)();

int main() {
    void* handle = dlopen("./application.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error loading the library: " << dlerror() << std::endl;
        return 1;
    }

    AppFunction appFunction = (AppFunction)dlsym(handle, "appFunction");
    if (!appFunction) {
        std::cerr << "Error finding the function: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    appFunction();

    dlclose(handle);
    return 0;
}