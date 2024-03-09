// PluginInterface.h
#pragma once
#include <string>

class PluginInterface {
public:
    virtual std::string processText(const std::string& input) = 0;
    virtual ~PluginInterface() = default;
};