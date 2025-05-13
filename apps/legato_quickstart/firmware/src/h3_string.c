// Copyright (C) 2006 Microchip Technology Inc. and its subsidiaries
//
// SPDX-License-Identifier: MIT

#include <stdio.h>

#define CHUNK_SIZE 4

struct chunk {
	unsigned long val[CHUNK_SIZE];
};
static const struct chunk c_zero = {{0}};

void *h3_memcpy(void *dst, const void *src, int cnt)
{
	char *d;
	const char *s;
	const struct chunk *csrc = (const struct chunk *)src;
	struct chunk *cdst = (struct chunk *)dst;

	/* Check if the addresses are word-alighed */
	if (((unsigned long)src & 0x3) == 0 && ((unsigned long)dst & 0x3) == 0) {
		while (cnt >= sizeof(struct chunk)) {
			*cdst++ = *csrc++;
			cnt -= sizeof(struct chunk);
		}
	}

	d = (char *) cdst;
	s = (const char *) csrc;

	while (cnt--)
		*d++ = *s++;

	return dst;
}

void *h3_memset(void *dst, int val, int cnt)
{
	char *d;
	const struct chunk *cpattern = NULL;
	struct chunk *cdst = (struct chunk *)dst;

	if (val == (c_zero.val[0] & 0xFF))
		cpattern = &c_zero;

	/* Check if the address is word-alighed */
	if (cpattern && (((unsigned long)dst & 0x3) == 0)) {
		while (cnt >= sizeof(struct chunk)) {
			*cdst++ = *cpattern;
			cnt -= sizeof(struct chunk);
		}
	}

	d = (char *) cdst;

	while (cnt--)
		*d++ = (char)val;

	return dst;
}
