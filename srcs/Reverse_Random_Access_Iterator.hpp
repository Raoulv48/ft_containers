#ifndef REVERSE_RANDOM_ACCESS_ITERATOR_HPP
# define REVERSE_RANDOM_ACCESS_ITERATOR_HPP
# include "Reverse_Bi_Directional_Iterator.hpp"

namespace ft
{
	template <class Iterator>
	class ReverseRandomAccessIterator: public ReverseBiDirectionalIterator<Iterator>
	{
	public:
		typedef ReverseBiDirectionalIterator<Iterator> base;
		typedef Iterator iterator_type;
		using typename base::pointer;
		using typename base::reference;
		using typename base::size_type;
		using typename base::difference_type;
		using typename base::iterator_catagory;

		ReverseRandomAccessIterator(): base()
		{

		}

		ReverseRandomAccessIterator(const iterator_type& other) : base(other)
		{

		}

		ReverseRandomAccessIterator(const ReverseRandomAccessIterator& other) : base(other.curr)
		{

		}

		template<typename Iter>
		ReverseRandomAccessIterator(const ReverseBiDirectionalIterator<Iter>& other) : base(other.base())
		{

		}

		~ReverseRandomAccessIterator()
		{

		}

		ReverseRandomAccessIterator& operator=(const ReverseRandomAccessIterator& other)
		{
			Iterator::operator=(other);
			return (*this);
		}

		ReverseRandomAccessIterator operator+(difference_type n) const
		{
			return (ReverseRandomAccessIterator(this->curr - n));
		}

		ReverseRandomAccessIterator& operator+=(difference_type n)
		{
			this->curr -= n;
			return (*this);
		}

		ReverseRandomAccessIterator operator-(difference_type n) const
		{
			return (ReverseRandomAccessIterator(this->curr + n));
		}

		ReverseRandomAccessIterator& operator-=(difference_type n)
		{
			this->curr += n;
			return (*this);
		}

		reference operator[](difference_type n)
		{
			return (*(*this + n));
		}
	};

	template <typename Iterator>
	inline typename ReverseRandomAccessIterator<Iterator>::difference_type operator-(const ReverseRandomAccessIterator<Iterator>& lhs, const ReverseRandomAccessIterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename IteratorL, typename IteratorR>
	inline typename ReverseRandomAccessIterator<IteratorL>::difference_type operator-(const ReverseRandomAccessIterator<IteratorL>& lhs, const ReverseRandomAccessIterator<IteratorR>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename Iterator>
	inline ReverseRandomAccessIterator<Iterator> operator+(typename ReverseRandomAccessIterator<Iterator>::difference_type n, const ReverseRandomAccessIterator<Iterator>& x)
	{
		return (ReverseRandomAccessIterator<Iterator>(x.base() - n));
	}
}

#endif
