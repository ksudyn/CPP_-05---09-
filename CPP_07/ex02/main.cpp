/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:23:07 by ksudyn            #+#    #+#             */
/*   Updated: 2025/10/17 15:11:39 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>


void testEmptyArrayAccess() {
	std::cout << "\033[32m==================== TEST EMPTY ARRAY ACCESS ====================\033[0m" << std::endl;
	try {
		Array<int> emptyArray;
		std::cout << "The size of the array is: " << emptyArray.size() << std::endl;
		std::cout << "Trying to access element at index 1..." << std::endl;
		std::cout << emptyArray[1] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void testDefaultInitialization() {
	std::cout << "\033[32m==================== TEST DEFAULT INITIALIZATION ====================\033[0m" << std::endl;
	Array<int> intArray(5);
	std::cout << "Default initialized int array: " << intArray << std::endl;

	Array<double> doubleArray(5);
	std::cout << "Default initialized double array: " << doubleArray << std::endl;

	Array<char> charArray(5);
	std::cout << "Default initialized char array: [";
	for (size_t i = 0; i < charArray.size(); ++i) {
		if (i)
			std::cout << ", ";
		std::cout << static_cast<int>(charArray[i]);
	}
	std::cout << "]" << std::endl;
}

void testDeepCopy() {
	std::cout << "\033[32m==================== TEST DEEP COPY ====================\033[0m" << std::endl;
	Array<int> originalArray(5);
	for (size_t i = 0; i < originalArray.size(); ++i) {
		originalArray[i] = i * 10;
	}

	std::cout << "Original array: " << originalArray << std::endl;

	Array<int> copiedArray(originalArray);
	std::cout << "Copied array: " << copiedArray << std::endl;

	copiedArray[0] = 420042;
	std::cout << "Modified copied array: " << copiedArray << std::endl;
	std::cout << "Original array after modifying copied array: " << originalArray << "\n" << std::endl;

	Array<int> assignedArray;
	assignedArray = originalArray;
	std::cout << "Assigned array: " << assignedArray << std::endl;

	assignedArray[1] = 330033;
	std::cout << "Modified assigned array: " << assignedArray << std::endl;
	std::cout << "Original array after modifying assigned array: " << originalArray << std::endl;
}

void testOutOfBoundsAccess() {
	std::cout << "\033[32m==================== TEST OUT OF BOUNDS ACCESS ====================\033[0m" << std::endl;
	try {
		Array<int> array(5);
		for (size_t i = 0; i < array.size(); ++i) {
			array[i] = static_cast<int>(i * 2);
		}
		std::cout << "The array is :" << array << std::endl;
		std::cout << "Accessing element at index 2: " << array[2] << std::endl;

		std::cout << "Trying to access element at index 10..." << std::endl;
		std::cout << array[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void testArraySize() {
	std::cout << "\033[32m==================== TEST ARRAY SIZE ====================\033[0m" << std::endl;

	Array<int> emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

	Array<int> nonEmptyArray(42);
	std::cout << "Size of non-empty array: " << nonEmptyArray.size() << std::endl;
}

int main()
{
	testEmptyArrayAccess();
	testDefaultInitialization();
	testDeepCopy();
	testOutOfBoundsAccess();
	testArraySize();

}