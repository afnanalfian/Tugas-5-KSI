#include <iostream>
#include <string>

std::string transposeEncrypt(const std::string &plainText, int key)
{
    int rows = (plainText.length() + key - 1) / key;
    char matrix[rows][key];

    int index = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < key; ++j)
        {
            if (index < plainText.length())
                matrix[i][j] = plainText[index++];
            else
                matrix[i][j] = ' ';
        }
    }

    std::string cipherText = "";
    for (int j = 0; j < key; ++j)
    {
        for (int i = 0; i < rows; ++i)
        {
            cipherText += matrix[i][j];
        }
    }

    return cipherText;
}

int main()
{
    std::string plainText;
    int key;

    std::cout << "Enter the text to encrypt: ";
    std::getline(std::cin, plainText);

    std::cout << "Enter the key: ";
    std::cin >> key;

    std::string cipherText = transposeEncrypt(plainText, key);
    std::cout << "Encrypted Text: " << cipherText << std::endl;

    return 0;
}
