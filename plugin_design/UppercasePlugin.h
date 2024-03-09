// UppercasePlugin.h
#pragma once
#include "PluginInterface.h"

class UppercasePlugin : public PluginInterface {
public:
    virtual std::string processText(const std::string& input) override;
};