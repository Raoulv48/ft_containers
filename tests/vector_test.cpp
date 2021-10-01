#include <iostream>
#include <string>
#include <deque>
#include "../srcs/Vector.hpp"
#include <stdlib.h>
#include <iomanip>
// #define MAX_RAM 4294967296

int g_exit_code;
#define MAX_RAM __INT_MAX__ / 8
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define TEST(X) std::cout <<  std::setw(30) << std::left << std::setfill(' ')   <<  X << ": " << RESET
# define SUCCESS std::cout << GREEN << "PASS" << RESET << std::endl;
# define FAIL std::cout << RED << "FAIL" << RESET << std::endl;
# define FAIL_CHECK(X) if(X){ FAIL; g_exit_code = 1; return;}
# define FAIL_CHECK_MSG(X, Y) if (X){ std::cout << RED << "FAIL " << RESET << Y << std::endl; g_exit_code = 1; return;}
# define COUNT 100

static void iterator_test_forward()
{
	TEST("iterator_test_forward");
	ft::vector<int> vec;

	for(int i = 0 ; i < 10000 ; i++)
		vec.push_back(i);

	int i = 0;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		FAIL_CHECK(*it != i);
		i++;
	}
	SUCCESS;
}
//
//static void iterator_test_reverse()
//{
//	TEST("iterator_test_reverse");
//	ft::vector<int> vec;
//
//	for(int i = 0 ; i < 10000 ; i++)
//		vec.push_back(i);
//
//	int i = 10000 - 1;
//	for (ft::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
//	{
//		FAIL_CHECK(*it != i);
//		i--;
//	}
//	SUCCESS;
//}
//
//
//static void InputIterator_constructor_test()
//{
//	TEST("InputIterator_constructor_test");
//	ft::vector<int> vec;
//
//	for(int i = 0 ; i < 10000 ; i++)
//		vec.push_back(i);
//
//	ft::vector<int> test2(vec.begin(), vec.end());
//	ft::vector<int>::iterator it = vec.begin();
//	ft::vector<int>::iterator it2 = test2.begin();
//
//
//	for (; it != vec.end(); it++)
//	{
//		FAIL_CHECK(*it != *it2);
//		it2++;
//	}
//	FAIL_CHECK(it == vec.end() && it2 != test2.end());
//
//	SUCCESS;
//}
//
//
//static void copy_constructor_test()
//{
//	TEST("copy_constructor_test");
//	ft::vector<int> vec;
//
//	for(int i = 0 ; i < 10000 ; i++)
//		vec.push_back(i);
//
//	ft::vector<int> test2(vec);
//	ft::vector<int>::iterator it = vec.begin();
//	ft::vector<int>::iterator it2 = test2.begin();
//
//
//	for (; it != vec.end(); it++)
//	{
//		FAIL_CHECK(*it != *it2);
//		it2++;
//	}
//	FAIL_CHECK(it == vec.end() && it2 != test2.end());
//
//	SUCCESS;
//}
//
//
//static void assign_test_1()
//{
//	TEST("assign_test_1");
//	ft::vector<int> vec;
//	std::size_t count = rand() % 500;
//
//	vec.assign(count, 42);
//
//	FAIL_CHECK_MSG(vec.size() != count, "Incorrect size " << vec.size() << " " << count);
//
//	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
//		FAIL_CHECK(*it != 42);
//
//	SUCCESS
//}
//
//static void assign_test_2()
//{
//	TEST("assign_test_2");
//	ft::vector<int> vec2;
//	for(int i = 0 ; i < 10000 ; i++)
//		vec2.push_back(42);
//
//	ft::vector<int> vec;
//	vec.assign(vec2.begin(), vec2.end());
//
//	FAIL_CHECK_MSG(vec2.size() != vec.size(), "Incorrect size " << vec.size() << " " << vec2.size());
//
//	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
//		FAIL_CHECK(*it != 42);
//
//	SUCCESS
//}
//
//static void at_test()
//{
//	TEST("at_test");
//	ft::vector<int> vec;
//	for(int i = 0 ; i < 10000 ; i++)
//		vec.push_back(42);
//
//	bool caught1 = false, caught2 = false;
//
//	try
//	{
//		vec.at(42000);
//		FAIL_CHECK_MSG(1 == 1, "Failed to throw exception!");
//	}
//	catch(const std::exception& e)
//	{
//		caught1 = true;
//	}
//
//	try
//	{
//		vec.at(-1);
//		FAIL_CHECK_MSG(1 == 1, "Failed to throw exception!");
//	}
//	catch(const std::exception& e)
//	{
//		caught2 = true;
//	}
//
//	FAIL_CHECK_MSG(vec.at(1) != 42, "Incorrect value!");
//	FAIL_CHECK_MSG(vec.at(9999) != 42, "Incorrect value!");
//	FAIL_CHECK_MSG(vec.at(5000) != 42, "Incorrect value!");
//	FAIL_CHECK_MSG(vec.at(42) != 42, "Incorrect value!");
//
//	if (caught1 && caught2)
//	{
//		SUCCESS;
//	}
//	else
//	{
//		FAIL_CHECK(caught1 == false && caught2 == false);
//	}
//}
//
//static void array_operator_test()
//{
//	TEST("array_operator_test");
//
//	ft::vector<int> vec;
//	for(int i = 0 ; i < 10000 ; i++)
//		vec.push_back(42);
//
//	for (int i = 0 ; i < 10000; i++)
//	{
//		if (vec[i] == 42)
//			;
//		else
//		FAIL_CHECK_MSG(1 == 1, "Incorrect value!");
//	}
//	SUCCESS;
//}
//
//
//static void front_test()
//{
//	TEST("front_test");
//
//	ft::vector<int> vec;
//	for(int i = 0 ; i < 10000 ; i++)
//		vec.push_back(i);
//
//	int i = vec.front();
//
//	FAIL_CHECK(i != 0);
//	SUCCESS;
//}
//
//static void back_test()
//{
//	TEST("back_test");
//
//	ft::vector<int> vec;
//	for(int i = 0 ; i < 10000 ; i++)
//		vec.push_back(i);
//
//	int i = vec.back();
//
//	FAIL_CHECK(i != 10000 - 1);
//	SUCCESS;
//}
//
//static void empty_test()
//{
//	TEST("empty_test");
//	ft::vector<int> vec;
//
//	FAIL_CHECK(vec.empty() != true);
//
//	vec.push_back(1);
//	FAIL_CHECK(vec.empty() != false);
//
//	SUCCESS;
//}
//
//static void size_test()
//{
//	TEST("size_test");
//	ft::vector<int> vec;
//
//	FAIL_CHECK(vec.size() != 0);
//
//	for (std::size_t i = 0 ; i < 10000; i++)
//	{
//		vec.push_back(i);
//		FAIL_CHECK(vec.size() != i + 1);
//	}
//	SUCCESS;
//}
//
//static void reserve_test()
//{
//	TEST("reserve_test");
//	ft::vector<int> vec;
//
//	FAIL_CHECK_MSG(vec.capacity() != 0, "test1");
//	vec.reserve(1);
//	FAIL_CHECK_MSG(vec.capacity() != 1, "test2");
//	vec.reserve(50);
//	FAIL_CHECK_MSG(vec.capacity() != 50, "test3");
//	vec.reserve(3);
//	FAIL_CHECK_MSG(vec.capacity() != 50, "test4");
//	vec.reserve(1);
//	FAIL_CHECK_MSG(vec.capacity() != 50, "test5");
//	vec.reserve(0);
//	FAIL_CHECK_MSG(vec.capacity() != 50, "test6");
//	vec.reserve(2142);
//	FAIL_CHECK_MSG(vec.capacity() != 2142, "test7");
//
//	SUCCESS;
//}
//
//
//static void clear_test()
//{
//	TEST("clear test");
//
//	ft::vector<std::string> vec;
//
//	vec.push_back("Hello");
//	vec.push_back("World");
//	vec.push_back("This");
//	vec.push_back("is");
//	vec.push_back("a");
//	vec.push_back("std::string");
//	vec.push_back("vector");
//
//	FAIL_CHECK(vec.size() != 7);
//
//	vec.clear();
//	FAIL_CHECK(vec.size() != 0);
//
//	SUCCESS;
//}
//
//static void insert_test_1()
//{
//	TEST("insert_test_1");
//
//	ft::vector<int> vec;
//
//	for (int i = 0 ; i < 10; i ++)
//	{
//		if (i == 4)
//			;
//		else
//			vec.push_back(i);
//	}
//
//	FAIL_CHECK(vec[4] != 5);
//	ft::vector<int>::iterator it = vec.begin();
//	it++;
//	it++;
//	it++;
//	it++;
//	it = vec.insert(it, 4);
//	FAIL_CHECK(*it != 4);
//	int i = 0;
//	for (ft::vector<int>::iterator it2 = vec.begin(); it2 != vec.end(); it2++)
//	{
//		FAIL_CHECK(*it2 != i);
//		i++;
//	}
//	FAIL_CHECK(vec[4] != 4);
//	SUCCESS;
//}
//
//static void insert_test_2()
//{
//	TEST("insert_test_2");
//
//	ft::vector<int> vec;
//	vec.reserve(7);
//	vec.push_back(0);
//	vec.push_back(1);
//	vec.push_back(3);
//
//	ft::vector<int>::iterator it = vec.begin();
//
//	it++;
//	it++;
//
//	vec.insert(it, (std::size_t)5, 2);
//
//	FAIL_CHECK(vec[0] != 0);
//	FAIL_CHECK(vec[1] != 1);
//	FAIL_CHECK(vec[2] != 2);
//	FAIL_CHECK(vec[3] != 2);
//	FAIL_CHECK(vec[4] != 2);
//	FAIL_CHECK(vec[5] != 2);
//	FAIL_CHECK(vec[6] != 2);
//	FAIL_CHECK(vec[7] != 3);
//
//	SUCCESS;
//}
//
//
//static void insert_test_3()
//{
//	TEST("insert_test_3");
//
//	ft::vector<int> vec;
//	vec.reserve(7);
//	vec.push_back(0);
//	vec.push_back(1);
//	vec.push_back(3);
//
//	ft::vector<int>::iterator it = vec.begin();
//
//	it++;
//	it++;
//
//	ft::vector<int> vec2;
//	vec2.insert(vec2.begin(), (std::size_t)5, 2);
//
//	vec.insert(it, vec2.begin(), vec2.end());
//
//	FAIL_CHECK(vec[0] != 0);
//	FAIL_CHECK(vec[1] != 1);
//	FAIL_CHECK(vec[2] != 2);
//	FAIL_CHECK(vec[3] != 2);
//	FAIL_CHECK(vec[4] != 2);
//	FAIL_CHECK(vec[5] != 2);
//	FAIL_CHECK(vec[6] != 2);
//	FAIL_CHECK(vec[7] != 3);
//
//	SUCCESS;
//}
//
//static void erase_test_1()
//{
//	TEST("erase_test_1");
//
//	ft::vector<int> vec;
//
//	vec.reserve(10);
//	for(int i = 0 ; i < 10; i++)
//		vec.push_back(i);
//
//	ft::vector<int>::iterator it = vec.begin(), it2;
//	it = vec.erase(it);
//	it2 = vec.begin();
//
//	FAIL_CHECK_MSG(*it != 1, "test1");
//	FAIL_CHECK_MSG(*it2 != 1, "test2");
//
//	it = vec.erase(vec.end() - 1);
//	FAIL_CHECK(it != vec.end());
//
//	vec.clear();
//	for(int i = 0 ; i < 10 ; i++)
//		vec.push_back(i);
//
//	it = vec.begin();
//	it++; it++; it++; it++; it++;
//	it = vec.erase(it);
//	FAIL_CHECK_MSG(*it != 6, "test3");
//	int i = 0;
//	for (ft::vector<int>::iterator it2 = vec.begin(); it2 != vec.end(); it2++)
//	{
//		if (i == 5)
//			i++;
//		FAIL_CHECK_MSG(*it2 != i, "test4");
//		i++;
//	}
//
//	SUCCESS;
//}
//
//static void erase_test_2()
//{
//	TEST("erase_test_2");
//
//	ft::vector<int> vec;
//
//	for(int i = 0 ; i < 10 ; i++)
//		vec.push_back(i);
//
//	ft::vector<int>::iterator it = vec.begin();
//	it++; it++; it++; it++; it++;
//	it = vec.erase(it, vec.end());
//	FAIL_CHECK_MSG(it != vec.end(), "test1");
//	FAIL_CHECK_MSG(vec.size() != 5, "test2 " << vec.size());
//	int i = 0;
//	for (ft::vector<int>::iterator it2 = vec.begin(); it2 != vec.end(); it2++)
//	{
//		FAIL_CHECK(*it2 != i);
//		i++;
//	}
//
//
//	vec.clear();
//	for(int i = 0 ; i < 10 ; i++)
//		vec.push_back(i);
//
//	it = vec.begin();
//	it++;
//
//	ft::vector<int>::iterator it2 = vec.end();
//
//	it2--;
//	it2--;
//	vec.erase(it, it2);
//	FAIL_CHECK(vec.size() != 3);
//	FAIL_CHECK(vec[0] != 0);
//	FAIL_CHECK(vec[1] != 8);
//
//
//	SUCCESS;
//}
//
//static void erase_test_3()
//{
//	TEST("erase_test_3");
//
//	ft::vector<int> vec;
//	ft::vector<int>::iterator it;
//	for(int i = 0 ; i < 10 ; i++)
//		vec.push_back(i);
//
//	it = vec.begin();
//	it++;
//
//	ft::vector<int>::iterator it2 = vec.end();
//	vec.erase(it, it2);
//	FAIL_CHECK(vec.size() != 1);
//
//	SUCCESS;
//}
//
//static void pop_back_test()
//{
//	TEST("pop_back_test");
//
//	ft::vector<double> vec;
//	ft::vector<double>::iterator it;
//
//	vec.reserve(5);
//	vec.push_back(11.2);
//	vec.push_back(22.4);
//	vec.push_back(44.8);
//	vec.push_back(89.6);
//	vec.push_back(179.2);
//
//	FAIL_CHECK(vec.size() != 5);
//
//	vec.pop_back();
//
//	FAIL_CHECK(vec.size() != 4);
//	FAIL_CHECK(*(vec.end() - 1) != 89.6);
//
//	vec.pop_back();
//
//	FAIL_CHECK(vec.size() != 3);
//	FAIL_CHECK(*(vec.end() - 1) != 44.8);
//
//	SUCCESS;
//}
//
//
//static void resize_test()
//{
//	TEST("resize_test");
//
//	ft::vector<int> vec;
//
//	for (int i = 0; i < 5; i++)
//		vec.push_back(i);
//
//	FAIL_CHECK(vec.size() != 5);
//
//	vec.resize(3);
//
//	FAIL_CHECK(vec.size() != 3);
//	vec.resize(10, 42);
//
//	FAIL_CHECK(vec[0] != 0);
//	FAIL_CHECK(vec[1] != 1);
//	FAIL_CHECK(vec[2] != 2);
//
//	for (int i = 3; i < 10 ; i++)
//		FAIL_CHECK(vec[i] != 42);
//
//	FAIL_CHECK(vec.size() != 10);
//#ifdef __linux__
//	FAIL_CHECK(vec.capacity() != 10);
//#elif __APPLE__
//	FAIL_CHECK(vec.capacity() != 16);
//#endif
//	SUCCESS;
//}
//
//static void swap_test_1()
//{
//	TEST("swap_test_1");
//
//	ft::vector<int> vec1;
//	ft::vector<int> vec2;
//	ft::vector<double> vec3;
//	ft::vector<double> vec4;
//
//	for (int i = 0; i < 10; i++)
//		vec1.push_back(i);
//
//	for (int i = 10; i < 20; i++)
//		vec2.push_back(i);
//
//	vec3.push_back(21.42);
//	vec3.push_back(42.21);
//
//	vec4.push_back(10.5);
//	vec4.push_back(20.6);
//
//	vec1.swap(vec2);
//
//	for (int i = 0; i < 10; i++)
//		FAIL_CHECK_MSG(vec2[i] != i, "Expected: " << i << " Actual: " << vec2[i]);
//
//	for (int i = 10; i < 20; i++)
//		FAIL_CHECK_MSG(vec1[i - 10] != i, "Expected: " << i << " Actual: " << vec1[i - 10]);
//
//	vec3.swap(vec4);
//
//	FAIL_CHECK_MSG(vec3[0] != 10.5, "Expected: " <<  10.5 << " Actual: " << vec3[0]);
//	FAIL_CHECK_MSG(vec3[1] != 20.6, "Expected: " <<  20.6 << " Actual: " << vec3[1]);
//
//	FAIL_CHECK_MSG(vec4[0] != 21.42, "Expected: " << 21.42 << " Actual: " << vec4[0]);
//	FAIL_CHECK_MSG(vec4[1] != 42.21, "Expected: " << 42.21 << " Actual: " << vec4[1]);
//
//	SUCCESS;
//}
//
//static void swap_test_2()
//{
//	TEST("swap_test_2");
//
//	ft::vector<int> vec1;
//	ft::vector<int> vec2;
//	ft::vector<double> vec3;
//	ft::vector<double> vec4;
//
//	for (int i = 0; i < 10; i++)
//		vec1.push_back(i);
//
//	for (int i = 10; i < 20; i++)
//		vec2.push_back(i);
//
//	vec3.push_back(21.42);
//	vec3.push_back(42.21);
//
//	vec4.push_back(10.5);
//	vec4.push_back(20.6);
//
//	ft::swap(vec1, vec2);
//
//	for (int i = 0; i < 10; i++)
//		FAIL_CHECK_MSG(vec2[i] != i, "Expected: " << i << " Actual: " << vec2[i]);
//
//	for (int i = 10; i < 20; i++)
//		FAIL_CHECK_MSG(vec1[i - 10] != i, "Expected: " << i << " Actual: " << vec1[i - 10]);
//
//	ft::swap(vec3, vec4);
//
//	FAIL_CHECK_MSG(vec3[0] != 10.5, "Expected: " <<  10.5 << " Actual: " << vec3[0]);
//	FAIL_CHECK_MSG(vec3[1] != 20.6, "Expected: " <<  20.6 << " Actual: " << vec3[1]);
//
//	FAIL_CHECK_MSG(vec4[0] != 21.42, "Expected: " << 21.42 << " Actual: " << vec4[0]);
//	FAIL_CHECK_MSG(vec4[1] != 42.21, "Expected: " << 42.21 << " Actual: " << vec4[1]);
//
//	SUCCESS;
//}
//
//static void equal_test()
//{
//	TEST("equal_test");
//
//	ft::vector<int> vec1;
//	ft::vector<int> vec2;
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 == vec2) == false, "test1 Expected: true Actual: false");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(4);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 4; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 == vec2) == true, "test2 Expected: false Actual: true");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 1; i < 6; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 == vec2) == true, "test3 Expected: false Actual: true");
//
//	SUCCESS;
//}
//
//static void not_equal_test()
//{
//	TEST("not_equal_test");
//	ft::vector<int> vec1;
//	ft::vector<int> vec2;
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 != vec2) == true, "test1 Expected: false Actual: true");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(4);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 4; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 != vec2) == false, "test2 Expected: true Actual: false");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 1; i < 6; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 != vec2) == false, "test3 Expected: true Actual: false");
//
//	SUCCESS;
//}
//
//static void lesser_test()
//{
//	TEST("lesser_test");
//
//
//	ft::vector<int> vec1;
//	ft::vector<int> vec2;
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 < vec2) == true, "test1 Expected: false Actual: true");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 1; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 < vec2) == false, "test2 Expected: true Actual: false");
//	FAIL_CHECK_MSG((vec2 < vec1) == true, "test3 Exptected: false Actual: true");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(6);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 6; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 < vec2) == false, "test4 Expected: true Actual: false");
//	FAIL_CHECK_MSG((vec2 < vec1) == true, "test5 Expected: false Actual: true");
//
//	SUCCESS;
//}
//
//static void lesser_equal_test()
//{
//	TEST("lesser_equal_test");
//	ft::vector<int> vec1;
//	ft::vector<int> vec2;
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 <= vec2) == false, "test1 Expected: true Actual: false");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 1; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 <= vec2) == false, "test2 Expected: true Actual: false");
//	FAIL_CHECK_MSG((vec2 <= vec1) == true, "test3 Exptected: false Actual: true");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(6);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 6; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 <= vec2) == false, "test4 Expected: true Actual: false");
//	FAIL_CHECK_MSG((vec2 <= vec1) == true, "test5 Expected: false Actual: true");
//
//	SUCCESS;
//}
//
//static void greater_test()
//{
//	TEST("greater_test");
//	ft::vector<int> vec1;
//	ft::vector<int> vec2;
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 > vec2) == true, "test1 Expected: false Actual: true");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 1; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 > vec2) == true, "test2 Expected: false Actual: true");
//	FAIL_CHECK_MSG((vec2 > vec1) == false, "test3 Exptected: true Actual: false");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(6);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 6; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 > vec2) == true, "test4 Expected: false Actual: true");
//	FAIL_CHECK_MSG((vec2 > vec1) == false, "test5 Expected: true Actual: false");
//
//	SUCCESS;
//}
//
//static void greater_equal_test()
//{
//	TEST("greater_equal_test");
//	ft::vector<int> vec1;
//	ft::vector<int> vec2;
//
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 >= vec2) == false, "test1 Expected: true Actual: false");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(5);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 1; i < 5; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 >= vec2) == true, "test2 Expected: false Actual: true");
//	FAIL_CHECK_MSG((vec2 >= vec1) == false, "test3 Exptected: true Actual: false");
//
//	vec1.clear();
//	vec2.clear();
//
//	vec1.reserve(5);
//	vec2.reserve(6);
//
//	for (int i = 0; i < 5; i++)
//		vec1.push_back(i);
//
//	for (int i = 0; i < 6; i++)
//		vec2.push_back(i);
//
//	FAIL_CHECK_MSG((vec1 >= vec2) == true, "test4 Expected: false Actual: true");
//	FAIL_CHECK_MSG((vec2 >= vec1) == false, "test5 Expected: true Actual: false");
//
//	SUCCESS;
//}


