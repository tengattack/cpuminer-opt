#ifndef __WOLF_AES_H
#define __WOLF_AES_H

#include <stdint.h>
#if defined(HAVE_IMMINTRIN_H)
#include <immintrin.h>
#else
#include <tmmintrin.h>
#include <wmmintrin.h>
#endif
#if defined(__XOP__) && (defined(__GNUC__) || defined(__clang__))
#include <x86intrin.h>
#endif

void ExpandAESKey256(__m128i *keys, const __m128i *KeyBuf);

#ifdef __AVX__

#define AES_PARALLEL_N 8
#define BLOCK_COUNT 256

void AES256CBC( __m128i** data, const __m128i** next, __m128i ExpandedKey[][16],
                __m128i* IV );

#else

void AES256CBC( __m128i *Ciphertext, const __m128i *Plaintext,
               const __m128i *ExpandedKey, __m128i IV, uint32_t BlockCount );

#endif

#endif		// __WOLF_AES_H
