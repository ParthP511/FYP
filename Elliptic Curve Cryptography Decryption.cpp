#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/objects.h>
// Function to decrypt ECC ciphertext using ECDSA
// Assumes the private key, public key, and ciphertext are already initialized
// Returns the plaintext as a string
std::string ecc_decrypt(EC_KEY* ec_key, EC_POINT* ec_point, const unsigned char* ciphertext, size_t ciphertext_len)
 {
    // Create a new ECDSA structure
    ECDSA_SIG* ecdsa_sig = ECDSA_SIG_new();
    if (!ecdsa_sig) {
        // Error handling
    }
    // Create a new BIGNUM structure to hold the shared secret
    BIGNUM* shared_secret = BN_new();
    if (!shared_secret) {
        // Error handling
    }
// Compute the shared secret using the private key and public key
if (!ECDH_compute_key(shared_secret, BN_num_bytes(shared_secret), ec_point, ec_key, NULL)) {
        // Error handling
    }
// Set the r and s values of the ECDSA signature from the ciphertext
if (!ECDSA_SIG_set0(ecdsa_sig, BN_bin2bn(ciphertext, ciphertext_len / 2, NULL), BN_bin2bn(ciphertext + ciphertext_len / 2, ciphertext_len / 2, NULL))) {
        // Error handling
    }
// Create a new plaintext buffer to hold the decrypted ciphertext
unsigned char* plaintext = new unsigned char[ciphertext_len];
    if (!plaintext) {
        // Error handling
    }
    // Decrypt the ciphertext using ECDSA
int plaintext_len = ECDSA_do_verify(ciphertext, ciphertext_len, ecdsa_sig, ec_key);
    if (plaintext_len < 0) {
        // Error handling
    }
    // Convert the decrypted plaintext to a string
std::string result(reinterpret_cast<const char*>(plaintext), plaintext_len);
    // Clean up memory

delete[] plaintext;
    BN_clear_free(shared_secret);
    ECDSA_SIG_free(ecdsa_sig);
    return result;
}
