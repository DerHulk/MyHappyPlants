
namespace myhappyplants
{
    template <typename T>
    class List
    {
    private:
        T *_Array;
        int _Length = 0;

    public:
        List(T *array, int length) : _Length(length), _Array(array){};
        int Length();
        T Get(int index);
    };

    template class List<int>;
    template class List<double>;
    template class List<float>;
} // namespace myhappyplants