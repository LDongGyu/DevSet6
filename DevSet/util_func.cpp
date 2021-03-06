#include <cstdlib>
#include <vector>

int bigrand(int v) {
	int r = 0;

	// this will generate a Integer using 30bit(larger than 10^8)
	for (int i = 0; i < 2; ++i) {
		r = (r << 15) | (rand() & 0x7FFF);
	}
	// return value: 0 to v
	return r % (v + 1);
}

void int_to_bitarray(int num) {
	std::vector<int> v;
	v.reserve(32);
	unsigned int i = 0x80000000;
	while (i > 0) {
		if(num & i) v.push_back(1);
		else v.push_back(0);
		i >>= 1;
	}
	for (std::vector<int>::reverse_iterator iter = v.rbegin(); iter != v.rend(); iter++)
		printf("%d", *iter);
	printf("\n");
}