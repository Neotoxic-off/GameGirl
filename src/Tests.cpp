#include "Tests.hpp"

Tests::Tests()
{
    this->logger = new Logger();
    this->rom = new Rom(this->logger, std::string("tests/rom test.gba"));
    this->cpu = new CPU(this->logger, new uint8_t(this->rom->size));
}

Tests::~Tests()
{
    delete[] this->cpu;
    delete[] this->rom;
    delete[] this->logger;
}

void Tests::TEST_CPU()
{
    std::string status = "failed";
    std::map<std::string, std::function<bool(void)>> tests = {
        { "INC_B", std::bind(&Tests::TEST_INC_B, this) }
    };

    this->logger->Log("tests", "running CPU");

    for (const auto& test : tests) {
        if (test.second() == true) {
            status = "success";
        } else {
            status = "failed";
        }
        this->logger->Log(test.first, status);
    }

    this->logger->Log("tests", "all tests CPU complete");
}

bool Tests::TEST_INC_B()
{
    uint8_t b = this->cpu->registers->b;

    this->cpu->INC_B();

    return (this->cpu->registers->b == (b += 1));
}

void Tests::TEST_Rom()
{
    this->logger->Log("tests", "-> running Rom");
    this->logger->Log("tests", "-> all tests Rom complete");
}

void Tests::TEST_Run()
{
    this->logger->Log("tests", "running tests");

    this->TEST_CPU();
    this->TEST_Rom();

    this->logger->Log("tests", "all tests completed");
}
