#include "byte.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

u8a_t *u8a_new(size_t size) {
	u8a_t *ret = malloc(sizeof(u8a_t));
	ret->size = size;
	ret->data = malloc(size*sizeof(uint8_t));
	return ret;
}

void u8a_delete(u8a_t *a) {
	free(a->data);
	free(a);
}

u8a_t *u8a_from_str(const char* str) {
	u8a_t *ret = malloc(sizeof(u8a_t));
	ret->size = strlen(str);
	ret->data = (uint8_t*)str;
	return ret;
}

static inline uint8_t hex_decode_char(char hex) {
	uint8_t ret = 0;
	if (('0' <= hex) && (hex <= '9'))
		ret = hex - 0x30;
	else
		ret = 10 + (toupper(hex) - 0x41);
	return ret;
}

u8a_t *u8a_from_hexstr(const char* src) {
	u8a_t *dest;
	size_t len = strlen(src)/2;

	dest = u8a_new(len);
	for (int i=0; i<len; ++i) {
		_(dest)[i] = (hex_decode_char(src[2*i]) << 4) | (hex_decode_char(src[2*i+1]) & 0x0F);
	}

	return dest;
}

