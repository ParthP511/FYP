#include <iostream>
#include <string>
using namespace std;
string vernam_cipher(string message, string key) {
    string cipher = "";
    int n = message.length();
    // Make sure key length is the same as message length
    while (key.length() < n) {
        key += key; 
    }
    // Encrypt each character in the message
    for (int i = 0; i < n; i++) {
        char c = (((message[i] - 'a') + (key[i] - 'a')) % 26) + 'a';
        cipher += c; 
    }
    return cipher;
}
int main() {
    string message;
    string key;
    cin>>message;
    cin>>key;
    string cipher = vernam_cipher(message, key);
    cout << "Message: " << message << endl;
    cout << "Key: " << key << endl;
    cout << "Cipher: " << cipher << endl;
    return 0;
}
