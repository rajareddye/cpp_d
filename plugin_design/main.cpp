// main.cpp
#include "PluginManager.h"

int main() {
    PluginManager pluginManager("./libUppercasePlugin.so");

    std::string inputText = "Hello, World!";
    // plugnManager.processTextWithPlugins(onpu)
    pluginManager.processTextWithPlugins(inputText);

    return 0;
}
