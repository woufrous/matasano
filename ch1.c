#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "byte.h"
#include "base64.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage:\n\t%s HEXSTR\n", argv[0]);
		return 1;
	}

	const char *hexstr = argv[argc-1];

	// u8a_t *data = hex_decode(hexstr);
	u8a_t *data = u8a_from_str(hexstr);

	char *b64 = base64_encode(data);

	printf("%s\n", b64);

	free(data);
	free(b64);

	return 0;
}
