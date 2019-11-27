#include <iostream>
#include "PolyEngine.h"

using namespace std;

int main(int argc, char **argv)
{
    //create a sample key
    unsigned char key_bytes[16];
    RAND_bytes(key_bytes, sizeof(key_bytes));
    string key = string((char *)key_bytes, sizeof(key_bytes));

    //text to encrypt
    string plaintext = "elephants in space";
    cout << plaintext << endl;

    //encrypt
    vector<unsigned char> ciphertext = PolyEngine::aes_128_gcm_encrypt(plaintext, key);

    //output
    static const char *chars = "0123456789ABCDEF";
    for (int i = 0; i < ciphertext.size(); i++)
    {
        cout << chars[ciphertext[i] / 16];
        cout << chars[ciphertext[i] % 16];
    }
    cout << endl;

    //decrypt
    string out = PolyEngine::aes_128_gcm_decrypt(ciphertext, key);
    cout << out << endl;
}