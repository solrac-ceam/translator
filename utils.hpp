#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "json.hpp"

nlohmann::json createConfigFile(std::string pathname);
nlohmann::json readConfigurations(std::string pathname);
void saveConfigutarions(nlohmann::json settings, std::string pathname);

#endif // UTILS_HPP
