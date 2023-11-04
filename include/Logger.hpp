#pragma once

    #include <string>
    #include <iostream>

    class Logger
    {
        public:
            Logger();
            ~Logger();

            void Log(std::string, std::string);
    };
