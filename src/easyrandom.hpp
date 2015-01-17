/* Class hierarchy to make the annoyingly fine-grained random utilities of
   C++11 much easier to use. Also Templates! Inheritance!
   Ill-advised casting practices! */

#ifndef EASY_RANDOM_HEADER
#define EASY_RANDOM_HEADER

#include <random>

template<typename T>
class PRNG {
protected:
	std::random_device rd {};
	std::default_random_engine re {};

public:
	PRNG() { re.seed(rd()); }
	virtual T operator()() = 0;
};

template<typename T>
class PRNGUniform : public PRNG<T> {
	std::uniform_real_distribution<> dist {};

public:
	PRNGUniform() : PRNGUniform(0, 99) {}
	PRNGUniform(T min, T max) {
		dist = std::uniform_real_distribution<double> {static_cast<double>(min), static_cast<double>(max)};
	}
	T operator()() {
		return  dist(this->re);
	}
};

template<typename T>
class PRNGNormal : public PRNG<T> {
	std::normal_distribution<> dist {};

public:
	PRNGNormal() : PRNGNormal(0, 1) {}
	PRNGNormal(T mean, T stddev) {
		dist = std::normal_distribution<double> {static_cast<double>(mean), static_cast<double>(stddev)};
	}
	T operator()() {
		return  dist(this->re);
	}
};

#endif
