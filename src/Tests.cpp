#include "Tests.hpp"

Tests::Tests()
{
    this->logger = Logger();
}

Tests::~Tests()
{
    
}

void Tests::Run()
{
    this->logger.Log("tests", "running tests");
    this->logger.Log("tests", "all tests completed");
}
