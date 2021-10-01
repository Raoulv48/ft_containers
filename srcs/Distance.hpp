#ifndef DISTANCE_HPP
# define DISTANCE_HPP
# include <memory>

namespace ft
{
	template <typename InputIterator> ptrdiff_t distance (InputIterator first, InputIterator last)
	{
		return last - first;
	}
}

#endif
