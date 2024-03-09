// PluginManager.cpp
#include "PluginManager.h"
#include <iostream>

void PluginManager::processTextWithPlugins(const std::string& input) {
    std::string result = input;
    for (const auto& plugin : plugins) {
        result = plugin->processText(result);
    }

    std::cout << "Processed text: " << result << std::endl;
}