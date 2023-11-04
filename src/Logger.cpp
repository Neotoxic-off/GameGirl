#include "Logger.hpp"

Logger::Logger()
{

}

Logger::~Logger()
{

}

void Logger::Log(std::string entity, std::string message)
{
    std::cout << "[+] " << entity << ": " << message << std::endl;
}