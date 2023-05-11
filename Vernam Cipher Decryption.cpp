#include <iostream>
#include <string>
using namespace std;
string vernamDecrypt(string message, string key) {
    string decryptedMessage = "";
    for (int i = 0; i < message.length(); i++) {
        int messageChar = message[i] - 'a';
        int keyChar = key[i] - 'a';
        int decryptedChar = (((messageChar - 'a') - (keyChar - 'a') + 26) % 26) % 26 + 'a';
        decryptedMessage += decryptedChar;
    }
    return decryptedMessage;
}
int main() {
    string message;
    string key;
    cin>>message;
    cin>>key;
    string decryptedMessage = vernamDecrypt(message, key);
    cout << "Decrypted message: " << decryptedMessage << endl;
    return 0; 
}
