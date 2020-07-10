#include <Arduino.h>

class iDataSource {
    public: 
        virtual String GetData() = 0;
};