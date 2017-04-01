#pragma once
#include "types.h"
#include "initializer_list.h"
#include "utility.h"
#include "algorithm.h"
#include "printk.h"
#include "bitsearch.h"

template<typename _T, typename _Allocator>
class vector
{
public:
    typedef _T value_type;
    typedef _Allocator allocator_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef value_type const& const_reference;
    typedef value_type* pointer;
    typedef value_type const* const_pointer;

    template<int _Dir, bool _Is_const>
    class vector_iter;

    typedef vector_iter<1, false> iterator;
    typedef vector_iter<1, true> const_iterator;
    typedef vector_iter<-1, false> reverse_iterator;
    typedef vector_iter<-1, true> const_reverse_iterator;

    vector();

    explicit vector(_Allocator const& __alloc_);

    vector(size_type __count,
           _T const& __value,
           _Allocator const& __alloc_ = _Allocator());

    explicit vector(size_type __count,
                    _Allocator const& __alloc_ = _Allocator());

    template< typename InputIt >
    vector( InputIt __first, InputIt __last,
            _Allocator const& __alloc_ = _Allocator());

    vector(vector const& __other);

    vector(vector const& __other, _Allocator const& __alloc_);

    vector(vector&& __other );

    vector(vector&& __other, _Allocator const& __alloc_);

    vector(initializer_list<_T> __init,
            const _Allocator& __alloc_ = _Allocator());

    ~vector();

    vector& operator=(vector const& __other);

    vector& operator=(vector&& __other);

    vector& operator=(initializer_list<_T> __ilist);

    void assign(size_type __count, _T const& __value);

    template<typename _InputIt>
    void assign(_InputIt __first, _InputIt __last);

    void assign(initializer_list<_T> __ilist);

    allocator_type get_allocator() const;

    reference at(size_type __pos);

    const_reference at(size_type __pos) const;

    reference operator[](size_type __pos);

    const_reference operator[](size_type __pos) const;

    reference front();

    const_reference front() const;

    reference back();

    const_reference back() const;

    pointer data();

    const_pointer data() const;

    iterator begin();

    const_iterator begin() const;

    const_iterator cbegin() const;

    iterator end();

    const_iterator end() const;

    const_iterator cend() const;

    reverse_iterator rbegin();

    const_reverse_iterator rbegin() const;

    const_reverse_iterator crbegin() const;

    reverse_iterator rend();

    const_reverse_iterator rend() const;

    const_reverse_iterator crend() const;

    bool empty() const;

    size_type size() const;

    size_type max_size() const;

    void reserve(size_type __new_cap);

    size_type capacity() const;

    void shrink_to_fit();

    void clear();

    iterator insert(const_iterator __pos,
                    _T const& __value);

    iterator insert(const_iterator __pos,
                    _T&& __value);

    iterator insert(const_iterator __pos,
                    size_type __count,
                    _T const& __value);

    template<typename InputIt>
    iterator insert(const_iterator __pos,
                    InputIt __first, InputIt __last);

    iterator insert(const_iterator __pos,
                    initializer_list<_T> __ilist);

    template<typename... _Args >
    iterator emplace(const_iterator __pos,
                     _Args&&... __args);

    iterator erase(const_iterator __pos);

    iterator erase(const_iterator __first,
                   const_iterator __last);

    void push_back(_T const& __value);

    void push_back(_T&& __value);

    template<typename... _Args>
    void emplace_back(_Args&&... __args);

    void pop_back();

    void resize(size_type __count);

    void resize(size_type __count,
                value_type const& __value);

    void swap(vector& __other);

    // Iterator
    template<int _Dir, bool _Is_const>
    class vector_iter
    {
    private:
        friend class vector;
        vector_iter(pointer __ip);

    public:
        vector_iter();

        reference operator*();
        const_reference operator*() const;
        vector_iter operator+(size_type __n);
        vector_iter operator-(size_type __n);
        reference operator[](size_type __n);
        const_reference operator[](size_type __n) const;

    private:
        pointer __p;
    };

private:
    pointer *__m;
    size_type __capacity;
    size_type __sz;
    _Allocator __alloc;
};

