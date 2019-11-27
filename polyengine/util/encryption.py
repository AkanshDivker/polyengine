# encryption.py
# Class to utilize the cryptography library and produce encrypted values
# Authors: Akansh Divker

import string
import random
from Crypto.Hash import SHA256


class Encryption:
    def __init__(self):
        letters = string.ascii_lowercase
        key = ''.join(random.choice(letters) for i in range(16))

        hash_object = SHA256.new(data=key.encode('utf-8'))
        self.key = hash_object.hexdigest()

    def encrypt(self, plaintext: str) -> str:
        ciphertext = ""

        for i in range(len(plaintext)):
            current = plaintext[i]
            current_key = self.key[i%len(self.key)]
            ciphertext += chr(ord(current) ^ ord(current_key))

        return ciphertext


    def to_byte_string(self, convert) -> str:
        return ''.join(['\\'+hex(b)[1:] for b in convert])
