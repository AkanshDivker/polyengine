# encryption.py
# Class to utilize the cryptography library and produce encrypted values
# Authors: Akansh Divker

from hashlib import md5
from base64 import b64encode
from base64 import b64decode

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad


class Encryption:
    def __init__(self, key: str):
        self.key = md5(key.encode('utf-8')).digest()

    def create_temp_file(self, plaintext: str):
        f = open('temp_str.txt', 'w+')
        f.write(plaintext)
        f.close()

    def encrypt(self, plaintext: str) -> bytes:
        iv = get_random_bytes(AES.block_size)
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        return b64encode(iv + cipher.encrypt(pad(plaintext.encode('utf-8'), AES.block_size)))

    def to_byte_string(self, convert) -> str:
        return ''.join(['\\'+hex(b)[1:] for b in convert])
