#include "iDataSource.h"

#ifndef simpleDataSource_H
#define simpleDataSource_H

namespace myhappyplants
{
    class SimpleDataSource : public iDataSource
    {
    private:
        List<float> &_Value;

    public:        
        SimpleDataSource(List<float> &value):_Value(value) {};
         
        List<float> *GetData();
    };
} // namespace myhappyplants

#endif