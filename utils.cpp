#include "utils.hpp"

#include <fstream>
#include <sstream>

nlohmann::json createConfigFile(std::string pathname)
{
	std::ofstream configFile(pathname, std::ios_base::out|std::ios_base::trunc);
	nlohmann::json defaultSetting = {
		{"from","auto"},
		{"to", "es"},
		{"home", "es"},
		{"choice columns", 3}
	};
	configFile << defaultSetting << std::endl;
	return defaultSetting;
}

nlohmann::json readConfigurations(std::string pathname)
{
	std::ifstream configFile(pathname);
	std::stringstream buffer;
	buffer << configFile.rdbuf();
	nlohmann::json settings = nlohmann::json::parse(buffer.str());
	return settings;
}

void saveConfigutarions(nlohmann::json settings, std::string pathname)
{
	std::ofstream configFile(pathname, std::ios_base::out|std::ios_base::trunc);
	configFile << settings << std::endl;
}
