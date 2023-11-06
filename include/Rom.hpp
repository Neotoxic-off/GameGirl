#pragma once

    #include <fstream>
    #include <iostream>
    #include <vector>

    #include "Logger.hpp"

    class Rom
    {
        public:
            char *title;
            char *data;
            std::streampos size;
            std::string path;
            bool status;
            Logger *logger;

            Rom(Logger *, std::string);
            ~Rom();

            bool Load();

        private:
            void LoadSize(std::ifstream &);
            void LoadData(std::ifstream &);
            void LoadTitle(std::ifstream &);
    };
