#include "Rom.hpp"

Rom::Rom(Logger *logger, std::string path)
{
    this->logger = logger;

    this->path = path;
    this->status = false;
    this->title = new char[17];
    this->data = nullptr;
    this->size = 0;

    this->status = Rom::Load();
}

Rom::~Rom()
{
    delete[] this->title;
    delete[] this->data;
}

void Rom::LoadSize(std::ifstream &file)
{
    file.seekg(0, std::ios::end);
    this->size = file.tellg();
    file.seekg(0, std::ios::beg);
}

void Rom::LoadData(std::ifstream &file)
{
    this->data = new char[this->size];
    file.read(this->data, this->size);
}

void Rom::LoadTitle(std::ifstream &file)
{
    file.seekg(0xA0, std::ios::beg);
    file.read(this->title, 16);
    this->title[16] = '\0';
}

bool Rom::Load()
{
    std::ifstream file(this->path, std::ios::binary);

    if (file) {
        Rom::LoadSize(file);
        Rom::LoadData(file);
        Rom::LoadTitle(file);

        file.close();

        return (true);
    }

    return (false);
}