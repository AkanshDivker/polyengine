# encryption.py
# Class to utilize the cryptography library and produce encrypted values
# Authors: Akansh Divker

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes


class Encryption:
    def __init__(self, key: str):
        self.key = key

    def encrypt(self, plaintext: str) -> str:
        key = get_random_bytes(16)
        cipher = AES.new(key, AES.MODE_EAX)
        ciphertext, tag = cipher.encrypt_and_digest(data)


    def to_byte_string(self, convert) -> str:
        return ''.join(['\\'+hex(b)[1:] for b in convert])
