#include <iostream>
#include <openssl/sha.h>
#include <string.h>

extern "C" void sha1_hash(const char *input, char *output) {
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)input, strlen(input), hash);

    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    output[SHA_DIGEST_LENGTH * 2] = '\0';
}
