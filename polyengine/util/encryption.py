# encryption.py
# Class to utilize the cryptography library and produce encrypted values
# Authors: Akansh Divker

import os
import subprocess


class Encryption:
    def __init__(self, password: str):
        self.password = password
        self.temp_file = 'temp_str.txt'

    def create_temp_file(self, plaintext: str):
        f = open('temp_str.txt', 'w+')
        f.write(plaintext)
        f.close()

    def encrypt(self, plaintext: str) -> bytes:
        # Create temporary text file containing string to encrypt
        self.create_temp_file(plaintext)

        # Use OpenSSL command line to encrypt string
        encrypted_bytes = subprocess.check_output(
            ['openssl', 'enc', '-aes-256-cbc', '-in', self.temp_file, '-base64', '-md', 'sha1', '-pass', self.password])

        # Decode the bytes into a string
        #encrypted = encrypted_bytes.decode('utf-8')

        return encrypted_bytes

    def to_byte_string(self, convert) -> str:
        return ''.join(['\\'+hex(b)[1:] for b in convert])
