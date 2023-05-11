#include <iostream>
#include <string>
using namespace std;
string caesar_cipher(string message, int key) {
    string cipher = "";
    // Iterate over each character in the message
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
    // Encrypt alphabetic characters by shifting them by the
        if (isalpha(c)) {
            if (isupper(c)) {
                c = (c - 'A' + key) % 26 + 'A';
            } else {
                c = (c - 'a' + key) % 26 + 'a';
            }
        }
        // Append the encrypted character to the cipher string
        cipher += c;
}
    return cipher;
}
int main() {
    string message;
    cin>>message;
    int key;
    cin>>key;
    string cipher = caesar_cipher(message, key);
    cout << "Message: " << message << endl;
    cout << "Key: " << key << endl;
    cout << "Cipher: " << cipher << endl;
    return 0;
}
