#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include <memory>
# include <cstddef>

namespace ft
{
	template<typename T, typename Pointer, typename Reference, class Category = std::random_access_iterator_tag>
	class RandomAccessIterator
	{
	public:
		typedef RandomAccessIterator<T, Pointer, Reference>	this_type;
		typedef RandomAccessIterator<T, T*, T&>	iterator;
		typedef RandomAccessIterator<T, const T*, const T&> const_iterator;
		typedef T value_type;
		typedef Category iterator_catagory;
		typedef std::size_t	size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Pointer	pointer;
		typedef Reference reference;
		template<typename T2, class A> friend class vector;
		pointer array;

		RandomAccessIterator() : array(NULL)
		{

		}

		RandomAccessIterator(const pointer element) : array(element)
		{

		}

		RandomAccessIterator(const iterator& it) : array(const_cast<pointer>(it.array))
		{

		}

		virtual ~RandomAccessIterator()
		{

		}

		this_type& operator+=(difference_type n)
		{
			this->array += n;
			return (*this);
		}

		this_type operator+(difference_type n) const
		{
			this_type out(*this);
			out.arry += n;
			return (out);
		}

		this_type& operator-=(difference_type n)
		{
			this->array -= n;
			return (*this);
		}

		difference_type operator-(RandomAccessIterator it) const
		{
			return (this->array - it.array);
		}

		this_type operator-(difference_type n) const
		{
			this_type out(*this);
			out.array += n;
			return (out);
		}

		this_type operator++(int)
		{
			this_type out(*this);
			++this->array;
			return  (out);
		}

		this_type& operator++()
		{
			this->array++;
			return (*this);
		}

		this_type operator--(int)
		{
			this_type out(*this);
			--this->array;
			return (out);
		}

		this_type& operator--()
		{
			this->array--;
			return (*this);
		}

		reference operator*()
		{
			return (*this->array);
		}

		pointer operator->()
		{
			return (*(&(this->array)));
		}

		reference operator[](difference_type n)
		{
			return (*(this->array + n));
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator<(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs)
		{
			return (lhs.array < rhs.array);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator>(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs)
		{
			return (rhs < lhs);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator>=(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs)
		{
			return !(lhs < rhs);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator<=(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs)
		{
			return !(rhs < lhs);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator==(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs)
		{
			return (lhs.array == rhs.array);
		}

		template<typename T2, typename P, typename R, class C>
		friend inline bool operator!=(const this_type& lhs, const RandomAccessIterator<T2, P, R, C>& rhs)
		{
			return !(lhs == rhs);
		}
	private:

	};

	template<typename T, typename P, typename R, typename C>
	inline RandomAccessIterator<T, P, R, C> operator+(typename RandomAccessIterator<T, P, R, C>::difference_type n, const RandomAccessIterator<T, P, R, C>& x)
	{
		return (x + n);
	}
}


#endif
