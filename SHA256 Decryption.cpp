#include <openssl/sha.h>
#include <iostream>
#include <cstring>
int main() {
    std::string input = "Hello, world!";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash, &sha256);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    std::cout << std::endl;
return 0; }
