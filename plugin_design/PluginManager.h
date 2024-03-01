// PluginManager.h
#pragma once
#include <vector>
#include <memory>
#include <dlfcn.h>
#include "PluginInterface.h"

class PluginManager {
public:
    PluginManager(const std::string& libraryPath);
    void processTextWithPlugins(const std::string& input);
    ~PluginManager();

private:
    std::vector<std::unique_ptr<PluginInterface>> plugins;
    void* libraryHandle;  // Handle to the loaded library
};
