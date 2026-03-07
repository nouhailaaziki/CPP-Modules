template <typename Type>
Array<Type>::Array() : store(NULL), _size(0)
{}

template <typename Type>
Array<Type>::Array(unsigned int n)
    : store(new Type[n]()), _size(n)
{}

template <typename Type>
Array<Type>::Array(const Array<Type>& other)
    : _size(other._size)
{
    if (_size > 0) {
        store = new Type[_size](); 
        for (unsigned int i = 0; i < _size; i++)
            store[i] = other.store[i];
    }
    else
        store = NULL;
}

template <typename Type>
Array<Type>& Array<Type>::operator=(const Array<Type>& other)
{
    if (this != &other)
    {
        delete[] store;

        _size = other._size;
        if (_size > 0)
        {
            store = new Type[_size]();
            for (unsigned int i = 0; i < _size; i++)
                store[i] = other.store[i];
        }
        else
            store = NULL;
    }
    return (*this);
}

template <typename Type>
Array<Type>::~Array()
{
    delete[] store;
}

template <typename Type>
Type& Array<Type>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return (store[index]);
}

template <typename Type>
const Type& Array<Type>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return (store[index]);
}

template <typename Type>
unsigned int Array<Type>::size() const
{
    return (_size);
}