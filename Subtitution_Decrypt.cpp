#include <iostream>
#include <string>

std::string substitutionDecrypt(const std::string& cipherText, int key) {
    std::string decryptedText = "";
    for (char c : cipherText) {
        if (isalpha(c)) {
            char base = (isupper(c)) ? 'A' : 'a';
            decryptedText += ((c - base - key + 26) % 26) + base;
        } else {
            decryptedText += c;
        }
    }
    return decryptedText;
}

int main() {
    std::string cipherText;
    int key;

    std::cout << "Enter the text to decrypt: ";
    std::getline(std::cin >> std::ws, cipherText); // To handle whitespace characters

    std::cout << "Enter the key: ";
    std::cin >> key;

    std::string decryptedText = substitutionDecrypt(cipherText, key);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
