// UppercasePlugin.cpp
#include "UppercasePlugin.h"
#include <algorithm>

std::string UppercasePlugin::processText(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}