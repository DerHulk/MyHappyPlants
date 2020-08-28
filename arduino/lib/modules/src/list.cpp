#include "list.h"

namespace myhappyplants
{
    template <typename T>
    int List<T>::Length()
    {
        return this->_Length;
    }

    template <typename T>
    T List<T>::Get(int index)
    {
        return _Array[index];
    }
} // namespace myhappyplants