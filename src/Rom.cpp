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

    if (this->data != nullptr) {
        delete[] this->data;
    }
}

void Rom::LoadSize(std::ifstream &file)
{
    this->size = file.tellg();
    file.seekg(0, std::ios::beg);

    this->logger->Log("rom: size (mb)", std::to_string(
        this->size / (1024 * 1024)
    ));
}

void Rom::LoadData(std::ifstream &file)
{
    size_t size = static_cast<std::size_t>(this->size);

    this->data = new char[size + 1];
    file.read(this->data, size);
    this->data[this->size] = '\0';

}

void Rom::LoadTitle(std::ifstream &file)
{
    file.seekg(0xA0, std::ios::beg);
    file.read(this->title, 16);
    this->title[16] = '\0';

    this->logger->Log("rom: title", this->title);
}

bool Rom::Load()
{
    std::ifstream file(this->path, std::ios::binary | std::ios::ate);

    if (file.is_open() == true) {
        Rom::LoadSize(file);
        Rom::LoadData(file);
        Rom::LoadTitle(file);

        file.close();

        return (true);
    }

    return (false);
}