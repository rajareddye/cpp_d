// PluginManager.cpp
#include "PluginManager.h"
#include <iostream>

PluginManager::PluginManager(const std::string& libraryPath) : libraryHandle(nullptr) {
    // Load the shared library dynamically
    libraryHandle = dlopen(libraryPath.c_str(), RTLD_LAZY);
    if (!libraryHandle) {
        std::cerr << "Error loading library: " << dlerror() << std::endl;
        return;
    }

    // Function pointer to create a PluginInterface instance from the loaded library
    using CreatePluginFunc = PluginInterface* (*)();
    CreatePluginFunc createPlugin = reinterpret_cast<CreatePluginFunc>(dlsym(libraryHandle, "createPlugin"));
    if (!createPlugin) {
        std::cerr << "Error loading symbol: " << dlerror() << std::endl;
        dlclose(libraryHandle);
        return;
    }

    std::unique_ptr<PluginInterface> plugin(createPlugin());
    if (plugin) {
        plugins.push_back(std::move(plugin));
    } else {
        std::cerr << "Error creating plugin instance." << std::endl;
    }
}

void PluginManager::processTextWithPlugins(const std::string& input) {
    if (!libraryHandle) {
        std::cerr << "Library not loaded." << std::endl;
        return;
    }

    std::string result = input;
    for (const auto& plugin : plugins) {
        result = plugin->processText(result);
    }

    std::cout << "Processed text: " << result << std::endl;
}

PluginManager::~PluginManager() {
    // Close the library handle when the PluginManager is destroyed
    if (libraryHandle) {
        dlclose(libraryHandle);
    }
}