//
// vector implementation

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector()
    : vector(_Allocator())
{
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector(_Allocator const& __alloc_)
    : __m(nullptr)
    , __capacity(0)
    , __sz(0)
    , __alloc(__alloc_)
{
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector(size_type __count,
       _T const& __value,
       _Allocator const& __alloc_)
    : __m(nullptr)
    , __capacity(0)
    , __sz(0)
    , __alloc(__alloc_)
{
    resize(__count, __value);
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector(
        size_type __count, _Allocator const& __alloc_)
    : __m(nullptr)
    , __capacity(0)
    , __sz(0)
    , __alloc(__alloc_)
{
    resize(__count);
}

template<typename _T, typename _Allocator>
template< typename InputIt >
vector<_T,_Allocator>::vector(InputIt __first, InputIt __last,
        _Allocator const& __alloc_)
    : __m(nullptr)
    , __capacity(0)
    , __sz(0)
    , __alloc(__alloc_)
{
    assign(__first, __last);
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector(vector const& __other)
    : __m(nullptr)
    , __capacity(0)
    , __sz(0)
    , __alloc(_Allocator())
{
    reserve(__other.size());
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector(vector const& __other,
                              _Allocator const& __alloc_)
    : __m(nullptr)
    , __capacity(0)
    , __sz(0)
    , __alloc(__alloc_)
{
    reserve(__other.size());
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector(vector&& __other )
    : __m(__other.__m)
    , __capacity(__other.__capacity)
    , __sz(__other.__sz)
    , __alloc(move(__other.__alloc))
{
    __other.__m = nullptr;
    __other.__capacity = 0;
    __other.__sz = 0;
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector(vector&& __other,
                              _Allocator const& __alloc_)
    : __m(__other.__m)
    , __capacity(__other.__capacity)
    , __sz(__other.__sz)
    , __alloc(__alloc_)
{
    __other.__m = nullptr;
    __other.__capacity = 0;
    __other.__sz = 0;
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::vector(initializer_list<_T> __init,
        const _Allocator& __alloc_)
    : __m(nullptr)
    , __sz(0)
    , __alloc(__alloc_)
{
    assign(move(__init));
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>::~vector()
{
    if (__m) {
        __alloc.deallocate(__m);
        __m = nullptr;
    }
    __sz = 0;
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>&
vector<_T,_Allocator>::operator=(vector const& other)
{
    assign(other.begin(), other.end());
    return *this;
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>&
vector<_T,_Allocator>::operator=(vector&& other)
{
    if (*this != other) {
        if (__m) {
            __alloc.deallocate(__m);
            __m = nullptr;
        }
        __sz = 0;

        __m = other.__m;
        __sz = other.__sz;
        __alloc = move(other.__alloc);
    }
    return *this;
}

template<typename _T, typename _Allocator>
vector<_T,_Allocator>&
vector<_T,_Allocator>::operator=(initializer_list<_T> __ilist)
{
    assign(move(__ilist));
    return *this;
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::assign(size_type __count, _T const& value)
{
    resize(0);
    while (__sz < __count)
        push_back(value);
}

template<typename _T, typename _Allocator>
template< typename InputIt >
void vector<_T,_Allocator>::assign(InputIt __first, InputIt __last)
{
    resize(0);
    while (__first != __last) {
        push_back(*__first);
        ++__first;
    }
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::assign(initializer_list<_T> __ilist)
{
    assign(__ilist.begin(), __ilist.end());
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::allocator_type
vector<_T,_Allocator>::get_allocator() const
{
    return __alloc;
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::reference
vector<_T,_Allocator>::at(size_type __pos)
{
    if (__pos < __sz)
        return __m[__pos];
    panic("vector access out of range");
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_reference
vector<_T,_Allocator>::at(size_type __pos) const
{
    if (__pos < __sz)
        return __m[__pos];
    panic("vector access out of range");
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::reference
vector<_T,_Allocator>::operator[](size_type __pos)
{
    return __m[__pos];
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_reference
vector<_T,_Allocator>::operator[](size_type __pos) const
{
    return __m[__pos];
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::reference
vector<_T,_Allocator>::front()
{
    return __m[0];
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_reference
vector<_T,_Allocator>::front() const
{
    return __m[0];
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::reference
vector<_T,_Allocator>::back()
{
    return __m[__sz - 1];
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_reference
vector<_T,_Allocator>::back() const
{
    return __m[__sz - 1];
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::pointer
vector<_T,_Allocator>::data()
{
    return __m;
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_pointer
vector<_T,_Allocator>::data() const
{
    return __m;
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::begin()
{
    return iterator(__m);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_iterator
vector<_T,_Allocator>::begin() const
{
    return const_iterator(__m);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_iterator
vector<_T,_Allocator>::cbegin() const
{
    return const_iterator(__m);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::end()
{
    return iterator(__m + __sz);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_iterator
vector<_T,_Allocator>::end() const
{
    return const_iterator(__m + __sz);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_iterator
vector<_T,_Allocator>::cend() const
{
    return const_iterator(__m + __sz);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::reverse_iterator
vector<_T,_Allocator>::rbegin()
{
    return reverse_iterator(__m + __sz);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_reverse_iterator
vector<_T,_Allocator>::rbegin() const
{
    return const_reverse_iterator(__m + __sz);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_reverse_iterator
vector<_T,_Allocator>::crbegin() const
{
    return const_reverse_iterator(__m + __sz);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::reverse_iterator
vector<_T,_Allocator>::rend()
{
    return reverse_iterator(__m);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_reverse_iterator
vector<_T,_Allocator>::rend() const
{
    return const_reverse_iterator(__m);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::const_reverse_iterator
vector<_T,_Allocator>::crend() const
{
    return const_reverse_iterator(__m);
}

template<typename _T, typename _Allocator>
bool vector<_T,_Allocator>::empty() const
{
    return __sz == 0;
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::size_type
vector<_T,_Allocator>::size() const
{
    return __sz;
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::size_type
vector<_T,_Allocator>::max_size() const
{
    return ~size_type(0) / sizeof(_T);
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::reserve(size_type __new_cap)
{
    if (__capacity < __new_cap) {
    }
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::size_type
vector<_T,_Allocator>::capacity() const
{
    return __capacity;
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::shrink_to_fit()
{
    if (__capacity > __sz) {
        pointer __tmp = __alloc.allocate(__sz * sizeof(value_type));
        uninitialized_copy(__m, __m + __sz, __tmp);
        __alloc.deallocate(__m);
        __m = __tmp;
        __sz = __capacity;
    }
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::clear()
{
    resize(0);
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::insert(const_iterator __pos, _T const& __value)
{
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::insert(const_iterator __pos, _T&& __value)
{
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::insert(const_iterator __pos, size_type __count, _T const& __value)
{
}

template<typename _T, typename _Allocator>
template<typename InputIt>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::insert(const_iterator __pos, InputIt __first, InputIt __last)
{
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::insert(const_iterator __pos, initializer_list<_T> __ilist)
{
}

template<typename _T, typename _Allocator>
template<typename... _Args >
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::emplace(const_iterator __pos, _Args&&... __args)
{
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::erase(const_iterator __pos)
{
}

template<typename _T, typename _Allocator>
typename vector<_T,_Allocator>::iterator
vector<_T,_Allocator>::erase(const_iterator __first, const_iterator __last)
{
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::push_back(_T const& __value)
{
    if (__sz + 1 >= __capacity)
        reserve(size_type(1) << bit_log2_n_32 (__capacity + 16) * 2
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::push_back(_T&& __value)
{
}

template<typename _T, typename _Allocator>
template<typename... _Args>
void vector<_T,_Allocator>::emplace_back(_Args&&__args )
{

}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::pop_back()
{
    __alloc.destruct(__m + --__sz);
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::resize(size_type __count)
{
    resize(__count, value_type());
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::resize(size_type __count, value_type const& __value)
{
    if (__sz > __count) {
        do {
            pop_back();
        } while (--__sz);
    } else {
        reserve(__count);
        fill_n(__m + __sz, __count - __sz, __value);
        __sz = __count;
    }
}

template<typename _T, typename _Allocator>
void vector<_T,_Allocator>::swap(vector &__other)
{
}

//
// Comparison

template< typename _R, typename _Alloc >
bool operator==(vector<_R,_Alloc> const& lhs,
                vector<_R,_Alloc> const& rhs)
{
    return equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template< typename _R, typename _Alloc >
bool operator!=(vector<_R,_Alloc> const& lhs,
                vector<_R,_Alloc> const& rhs)
{
    return !equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template< typename _R, typename _Alloc >
bool operator<(vector<_R,_Alloc> const& lhs,
               vector<_R,_Alloc> const& rhs);

template< typename _R, typename _Alloc >
bool operator<=(vector<_R,_Alloc> const& lhs,
                vector<_R,_Alloc> const& rhs);

template< typename _R, typename _Alloc >
bool operator>(vector<_R,_Alloc> const& lhs,
               vector<_R,_Alloc> const& rhs);

template< typename _R, typename _Alloc >
bool operator>=(vector<_R,_Alloc> const& lhs,
                vector<_R,_Alloc> const& rhs);

template<typename _T, typename _Alloc>
void swap(vector<_T,_Alloc>& lhs,
          vector<_T,_Alloc>& rhs);

template<typename _T, typename _Alloc>
template<int _Dir, bool _Is_const>
typename vector<_T,_Alloc>::reference
vector<_T,_Alloc>::vector_iter<_Dir, _Is_const>::operator *()
{
    return *__p;
}

template<typename _T, typename _Alloc>
template<int _Dir, bool _Is_const>
typename vector<_T,_Alloc>::const_reference
vector<_T,_Alloc>::vector_iter<_Dir, _Is_const>::operator *() const
{
    return *__p;
}

template<typename _T, typename _Alloc>
template<int _Dir, bool _Is_const>
typename vector<_T,_Alloc>::template vector_iter<_Dir, _Is_const>
vector<_T,_Alloc>::template vector_iter<_Dir, _Is_const>::operator+(size_type __n)
{
    return vector_iter(__p + __n * _Dir);
}

template<typename _T, typename _Alloc>
template<int _Dir, bool _Is_const>
typename vector<_T,_Alloc>::template vector_iter<_Dir, _Is_const>
vector<_T,_Alloc>::vector_iter<_Dir, _Is_const>::operator-(size_type __n)
{
    return vector_iter(__p - __n * _Dir);
}

template<typename _T, typename _Alloc>
template<int _Dir, bool _Is_const>
typename vector<_T,_Alloc>::reference
vector<_T,_Alloc>::vector_iter<_Dir, _Is_const>::operator[](size_type __n)
{
    return __p[__n];
}

template<typename _T, typename _Alloc>
template<int _Dir, bool _Is_const>
typename vector<_T,_Alloc>::const_reference
vector<_T,_Alloc>::vector_iter<_Dir, _Is_const>::operator[](size_type __n) const
{
    return __p[__n];
}