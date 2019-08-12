/* 
 * Helper definitions and functions for runnable test suite programs.
 * 
 * Bitcoin cryptography library
 * Copyright (c) Project Nayuki
 * 
 * https://www.nayuki.io/page/bitcoin-cryptography-library
 * https://github.com/nayuki/Bitcoin-Cryptography-Library
 */

#pragma once

#undef NDEBUG
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>


using std::size_t;
using std::array;
using std::vector;

typedef vector<std::uint8_t> Bytes;


static inline Bytes asciiBytes(const char *str) {
	return Bytes(str, str + std::strlen(str));
}


static inline Bytes hexBytes(const char *str) {
	Bytes result;
	size_t length = std::strlen(str);
	assert(length % 2 == 0);
	for (size_t i = 0; i < length; i += 2) {
		unsigned int temp;
		std::sscanf(&str[i], "%02x", &temp);
		result.push_back(static_cast<std::uint8_t>(temp));
	}
	return result;
}
