#include "OtherInfo.h"

std::string getCurrentDateTime() {
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
	return std::string(buffer);
}

std::string getUserIP() {
	const char* ip = std::getenv("REMOTE_ADDR");
	return ip ? std::string(ip) : "Unknown";
}

std::string getUserAgent() {
	const char* userAgent = std::getenv("HTTP_USER_AGENT");
	return userAgent ? std::string(userAgent) : "Unknown";
}