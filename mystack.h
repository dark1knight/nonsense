#ifndef INCLUDED_ABSTRACTSTACK
#define INCLUDED_ABSTRACTSTACK

#include <vector>
#include <experimental/optional>

namespace nonsense {

template<typename T>
class MyStack {
    public:
	typedef T value_type;
    public:
	MyStack();
	~MyStack();
	MyStack(const MyStack<T> &);
	MyStack &operator=(const MyStack<T> &);

	void push(const T &);
	template<typename ...ARGS>
	void emplace(ARGS &&...args) {
	    data_.emplace_back(args...);
	}
	std::experimental::optional<T> pop();

    private:
	std::vector<T> data_;
};

template<typename T>
MyStack<T>::MyStack() : data_{} {}

template<typename T>
MyStack<T>::~MyStack() {}


template<typename T>
void MyStack<T>::push(const T &item) {
    data_.push_back(item);
}

template<typename T>
std::experimental::optional<T> MyStack<T>::pop() {
    if (data_.empty()) {
	return experimental::optional<T>{};
    }

}
    

} // close namespace nonsense

#endif
