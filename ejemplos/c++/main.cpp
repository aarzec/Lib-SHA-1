#include <dlfcn.h>
#include <iostream>

int main() {
    void* handle = dlopen("../../libsha1.so", RTLD_LAZY);
    typedef void (*sha1_hash_t)(const char *input, char *output);
    sha1_hash_t sha1_hash = (sha1_hash_t) dlsym(handle, "sha1_hash");

    char input[] = "Hola Mundo!";
    char output[40 + 1];

    sha1_hash(input, output);

    std::cout << "String: " << input << std::endl;
    std::cout << "SHA1 hash: " << output << std::endl;

    return 0;
}
