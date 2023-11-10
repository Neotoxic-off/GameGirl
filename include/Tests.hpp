#pragma once

    #include "Logger.hpp"

    class Tests
    {
        public:
            Tests();
            ~Tests();

            void Run();
        
        private:
            Logger logger;
    };
