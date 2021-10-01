#include <iostream>
#include <iomanip>
#include <stack>


int g_exit_code;

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define TEST(X) std::cout <<  std::setw(30) << std::left << std::setfill(' ')   <<  X << ": " << RESET
# define SUCCESS std::cout << GREEN << "PASS" << RESET << std::endl;
# define FAIL std::cout << RED << "FAIL" << RESET << std::endl;
# define FAIL_CHECK(X) if(X){ FAIL; g_exit_code = 1; return;}
# define FAIL_CHECK_MSG(X, Y) if (X){ std::cout << RED << "FAIL " << RESET << Y << std::endl; g_exit_code = 1; return;}



static void constructor_test()
{
	TEST("constructor_test");
	std::stack<int> sta;

	FAIL_CHECK(sta.empty() == false);

	SUCCESS;
}

static void empty_test()
{
	TEST("empty_test");
	std::stack<int> sta;

	FAIL_CHECK_MSG(sta.empty() == false, "test1 Expected: true Actual: false");

	sta.push(1);

	FAIL_CHECK_MSG(sta.empty() == true, "test2 Expected: false Actual: true");
	sta.pop();

	FAIL_CHECK_MSG(sta.empty() == false, "test3 Expected: true Actual: false");
	SUCCESS;
}

static void size_test()
{
	TEST("size_test");

	std::stack<int> sta;

	FAIL_CHECK_MSG(sta.size() != 0, "test1 Expected: 0 Actual: " << sta.size());

	sta.push(1);

	FAIL_CHECK_MSG(sta.size() != 1, "test2 Expected: 1 Actual: " << sta.size());

	sta.pop();
	FAIL_CHECK_MSG(sta.size() != 0, "test3 Expected: 0 Actual: " << sta.size());

	for(int i = 0; i < 10000; i++)
	{
		sta.push(i);
		FAIL_CHECK_MSG(sta.size() != (std::stack<int>::size_type)i + 1, "test4" << " Expected: " << i + 1 << " Actual: " << sta.size());
	}

	SUCCESS;
}

static void top_test()
{
	TEST("top_test");

	std::stack<int> sta;

	for (int i = 0; i < 5; i++)
	{
		sta.push(i);
		FAIL_CHECK_MSG(sta.top() != i, "test1 Expected: " << i << " Actual: " << sta.top());
	}

	for (int i = 5; i < 10000; i++)
	{
		sta.push(i);
		FAIL_CHECK_MSG(sta.top() != i, "test2 Expected: " << i << " Actual: " << sta.top());
	}

	sta.pop();
	FAIL_CHECK_MSG(sta.top() != 9998, "test3 Expected: 9998 Actual: " << sta.top());

	SUCCESS;
}

static void push_test()
{
	TEST("push_test");

	std::stack<int> sta;

	for (int i = 0; i < 1000000; i++)
	{
		sta.push(i);
		FAIL_CHECK_MSG(sta.top() != i, "test1 Expected: " << i << " Actual: " << sta.top());
	}

	SUCCESS;
}

static void pop_test()
{
	TEST("pop_test");

	std::stack<int> sta;

	for (int i = 0; i < 5; i++)
	{
		sta.push(i);
		FAIL_CHECK_MSG(sta.top() != i, "test1 Expected: " << i << " Actual: " << sta.top());
	}

	for (int i = 4; i > 0; i--)
	{
		sta.pop();
		FAIL_CHECK_MSG(sta.top() != i - 1, "test2 Expected: " << i << " Actual: " << sta.top());
	}

	SUCCESS;
}

