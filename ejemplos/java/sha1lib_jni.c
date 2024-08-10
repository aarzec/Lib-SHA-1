#include <jni.h>
#include <openssl/sha.h>
#include <string.h>
#include "ejemplos_java_SHA1Lib.h"

JNIEXPORT void JNICALL Java_SHA1Library_sha1_1hash(JNIEnv *env, jobject thisObj, jstring input, jbyteArray output) {
    const char *inputStr = (*env)->GetStringUTFChars(env, input, NULL);
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)inputStr, strlen(inputStr), hash);
    (*env)->ReleaseStringUTFChars(env, input, inputStr);

    char hex_output[41];
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf(hex_output + (i * 2), "%02x", hash[i]);
    }
    hex_output[40] = '\0';

    (*env)->SetByteArrayRegion(env, output, 0, 41, (jbyte*)hex_output);
}
