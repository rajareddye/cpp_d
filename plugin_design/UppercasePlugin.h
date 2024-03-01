// UppercasePlugin.h
#pragma once
#include "PluginInterface.h"

class UppercasePlugin : public PluginInterface {
public:
    UppercasePlugin();  // Make sure the constructor is declared in the header.
    virtual std::string processText(const std::string& input) override;
};
