//
// Created by user on 31.07.2019.
//

#include <assert.h>

#ifndef MYARRAY_MYARRAY_H
#define MYARRAY_MYARRAY_H


template <typename T, size_t N>
struct MyArray {
    typedef T*          iterator;
    typedef const T*    const_iterator;

    T array[N];

    constexpr inline size_t size(){return N;}

    constexpr inline size_t max_size() {return N;}

    constexpr inline bool empty() {return size() == 0;}

    inline T* data() {return array;}

    inline iterator begin() {return iterator(array);}

    inline iterator end() {return iterator(array + N);}

    constexpr inline const_iterator cbegin() const {return const_iterator(array);}

    constexpr inline const_iterator cend() const {return const_iterator(array + N);}

    T& front() {return *begin(); }

    T& back() {return N ? *(end() - 1) : *end(); }

    constexpr const T& front() const {return *begin(); }

    constexpr const T& back() const {return N ? *(end() - 1) : *end(); }

    inline void swap(MyArray<T, N>& other) { std::swap(array, other.array); }

    void fill(const T& elem)
    {
        for(int i = 0; i < N; ++i)
            array[i] = elem;
    }

    inline T& operator[](size_t ind) {return array[ind];}

    inline const T& operator[](size_t ind) const {return array[ind];}

    T& at(size_t ind)
    {
        assert(ind >= 0 && ind < size());
        return operator[](ind);
    }

    const T& at(size_t ind) const
    {
        assert(ind >= 0 && ind < size());
        return operator[](ind);
    }
};

template <typename T, size_t N>
inline bool operator==(const MyArray<T, N>& array1, const MyArray<T, N>& array2) {
    return std::equal(array1.cbegin(), array1.cend(), array2.cbegin());
}

template <typename T, size_t N>
inline bool operator!=(const MyArray<T, N>& array1, const MyArray<T, N>& array2) {
    return !(array1 == array2);
}

template <typename T, size_t N>
inline bool operator<=(const MyArray<T, N>& array1, const MyArray<T, N>& array2) {
    return !(array1 > array2);
}

template <typename T, size_t N>
inline bool operator>=(const MyArray<T, N>& array1, const MyArray<T, N>& array2) {
    return !(array1 < array2);
}

template <typename T, size_t N>
inline bool operator<(const MyArray<T, N>& array1, const MyArray<T, N>& array2) {
    return std::lexicographical_compare(array1.cbegin(), array1.cend(),
                                        array2.cbegin(), array2.cend());
}

template <typename T, size_t N>
inline bool operator>(const MyArray<T, N>& array1, const MyArray<T, N>& array2) {
    return std::lexicographical_compare(array2.cbegin(), array2.cend(),
                                        array1.cbegin(), array1.cend());
}

#endif //MYARRAY_MYARRAY_H
