#include <stdio.h>

#include "byte.h"

const char *keystr = "686974207468652062756c6c277320657965";
const char *instr = "1c0111001f010100061a024b53535009181c";

u8a_t *u8a_xor(u8a_t *key, u8a_t *data) {
	int i = 0;
	u8a_t *res = u8a_new(LEN(data));

	for (i=0; i<LEN(data); ++i)
		_(res)[i] = _(data)[i] ^ _(key)[i];

	return res;
}

int main(int argc, char *argv[]) {
	u8a_t *key, *in, *enc;

	key = u8a_from_hexstr(keystr);
	in = u8a_from_hexstr(instr);

	enc = u8a_xor(key, in);

	for (int i=0; i<LEN(enc); ++i)
		printf("%02X", _(enc)[i]);
	puts("");

	u8a_delete(key);
	u8a_delete(in);
	u8a_delete(enc);

	return 0;
}
