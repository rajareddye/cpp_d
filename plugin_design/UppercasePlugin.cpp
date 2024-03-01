// UppercasePlugin.cpp
#include "UppercasePlugin.h"
#include "PluginInterface.h" // Include the missing header file

UppercasePlugin::UppercasePlugin() {
    // Constructor implementation if needed.
}
extern "C" PluginInterface* createPlugin() {
    return new UppercasePlugin();
}
