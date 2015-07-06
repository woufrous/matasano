#ifndef _BYTE_H
#define _BYTE_H

#include <stdlib.h>
#include <stdint.h>

#define _(a)	(a->data)
#define LEN(a)	(a->size)

typedef struct {
	uint8_t *data;
	size_t size;
} u8a_t;

u8a_t *u8a_new(size_t size);
u8a_t *u8a_from_str(const char* str);
void u8a_delete(u8a_t *a);
u8a_t *u8a_from_hexstr(const char* src);

#endif /* _BYTE_H */
