#include <simpleDataSource.h>

namespace myhappyplants
{
    List<float> *SimpleDataSource::GetData()
    {
        return &_Value;
    }    

} // namespace myhappyplants