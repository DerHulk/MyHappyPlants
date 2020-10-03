#include <analogDataSource.h>

namespace myhappyplants
{
    List<float> *AnalogDataSource::GetData()
    {
        uint16_t value = analogRead(this->_PinToUse);

        float *values = new float[1]{
            value};

        return new List<float>(values, 1);        
    }

} // namespace myhappyplants