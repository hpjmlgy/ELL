// RealArray.tcc

namespace types
{
    //
    // SparseStlIterator implementation
    //
    template<typename ValueType>
    bool StlIndexValueIterator<ValueType>::IsValid() const
    {
        return (_begin != _end);
    }

    template<typename ValueType>
    void StlIndexValueIterator<ValueType>::Next()
    {
        ++_begin;
        ++_index;
        SkipZeros();
    }

    template<typename ValueType>
    IndexValue StlIndexValueIterator<ValueType>::Get() const
    {
        return IndexValue{ _index, (double)*_begin };
    }

    template<typename ValueType>
    StlIndexValueIterator<ValueType>::StlIndexValueIterator(const StlIteratorType& begin, const StlIteratorType& end) : _begin(begin), _end(end), _index(0)
    {
        SkipZeros();
    }

    template<typename ValueType>
    void StlIndexValueIterator<ValueType>::SkipZeros()
    {
        while (_begin < _end && *_begin == 0)
        {
            ++_begin;
            ++_index;
        }
    }


    //
    // GetIterator function
    //
    template <typename ValueType>
    StlIndexValueIterator<ValueType> inline GetIndexValueIterator(const std::vector<ValueType>& arr)
    {
        return StlIndexValueIterator<ValueType>(arr.cbegin(), arr.cend());
    }


}
