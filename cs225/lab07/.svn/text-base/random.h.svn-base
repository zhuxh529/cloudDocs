#ifndef UTIL_RANDOM_H
#define UTIL_RANDOM_H

#include <stdint.h>
#include <sys/time.h>
#include <time.h>

// Taken from
// http://software.intel.com/en-us/articles/fast-random-number-generator-on-the-intel-pentiumr-4-processor/

namespace util
{

namespace internal
{

inline uint32_t time_seed()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec ^ tv.tv_usec ^ clock();
}

inline int_fast16_t rand(uint32_t setseed)
{
	static uint32_t mySeed = (uint32_t)(-1);
	if (setseed != (uint32_t)(-2))
		mySeed = setseed;
	if (mySeed == (uint32_t)(-1))
		mySeed = time_seed();
	mySeed = 214013 * mySeed + 2531011;
	return (mySeed >> 16) & 0x7FFF;
}

}

inline int_fast16_t urand()
{
	return internal::rand(-2);
}

inline int_fast16_t urandn(int32_t n)
{
	return urand() % n;
}

inline void usrand(uint64_t seed)
{
	internal::rand(seed);
}

class Random
{
	private:
	static uint32_t auto_seed;
	uint32_t mySeed;

	static uint32_t time_seed();

	public:
	Random();
	Random(uint64_t seed);

	int_fast16_t rand();
	int_fast16_t rand(int32_t n);
	int_fast16_t operator()();
	int_fast16_t operator()(int32_t n);
	void         srand(uint64_t seed);
};

uint32_t Random::auto_seed = 0;

inline Random::Random()
{
	if (auto_seed == 0)
		auto_seed = time_seed();
	mySeed = auto_seed;
	auto_seed = (rand() << 16) ^ (rand()) ^ internal::time_seed();
}

inline Random::Random(uint64_t seed)
	: mySeed(seed) { }

inline void Random::srand(uint64_t seed)
{
	mySeed = seed;
}

inline int_fast16_t Random::rand()
{
	mySeed = 214013 * mySeed + 2531011;
	return (mySeed >> 16) & 0x7FFF;
}

inline int_fast16_t Random::rand(int32_t n)
{
	return rand() % n;
}

inline int_fast16_t Random::operator()()
{
	return rand();
}

inline int_fast16_t Random::operator()(int32_t n)
{
	return rand(n);
}

} // namespace util

#endif // UTIL_RANDOM_H
