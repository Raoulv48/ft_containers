#ifndef REVERSE_BI_DIRECTIONAL_ITERATOR_HPP
# define REVERSE_BI_DIRECTIONAL_ITERATOR_HPP

namespace ft
{
	template <class Iterator>
	class ReverseBiDirectionalIterator{
	public:
		typedef Iterator								iterator_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::size_type			size_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::iterator_catagory	iterator_catagory;

		ReverseBiDirectionalIterator() : curr()
		{

		}

		ReverseBiDirectionalIterator(const iterator_type& other) : curr(other)
		{

		}

		ReverseBiDirectionalIterator(const ReverseBiDirectionalIterator& other) : curr(other.curr)
		{

		}

		template<typename Iter>
		ReverseBiDirectionalIterator(const ReverseBiDirectionalIterator<Iter>& other) : curr(other.base())
		{

		}

		~ReverseBiDirectionalIterator()
		{

		}

		ReverseBiDirectionalIterator& operator=(const ReverseBiDirectionalIterator& other)
		{
			Iterator::operator=(other);
			return (*this);
		}

		iterator_type base() const
		{
			return (this->curr);
		}

		reference operator*()
		{
			return (*curr);
		}

		pointer operator->()
		{
			return (&operator*());
		}

		ReverseBiDirectionalIterator& operator++()
		{
			--curr;
			return (*this);
		}

		ReverseBiDirectionalIterator operator++(int)
		{
			ReverseBiDirectionalIterator out(*this);
			--curr;
			return (out);
		}

		ReverseBiDirectionalIterator& operator--()
		{
			++curr;
			return (*this);
		}

		ReverseBiDirectionalIterator operator--(int)
		{
			ReverseBiDirectionalIterator out(*this);
			++curr;
			return (out);
		}

	protected:
		Iterator curr;
	};

	template <typename Iterator>
	inline bool operator==(const ReverseBiDirectionalIterator<Iterator>& lhs, const ReverseBiDirectionalIterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename Iterator>
	inline bool operator<(const ReverseBiDirectionalIterator<Iterator>& lhs, const ReverseBiDirectionalIterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename Iterator>
	inline bool operator!=(const ReverseBiDirectionalIterator<Iterator>& lhs, const ReverseBiDirectionalIterator<Iterator>& rhs)
	{
		return !(lhs.base() == rhs.base());
	}

	template <typename Iterator>
	inline bool operator>(const ReverseBiDirectionalIterator<Iterator>& lhs, const ReverseBiDirectionalIterator<Iterator>& rhs)
	{
		return (rhs.base() < lhs.base());
	}

	template <typename Iterator>
	inline bool operator<=(const ReverseBiDirectionalIterator<Iterator>& lhs, const ReverseBiDirectionalIterator<Iterator>& rhs)
	{
		return !(rhs.base() < lhs.base());
	}

	template <typename Iterator>
	inline bool operator>=(const ReverseBiDirectionalIterator<Iterator>& lhs, const ReverseBiDirectionalIterator<Iterator>& rhs)
	{
		return !(lhs.base() < rhs.base());
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator==(const ReverseBiDirectionalIterator<IteratorL>& lhs, const ReverseBiDirectionalIterator<IteratorR>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator<(const ReverseBiDirectionalIterator<IteratorL>& lhs, const ReverseBiDirectionalIterator<IteratorR>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator!=(const ReverseBiDirectionalIterator<IteratorL>& lhs, const ReverseBiDirectionalIterator<IteratorR>& rhs)
	{
		return !(lhs.base() == rhs.base());
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator>(const ReverseBiDirectionalIterator<IteratorL>& lhs, const ReverseBiDirectionalIterator<IteratorR>& rhs)
	{
		return (rhs.base() < lhs.base());
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator<=(const ReverseBiDirectionalIterator<IteratorL>& lhs, const ReverseBiDirectionalIterator<IteratorR>& rhs)
	{
		return !(rhs.base() < lhs.base());
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator>=(const ReverseBiDirectionalIterator<IteratorL>& lhs, const ReverseBiDirectionalIterator<IteratorR>& rhs)
	{
		return !(lhs.base() < rhs.base());
	}

	template<typename Iterator>
	inline ReverseBiDirectionalIterator<Iterator> make_reverse_iterator(Iterator i)
	{
		return (ReverseBiDirectionalIterator<Iterator>(i));
	}
}

#endif
