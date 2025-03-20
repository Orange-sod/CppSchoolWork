#ifndef HTML_GENERATOR_H
#define HTML_GENERATOR_H

#include <string>

void GenerateHeaders(const std::string& outputUrl); //output first, use ios::out
void GenerateSystemInfo(const std::string& outputUrl, const std::string& date,
						const std::string& IP, const std::string& Agent);
void GenerateOutput(const std::string& outputUrl,
					const int& firstCount, const int& secondCount,
					const std::string& firstMsg, const std::string& secondMsg);

void GenerateFooters(const std::string& outputUrl, const int& firstCount, const int& secondCount); //output later, use ios::app

#endif
