#include <iostream>
#include <string>
using namespace std;
string caesarDecrypt(string message, int key) {
    string decryptedMessage = "";
    for (int i = 0; i < message.length(); i++) {
        if (isalpha(message[i])) {
            int messageChar = tolower(message[i]) - 'a';
            int decryptedChar = (messageChar - key) % 26;
            if (decryptedChar < 0) {
                decryptedChar += 26;
            }
            decryptedMessage += decryptedChar + 'a';
        } else {
            decryptedMessage += message[i];
        }
}
    return decryptedMessage;
}
int main() {
    string message;
    cin>>message;
    int key;
    cin>>key;
    string decryptedMessage = caesarDecrypt(message, key);
    cout << "Decrypted message: " << decryptedMessage << endl;
    return 0;
}