static void equal_test()
{
	TEST("equal_test");

	std::stack<int> sta1;
	std::stack<int> sta2;

	FAIL_CHECK_MSG((sta1 == sta2) == false, "test1 Expected: true Actual: false");

	for(int i = 0 ; i < 4 ; i++)
	{
		sta1.push(i);
		sta2.push(i);
	}

	FAIL_CHECK_MSG((sta1 == sta2) == false, "test2 Expected: true Actual: false");

	sta2.push(4);

	FAIL_CHECK_MSG((sta1 == sta2) == true, "test3 Expected: false Actual: true");

	sta1.push(4);

	FAIL_CHECK_MSG((sta1 == sta2) == false, "test4 Expected: true Actual: false");

	sta1.push(5);

	FAIL_CHECK_MSG((sta1 == sta2) == true, "test5 Expected: false Actual: true");

	sta2.push(5);

	sta1.push(1);

	FAIL_CHECK_MSG((sta1 == sta2) == true, "test6 Expected: false Actual: true");


	sta2.push(1);

	sta2.push(6);

	FAIL_CHECK_MSG((sta1 == sta2) == true, "test7 Expected: false Actual: true");


	sta1.push(6);

	sta2.push(1);

	FAIL_CHECK_MSG((sta1 == sta2) == true, "test8 Expected: false Actual: true");

	SUCCESS;
}

static void not_equal_test()
{
	TEST("not_equal_test");

	std::stack<int> sta1;
	std::stack<int> sta2;

	FAIL_CHECK_MSG((sta1 != sta2) == true, "test1 Expected: false Actual: true");

	for(int i = 0 ; i < 4 ; i++)
	{
		sta1.push(i);
		sta2.push(i);
	}

	FAIL_CHECK_MSG((sta1 != sta2) == true, "test2 Expected: false Actual: true");

	sta2.push(4);

	FAIL_CHECK_MSG((sta1 != sta2) == false, "test3 Expected: true Actual: false");

	sta1.push(4);

	FAIL_CHECK_MSG((sta1 != sta2) == true, "test4 Expected: false Actual: true");

	sta1.push(5);

	FAIL_CHECK_MSG((sta1 != sta2) == false, "test5 Expected: true Actual: false");

	sta2.push(5);

	sta1.push(1);

	FAIL_CHECK_MSG((sta1 != sta2) == false, "test6 Expected: true Actual: false");


	sta2.push(1);

	sta2.push(6);

	FAIL_CHECK_MSG((sta1 != sta2) == false, "test7 Expected: true Actual: false");


	sta1.push(6);

	sta2.push(1);

	FAIL_CHECK_MSG((sta1 != sta2) == false, "test8 Expected: true Actual: false");

	SUCCESS;
}

static void lesser_test()
{
	TEST("lesser_test");

	std::stack<int> sta1;
	std::stack<int> sta2;

	FAIL_CHECK_MSG((sta1 < sta2) == true, "test1 Expected: false Actual: true");

	for(int i = 0 ; i < 4 ; i++)
	{
		sta1.push(i);
		sta2.push(i);
	}

	FAIL_CHECK_MSG((sta1 < sta2) == true, "test2 Expected: false Actual: true");

	sta2.push(4);

	FAIL_CHECK_MSG((sta1 < sta2) == false, "test3 Expected: true Actual: false");

	sta1.push(4);

	FAIL_CHECK_MSG((sta1 < sta2) == true, "test4 Expected: false Actual: true");

	sta1.push(5);

	FAIL_CHECK_MSG((sta1 < sta2) == true, "test5 Expected: false Actual: true");

	sta2.push(5);

	sta1.push(1);

	FAIL_CHECK_MSG((sta1 < sta2) == true, "test6 Expected: false Actual: true");


	sta2.push(1);

	sta2.push(6);

	FAIL_CHECK_MSG((sta1 < sta2) == false, "test7 Expected: true Actual: false");


	sta1.push(6);

	sta2.push(1);

	FAIL_CHECK_MSG((sta1 < sta2) == false, "test8 Expected: true Actual: false");

	SUCCESS;
}

