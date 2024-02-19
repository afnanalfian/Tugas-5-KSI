#include <iostream>
#include <string>

std::string transposeDecrypt(const std::string& cipherText, int key) {
    int rows = (cipherText.length() + key - 1) / key;
    char matrix[rows][key];

    int index = 0;
    for (int j = 0; j < key; ++j) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][j] = cipherText[index++];
        }
    }

    std::string decryptedText = "";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < key; ++j) {
            decryptedText += matrix[i][j];
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

    std::string decryptedText = transposeDecrypt(cipherText, key);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
