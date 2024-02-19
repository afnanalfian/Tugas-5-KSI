#include <iostream>
#include <string>

std::string substitutionEncrypt(const std::string& plainText, int key) {
    std::string cipherText = "";
    for (char c : plainText) {
        if (isalpha(c)) {
            char base = (isupper(c)) ? 'A' : 'a';
            cipherText += ((c - base + key) % 26) + base;
        } else {
            cipherText += c;
        }
    }
    return cipherText;
}

int main() {
    std::string plainText;
    int key;

    std::cout << "Enter the text to encrypt: ";
    std::getline(std::cin, plainText);

    std::cout << "Enter the key: ";
    std::cin >> key;

    std::string cipherText = substitutionEncrypt(plainText, key);
    std::cout << "Encrypted Text: " << cipherText << std::endl;

    return 0;
}
