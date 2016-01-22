#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLUDED_DYNAMIC_ARRAY

#include <cstddef>
#include <algorithm>

namespace nonsense {

template<typename T>
class DynamicArray {
    public:
	typedef std::size_t size_type;
	typedef T           value_type;
	typedef T*          iterator;
	typedef const T*    const_iterator;
    public:
	DynamicArray();
	~DynamicArray();
	
	T &front();
	T &back();

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	size_type size() const;
	void resize(const size_type new_size);

	// manipulators
	void push_back(const value_type &);
	void pop_back();

    private:
	const double k_GrowthFactor = 1.5;

	value_type *array_;
	size_type size_;
	size_type capacity_;

};

namespace {
std::size_t calc_new_size(std::size_t capacity, std::size_t new_size, double growth_factor) {
    if (0 == capacity)
	capacity = 1;
    if (capacity > new_size)
	return capacity;

    auto cap_d = static_cast<double>(capacity); // do all calculations with double not get
	// truncation errors.
    for(; static_cast<std::size_t>(cap_d) < new_size; cap_d *= growth_factor);

    return static_cast<std::size_t>(cap_d);
}
} // close anon namespace

template<typename T>
DynamicArray<T>::DynamicArray() : array_(0), size_(0), capacity_(0) {}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    if (0 == array_)
	return;

    size_ = 0;
    capacity_ = 0;
    delete []array_;
    array_ = 0;
}

template<typename T>
void DynamicArray<T>::resize(const size_type new_size) {
    // nothing to do if the size that's asked for is smaller than current cap
    if (new_size < capacity_)
	return;

    auto new_cap = calc_new_size(this->capacity_, new_size, k_GrowthFactor);

    if (new_cap == this->capacity_) {
	return;
    }

    // create new array and copy all elements over.
    T* new_array = new T[new_cap];
    for (size_type i = 0; i < this->size_; ++i) {
	new_array[i] = array_[i];
    }

    std::swap(new_array, array_);
    if (0 != new_array) {
	delete []new_array;
    }
}

template<typename T>
void DynamicArray<T>::push_back(const value_type &v) {
    if (size_ + 1 > capacity_)
	this->resize((size_ + 1) * k_GrowthFactor);

    array_[size_++] = v;
}

template<typename T>
void DynamicArray<T>::pop_back() {
    // TODO - shrink array when it gets smaller than a certain size.
    --size_;
}

template<typename T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::begin() const {
    return array_;
}

template<typename T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::end() const {
    return &array_[size_]; // past the end iterator
}

template<typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::begin() {
    return array_;
}

template<typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::end() {
    return &array_[size_]; // past the end iterator
}

template<typename T>
T & DynamicArray<T>::front() {
    return array_[0];
}

template<typename T>
T & DynamicArray<T>::back() {
    return array_[size_-1];
}


} // close namespace nonsense

#endif
