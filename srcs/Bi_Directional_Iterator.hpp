#ifndef BI_DIRECTIONAL_ITERATOR_HPP
# define BI_DIRECTIONAL_ITERATOR_HPP
//# include "map_node.hpp"
# include <memory>

namespace ft
{
	template <typename T, typename Pointer, typename Reference, class C, class U>
	class BiDirectionalIterator
	{
	public:
		typedef BiDirectionalIterator<T, Pointer, Reference, C, U> this_type;
		typedef BiDirectionalIterator<T, T*, T&, C, U> iterator;
		typedef BiDirectionalIterator<T, const T*, const T&, C, U> const_iterator;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef node<C, U>* node_pointer;
		typedef std::bidirectional_iterator_tag iterator_catagory;

		node_pointer ptr;

		BiDirectionalIterator() : ptr(NULL)
		{

		}

		BiDirectionalIterator(const node_pointer element) : ptr(element)
		{

		}

		BiDirectionalIterator(const iterator& x) : ptr(const_cast<node_pointer>(x.ptr))
		{

		}

		this_type& operator=(const const_iterator& x)
		{
			this->ptr = x.ptr;
			return (*this);
		}

		virtual ~BiDirectionalIterator()
		{

		}

		BiDirectionalIterator operator++(int)
		{
			BiDirectionalIterator out(*this);
			this->ptr = ptr->get_next();
			return (out);
		}

		BiDirectionalIterator& operator++()
		{
			this->ptr = ptr->get_next();
			return (*this);
		}

		BiDirectionalIterator operator--(int)
		{
			BiDirectionalIterator out(*this);
			this->ptr = ptr->get_previous();
			return (out);
		}

		BiDirectionalIterator& operator--()
		{
			this->ptr = ptr->get_previous();
			return (*this);
		}

		reference operator*()
		{
			return (this->ptr->value);
		}

		pointer operator->()
		{
			return (&(this->ptr->value));
		}

		template <typename T2, typename P, typename R, class C2, class U2>
		friend inline bool operator==(const this_type& lhs, const BiDirectionalIterator<T2, P, R, C2, U2>& rhs)
		{
			return (lhs.ptr == rhs.ptr);
		}
		template <typename T2, typename P, typename R, class C2, class U2>
		friend inline bool operator!=(const this_type& lhs, const BiDirectionalIterator<T2, P, R, C2, U2>& rhs)
		{
			return (!(lhs == rhs));
		}
	};
}

#endif