int main(void) {

	g_exit_code = 0;
	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::vector<Buffer> vector_buffer;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
//	for (int i = 0; i < COUNT; i++)
//	{
//		const int idx = rand() % COUNT;
//		vector_buffer[idx].idx = 5;
//	}
//	ft::vector<Buffer>().swap(vector_buffer);
//	try
//	{
//		for (int i = 0; i < COUNT; i++)
//		{
//			const int idx = rand() % COUNT;
//			vector_buffer.at(idx);
//			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
//		}
//	}
//	catch(const std::exception& e)
//	{
//		//NORMAL ! :P
//	}

	iterator_test_forward();
//	iterator_test_reverse();
//	InputIterator_constructor_test();
//	copy_constructor_test();
//	assign_test_1();
//	assign_test_2();
//	at_test();
//	array_operator_test();
//	front_test();
//	back_test();
//	empty_test();
//	size_test();
//	reserve_test();
//	clear_test();
//	insert_test_1();
//	insert_test_2();
//	insert_test_3();
//	erase_test_1();
//	erase_test_2();
//	erase_test_3();
//	pop_back_test();
//	resize_test();
//	swap_test_1();
//	swap_test_2();
//	equal_test();
//	not_equal_test();
//	lesser_test();
//	lesser_equal_test();
//	greater_test();
//	greater_equal_test();
	exit(g_exit_code);
}
