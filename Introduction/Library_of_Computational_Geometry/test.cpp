#include <iostream>

template <typename TYPE, std::size_t SIZE>
std::size_t array_length(TYPE (&array)[SIZE])
{
	TYPE a[SIZE];
	a[0] = array[0];
	std::cout << a[0] << std::endl;
	return SIZE;
}

template<typename T>
const T test(T a){
	return a;
}

int main()
{
	int array1[10];
	int array2[20];
	int array3[30];
	// int a=0;

	std::cout << array_length(array1) << std::endl;
	// std::cout << array_length(array2) << std::endl;
	// std::cout << array_length(array3) << std::endl;
	// std::cout << test<int>(a) << std::endl;
}