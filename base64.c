#include "base64.h"

#include <stdlib.h>
#include <stdint.h>

char base64_map[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/'
};

char *base64_encode(u8a_t *src) {
	size_t dest_len;
	char *dest;

	dest_len = 4*(((LEN(src)+2)-((LEN(src)+2)%3))/3);
	dest = malloc((dest_len+1)*sizeof(char));

	for (int i=0, j=0; i<LEN(src); i+=3, j+=4) {
		uint32_t triple = (uint32_t)(_(src)[i  ]) << 16;
		triple |= (i+1<LEN(src)) ? (uint32_t)(_(src)[i+1]) << 8 : 0;
		triple |= (i+2<LEN(src)) ? (uint32_t)(_(src)[i+2]) : 0;
		
		dest[j  ] = base64_map[(uint8_t)(triple >> 18) & 0x3F];
		dest[j+1] = base64_map[(uint8_t)(triple >> 12) & 0x3F];
		dest[j+2] = base64_map[(uint8_t)(triple >>  6) & 0x3F];
		dest[j+3] = base64_map[(uint8_t)(triple      ) & 0x3F];

		switch (LEN(src) - i) {
			case 1:
				dest[j+2] = '=';
			case 2:
				dest[j+3] = '=';
		}
 	}
	dest[dest_len] = 0;

	return dest;
}
