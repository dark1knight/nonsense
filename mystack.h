#ifndef INCLUDED_ABSTRACTSTACK
#define INCLUDED_ABSTRACTSTACK

#include <vector>

namespace nonsense {

template<typename T>
class MyStack {
    public:
	typedef T value_type;
    public:
	MyStack();
	~MyStack();
	MyStack(const MyStack<T> &);
	MyStack &operator=(MyStack<T>);

	void push(const T &);
	template<typename ...ARGS>
	void emplace(ARGS &&...args) {
	    data_.emplace_back(args...);
	}


	// accessor routines
	T &top();

	// manipulator routines
	void pop();

    private:
	std::vector<T> data_;
};

template<typename T>
MyStack<T>::MyStack() : data_{} {}

template<typename T>
MyStack<T>::~MyStack() {}

template<typename T>
MyStack<T>::MyStack(const MyStack<T> &other) : data_(other.data_) {}

template<typename T>
MyStack<T> &MyStack<T>::operator=(MyStack<T> other) {
    std::swap(other.data_, data_);
    return *this;
}

template<typename T>
void MyStack<T>::push(const T &item) {
    data_.push_back(item);
}

template<typename T>
T &MyStack<T>::top() {
    return data_.back();
}

template<typename T>
void MyStack<T>::pop() {
    data_.pop_back();
}
    

} // close namespace nonsense

#endif
