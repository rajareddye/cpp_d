// PluginManager.h
#pragma once
#include <vector>
#include <memory>
#include "PluginInterface.h"

class PluginManager {
public:
    void processTextWithPlugins(const std::string& input);

private:
    std::vector<std::unique_ptr<PluginInterface>> plugins;
};