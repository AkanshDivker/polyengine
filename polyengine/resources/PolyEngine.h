#pragma once

#include <string>

using std::string;

class PolyEngine
{
public:
	static string Decrypt(const char* cipheredBytes, const string& key)
	{
		int size = sizeof(cipheredBytes) / sizeof(cipheredBytes[0]);
		std::string ciphertext(cipheredBytes, size);

		string plaintext = ciphertext;

		for (int i = 0; i < ciphertext.size(); i++)
			plaintext[i] = ciphertext[i] ^ key[i % (sizeof(key) / sizeof(char))];

		return plaintext;
	}
};