#pragma once

    #include <fstream>
    #include <iostream>

    class Rom
    {
        public:
            char *title;
            char *data;
            std::streampos size;
            std::string path;
            bool status;

            Rom(std::string);
            ~Rom();

            bool Load();
    };