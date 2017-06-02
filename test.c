#include <stdint.h>

//  Windows
#ifdef _WIN32

#include <intrin.h>
uint64_t rdtsc(){
    return __rdtsc();
}

//  Linux/GCC
#else

uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

#endif

#include <stdio.h>

int main(void)
{
	int a = 5;
	int i = 1000000;
	int sum = 0;

	while (i--)
	{
		uint64_t lol = rdtsc();
		a ^= a;
		uint64_t z = rdtsc();
		sum += z - lol;
	}
	dprintf(2, "%llu\n", sum);
	sum ^= sum;
	i = 1000000;
	while (i--)
	{
		uint64_t lol = rdtsc();
		a = 0;
		uint64_t z = rdtsc();
		sum += z - lol;
	}
	dprintf(2, "%llu\n", sum);
	return (0);
}