static void lesser_equal_test()
{
	TEST("lesser_equal_test");

	std::stack<int> sta1;
	std::stack<int> sta2;

	FAIL_CHECK_MSG((sta1 <= sta2) == false, "test1 Expected: true Actual: false");

	for(int i = 0 ; i < 4 ; i++)
	{
		sta1.push(i);
		sta2.push(i);
	}

	FAIL_CHECK_MSG((sta1 <= sta2) == false, "test2 Expected: true Actual: false");

	sta2.push(4);

	FAIL_CHECK_MSG((sta1 <= sta2) == false, "test3 Expected: true Actual: false");

	sta1.push(4);

	FAIL_CHECK_MSG((sta1 <= sta2) == false, "test4 Expected: true Actual: false");

	sta1.push(5);

	FAIL_CHECK_MSG((sta1 <= sta2) == true, "test5 Expected: false Actual: true");

	sta2.push(5);

	sta1.push(1);

	FAIL_CHECK_MSG((sta1 <= sta2) == true, "test6 Expected: false Actual: true");


	sta2.push(1);

	sta2.push(6);

	FAIL_CHECK_MSG((sta1 <= sta2) == false, "test7 Expected: true Actual: false");


	sta1.push(6);

	sta2.push(1);

	FAIL_CHECK_MSG((sta1 <= sta2) == false, "test8 Expected: true Actual: false");

	SUCCESS;
}

static void greater_test()
{
	TEST("greater_test");

	std::stack<int> sta1;
	std::stack<int> sta2;

	FAIL_CHECK_MSG((sta1 > sta2) == true, "test1 Expected: true Actual: false");

	for(int i = 0 ; i < 4 ; i++)
	{
		sta1.push(i);
		sta2.push(i);
	}

	FAIL_CHECK_MSG((sta1 > sta2) == true, "test2 Expected: false Actual: true");

	sta2.push(4);

	FAIL_CHECK_MSG((sta1 > sta2) == true, "test3 Expected: false Actual: true");

	sta1.push(4);

	FAIL_CHECK_MSG((sta1 > sta2) == true, "test4 Expected: false Actual: true");

	sta1.push(5);

	FAIL_CHECK_MSG((sta1 > sta2) == false, "test5 Expected: true Actual: false");

	sta2.push(5);

	sta1.push(1);

	FAIL_CHECK_MSG((sta1 > sta2) == false, "test6 Expected: true Actual: false");


	sta2.push(1);

	sta2.push(6);

	FAIL_CHECK_MSG((sta1 > sta2) == true, "test7 Expected: false Actual: true");


	sta1.push(6);

	sta2.push(1);

	FAIL_CHECK_MSG((sta1 > sta2) == true, "test8 Expected: false Actual: true");

	SUCCESS;
}

static void greater_equal_test()
{
	TEST("greater_equal_test");

	std::stack<int> sta1;
	std::stack<int> sta2;

	FAIL_CHECK_MSG((sta1 >= sta2) == false, "test1 Expected: false Actual: true");

	for(int i = 0 ; i < 4 ; i++)
	{
		sta1.push(i);
		sta2.push(i);
	}

	FAIL_CHECK_MSG((sta1 >= sta2) == false, "test2 Expected: true Actual: false");

	sta2.push(4);

	FAIL_CHECK_MSG((sta1 >= sta2) == true, "test3 Expected: false Actual: true");

	sta1.push(4);

	FAIL_CHECK_MSG((sta1 >= sta2) == false, "test4 Expected: true Actual: false");

	sta1.push(5);

	FAIL_CHECK_MSG((sta1 >= sta2) == false, "test5 Expected: true Actual: false");

	sta2.push(5);

	sta1.push(1);

	FAIL_CHECK_MSG((sta1 >= sta2) == false, "test6 Expected: true Actual: false");


	sta2.push(1);

	sta2.push(6);

	FAIL_CHECK_MSG((sta1 >= sta2) == true, "test7 Expected: false Actual: true");


	sta1.push(6);

	sta2.push(1);

	FAIL_CHECK_MSG((sta1 >= sta2) == true, "test8 Expected: false Actual: true");

	SUCCESS;
}

int main(void)
{
	g_exit_code = 0;
	constructor_test();
	empty_test();
	size_test();
	top_test();
	push_test();
	pop_test();
	equal_test();
	not_equal_test();
	lesser_test();
	lesser_equal_test();
	greater_test();
	greater_equal_test();
	return(g_exit_code);
}
