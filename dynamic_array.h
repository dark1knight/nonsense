#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLUDED_DYNAMIC_ARRAY

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
std::size_t calc_new_size(size_type capacity, size_type new_size, double growth_factor) {
    if (capacity > new_size)
	return capacity;

    for(; capacity < new_size; capacity *= growth_factor);
    return capacity;
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

    auto new_cap = calc_new_size(this->capacity_, this->new_size, k_GrowthFactor);

    if (new_cap == this->capacity_) {
	return;
    }

    // create new array and copy all elements over.
    new_array = new T[new_cap];
    for (size_type i = 0; i < this->size_; ++i) {
	new_array[i] = array_[i];
    }
    auto sz = this->size_;

    std::swap(new_array, array_);
    if (0 != new_array) {
	delete []new_array;
    }
}



} // close namespace nonsense

#endif
