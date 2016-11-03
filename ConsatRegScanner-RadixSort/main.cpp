#include <iostream>
#include <algorithm>
#include <time.h>
#include <thread>
#include <unordered_set>
#include <boost/iostreams/device/mapped_file.hpp>

/**
 * THINGS NEEDED FOR THIS TO WORK:
 * 1. Boost library, installed under C:\Program Files\boost\boost_1_62_0
 * 2. Change the path for the txt file to read.
 * 3. Implement clock routines where I commented down below. (Note that the last few printouts should not be part of the time, preferably.)
 */

int concat(int a, int b) {
	int times = 10;
	while (times <= b)
		times *= 10;
	return a*times + b;
}

int main() {
	// -----------------------------------------
	// START CLOCK BETWEEN HERE!
	// -----------------------------------------
	clock_t start_time = clock();
	// -----------------------------------------
	// START CLOCK BETWEEN HERE!
	// -----------------------------------------

	boost::iostreams::mapped_file mmap("FILEPATH", boost::iostreams::mapped_file::readonly);

	auto data_pointer = mmap.const_data();
	auto length = data_pointer + mmap.size();

	int* line_content = new int[6000000];
	int n = 0;
	while (data_pointer && data_pointer < length) {
		for (int i = 0; i < 6; i++) {
			if ((int)data_pointer[i] > 64 && (int)data_pointer[i] < 91)
				line_content[n] = concat(line_content[n], data_pointer[i]);
			else if ((int)data_pointer[i] > 47 && (int)data_pointer[i] < 58)
				line_content[n] = concat(line_content[n], data_pointer[i] - '0');
		}

		data_pointer = data_pointer + 8;
		n++;
	}

	std::sort(line_content, line_content + n);

	bool found_duplicate = false;
	for (int i = 0; i < n; i++) {
		if (line_content[i] == line_content[i+1]) {
			found_duplicate = true;
			break;
		}
		i++;
	}

	// -----------------------------------------
	// END CLOCK BETWEEN HERE!
	// -----------------------------------------
	clock_t end_time = clock();
	double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	// -----------------------------------------
	// END CLOCK BETWEEN HERE!
	// -----------------------------------------


	std::cout << std::endl << "Found duplicate: " << found_duplicate << std::endl;
	std::cout << "Total execution time: " << time_spent << "s";
	std::cout << std::endl;
}