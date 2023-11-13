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
        { "INC_B", std::bind(&Tests::TEST_INC_B, this) },
        { "DEC_B", std::bind(&Tests::TEST_DEC_B, this) },
        { "INC_C", std::bind(&Tests::TEST_INC_C, this) },
        { "DEC_C", std::bind(&Tests::TEST_DEC_C, this) },
        { "INC_D", std::bind(&Tests::TEST_INC_D, this) },
        { "DEC_D", std::bind(&Tests::TEST_DEC_D, this) },
        { "INC_E", std::bind(&Tests::TEST_INC_E, this) },
        { "DEC_E", std::bind(&Tests::TEST_DEC_E, this) },
        { "INC_H", std::bind(&Tests::TEST_INC_H, this) },
        { "DEC_H", std::bind(&Tests::TEST_DEC_H, this) },
        { "INC_L", std::bind(&Tests::TEST_INC_L, this) },
        { "DEC_L", std::bind(&Tests::TEST_DEC_L, this) }
    };

    this->logger->Log("tests", "running CPU");

    for (const auto& test : tests) {
        if (test.second() == true) {
            status = "passed";
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

bool Tests::TEST_DEC_B()
{
    uint8_t b = this->cpu->registers->b;

    this->cpu->DEC_B();

    return (this->cpu->registers->b == (b -= 1));
}

bool Tests::TEST_INC_C()
{
    uint8_t c = this->cpu->registers->c;

    this->cpu->INC_C();

    return (this->cpu->registers->c == (c += 1));
}

bool Tests::TEST_DEC_C()
{
    uint8_t c = this->cpu->registers->c;

    this->cpu->DEC_C();

    return (this->cpu->registers->c == (c -= 1));
}

bool Tests::TEST_INC_D()
{
    uint8_t d = this->cpu->registers->d;

    this->cpu->INC_D();

    return (this->cpu->registers->d == (d += 1));
}

bool Tests::TEST_DEC_D()
{
    uint8_t d = this->cpu->registers->d;

    this->cpu->DEC_D();

    return (this->cpu->registers->d == (d -= 1));
}

bool Tests::TEST_INC_E()
{
    uint8_t e = this->cpu->registers->e;

    this->cpu->INC_E();

    return (this->cpu->registers->e == (e += 1));
}

bool Tests::TEST_DEC_E()
{
    uint8_t e = this->cpu->registers->e;

    this->cpu->DEC_E();

    return (this->cpu->registers->e == (e -= 1));
}

bool Tests::TEST_INC_H()
{
    uint8_t h = this->cpu->registers->h;

    this->cpu->INC_H();

    return (this->cpu->registers->h == (h += 1));
}

bool Tests::TEST_DEC_H()
{
    uint8_t h = this->cpu->registers->h;

    this->cpu->DEC_H();

    return (this->cpu->registers->h == (h -= 1));
}

bool Tests::TEST_INC_L()
{
    uint8_t l = this->cpu->registers->l;

    this->cpu->INC_L();

    return (this->cpu->registers->l == (l += 1));
}

bool Tests::TEST_DEC_L()
{
    uint8_t l = this->cpu->registers->l;

    this->cpu->DEC_L();

    return (this->cpu->registers->l == (l -= 1));
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
