#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <stdexcept>

# include "Equal.hpp"
# include "LexicoGraphical_Compare.hpp"
# include "Random_Access_Iterator.hpp"
# include "Reverse_Random_Access_Iterator.hpp"
# include "Distance.hpp"
// https://www.cplusplus.com/reference/vector/vector/
// https://en.cppreference.com/w/cpp/container/vector

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type& const_reference;
		typedef value_type* pointer;
		typedef value_type* const_pointer;
		typedef RandomAccessIterator<T, T *, T &> iterator;
		typedef RandomAccessIterator<T, const T *, const T &> const_iterator;
		typedef ReverseRandomAccessIterator<iterator> reverse_iterator;
		typedef ReverseRandomAccessIterator<const iterator> const_revers_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

		//NOTE		default: Constructs an empty container, with no elements.
		explicit vector (const allocator_type& alloc = allocator_type()) : _arr(NULL), _size(0), _capacity(0), _allocator(alloc)
		{

		}

		//NOTE		fill: Constructs a container with count elements. Each element is a copy of value.
		explicit vector (size_type count, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()) : _size(count), _capacity(count), _allocator(alloc)
		{
			this->_arr = new value_type[count];
			for (size_type i = 0; i < count; i++)
				this->_arr[i] = value;
		}

		//NOTE		range: Constructs a container with as many elements as the
		//		range [first,last), with each element constructed from its
		//		corresponding element in that range, in the same order.
		template <class InputIterator> vector (InputIterator first, InputIterator last,	const allocator_type& alloc = allocator_type()) : _allocator(alloc)
		{
			_size = 0;
			_capacity = ft::distance(first, last);
			_arr = new value_type[_capacity];
			while(first != last)
			{
				_arr[_size] = *first;
				first++;
				_size++;

			}
			_capacity = _size;
		}

		//NOTE		copy: Constructs a container with a copy of each of the elements in x, in the same order.
		vector (const vector& other)
		{
			*this = other;
		}

		//NOTE		destructor:
		~vector()
		{
			if (_arr != NULL)
				delete [] this->_arr;
		}

		//NOTE		deepcopy: Copies all the elements from other into the container.

		// TODO this current function is completely fucked ATM!!!!!!!
		vector& operator= (const vector& other)
		{
			if (this == &other)
				return (*this);

			delete [] this->_arr;
			this->_capacity = other._capacity;
			this->_allocator = other._allocator;
			this->_size = 0;
			this->_arr = new value_type[this->_capacity];
			//this->assign() // add assign function

			return (*this);
		}
		//TODO bad !!!!!!!!!!!

		//NOTE		range: the new contents are elements constructed from each of the elements
		// in the range between first and last, in the same order.
		template <class InputIterator> void assign (InputIterator first, InputIterator last)
		{
			size_type count = ft::distance(first, last) + _size;
			if (count > _capacity)
			{
				reserve(count);
				//delete [] _arr;

			}
			while (first != last)
				push_back(*first);
			//TODO pushback
		}
		//NOTE		fill: the new contents are count elements, each initialized to a copy of value.
		void assign (size_type count, const value_type& value)
		{
			if (_size + count >= _capacity)
			{
				reserve(count);
//				delete [] _arr;
//				_capacity *= 2;
//				_arr = new value_type[_capacity];
			}
			for (size_type i = 0; i < count; i++)
				push_back(value);
			//TODO pushback
		}

		//NOTE		reserve: Request a change in capacity
		void reserve (size_type newcapacity)
		{
			if (newcapacity <= _capacity)
				return;
			value_type *temp = new value_type [newcapacity];
			_capacity = newcapacity;
			for (size_type i = 0; i < _size; i++) //TODO check if this is okay or it should be <=
				temp[i] = _arr[i];
			delete [] _arr;
			_arr = temp;
		}

//	!!	If n is smaller than the current container size, the content
//	!!	is reduced to its first n elements, removing those beyond (and destroying them).
//
//		If n is greater than the current container size, the content is expanded by inserting
//		at the end as many elements as needed to reach a size of n. If val is specified,
//		the new elements are initialized as copies of val, otherwise, they are value-initialized.
//
//	!!	If n is also greater than the current container capacity, an automatic reallocation
//	!!	of the allocated storage space takes place.
//
//		Notice that this function changes the actual content of the container by inserting
//		or erasing elements from it.


		//NOTE		resize: Resizes the container so that it contains count elements.
		void resize (size_type count, value_type value = value_type())
		{
			if (count < _size)//TODO is the rest deleted?
			{
				_size = count;
				return;
			}
			if (count > _capacity)
				reserve(count);
			if (count > _size)
				push_back(value);//add value to the back of _arr either value or NULL
		}


//		Adds a new element at the end of the vector, after its current last element.
//		The content of val is copied (or moved) to the new element.
//
//		This effectively increases the container size by one, which causes an automatic
//		reallocation of the allocated storage space if -and only if- the new vector size
//		surpasses the current vector capacity.

		//NOTE		push_back: Add element at the end
		void push_back (const value_type& value)
		{
//			if (_size == _capacity)//TODO gvd jordi je hebt gelijk
//			{
//				if (_capacity == 0)
//					reserve(1);
//				else
//					reserve(_capacity * 2);
//			}
			reserve(_size + 1); //TODO check if this is not realy bad practice.
			//TODO if _capacity is always checked before push_back, this function will be safe??????????????
			_arr[_size] = value;
			_size++;
		}

		//NOTE		pop_back: This destroys the removed element.
		void pop_back()
		{
			if (_size > 0)
				_size--;
		}

		//NOTE		Return iterator to beginning
		iterator begin()
		{
			return (iterator (_arr));
//			while (_arr[_size] != 0)
//				_size--;

		}
		const_iterator begin() const
		{
			return (iterator(_arr));
		}

		//NOTE		Return iterator to end
		iterator end()
		{
			return (iterator(&_arr[_size]));
		}
		const_iterator end() const
		{
			return (iterator(&_arr[_size]));
		}

	private:
		pointer _arr;
		size_type _size;
		size_type _capacity;
		allocator_type _allocator;

    };
}

#endif
