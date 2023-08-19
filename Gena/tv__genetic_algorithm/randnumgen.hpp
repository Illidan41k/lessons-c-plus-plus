
// Copyright (C) by Tim Völcker. All rights reserved.
// See the complete tutorial at www.timvoelcker.de/genetic_algorithm.html

// Functions for the creation of (pseudo) random numbers.
//
// A Mersenne Twister is used as a high quality (pseudo) random number
// generator. It is slower than simply calling the rand() function but it will 
// create better random numbers with a very good (uniform) distribution and
// is thread safe.
//
// A random number generator instance will be created once for every thread,
// so it must not be locked / synced, which will result in a better performance.
//
// The system time & thread id will be used to create an initial random seed.
// When the system clock is called by multiple threads at nearly the same time
// it might return the same value. A hash of the thread id will be combined
// with the current time to create a unique random seed for every thread.


#pragma once

#include <iostream>
#include <string>

#include <random>
using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::bernoulli_distribution;

#include <chrono>

#include <thread>
using std::thread;

#include <functional>
using std::hash;

#include <memory>
using std::unique_ptr;


// By defining a fixed seed value the random number generator can be
// forced to produce the exact same set of pseudo random numbers all
// the time. This can be temporarily useful for general debugging or
// performance optimizations of algorithms.

// #define USE_FIXED_SEED


inline unsigned int getRandomSeed()
{
    #ifdef USE_FIXED_SEED
        return 123456789;
    #else
        // Seed = Randomized variable address per thread (by os) + thread id + time

        const auto localVariable = 0;
        const auto randomMemoryAddress = reinterpret_cast<size_t>(&localVariable);
        const auto time = static_cast<size_t>(
            std::chrono::high_resolution_clock::now().time_since_epoch().count() );
        const size_t thread_id = hash<thread::id>()(std::this_thread::get_id());
        return static_cast<unsigned int>(randomMemoryAddress + thread_id + time);
    #endif
}


inline mt19937* getMersenneTwisterEngine()
{
    static thread_local unique_ptr<mt19937> generator_owner;
    static thread_local mt19937* generator = nullptr;

    if (!generator)
    {
        generator_owner.reset(new mt19937(getRandomSeed()));
        generator = generator_owner.get();
    }

    return generator;
}


template<typename T> T
inline getRandomIntegerInRange(T minInclusive, T maxInclusive)
{
    auto generator = getMersenneTwisterEngine();
    uniform_int_distribution<T> distribution(minInclusive, maxInclusive);
    return distribution(*generator);
}


template<typename T> T
inline getRandomRealInRange(T minInclusive, T maxInclusive)
{
    auto generator = getMersenneTwisterEngine();
    uniform_real_distribution<T> distribution(minInclusive, maxInclusive);
    return distribution(*generator);
}


inline bool getRandomTrueWithProbability(double probability)
{
    auto generator = getMersenneTwisterEngine();
    std::bernoulli_distribution distribution(probability);
    return distribution(*generator);
}
