#include "Logger.hpp"

Logger::Logger()
{

}

Logger::~Logger()
{

}

void Logger::log(std::string message)
{
    std::cout << "[LOG] " << message << std::endl;
}