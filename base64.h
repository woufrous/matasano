#ifndef _BASE64_H
#define _BASE64_H

#include "byte.h"

extern char base64_map[];

char *base64_encode(u8a_t *src);

#endif /* _BASE64_H */
