# encryption.py
# Class to utilize the cryptography library and produce encrypted values
# Authors: Akansh Divker

import os
import subprocess


class Encryption:
    def __init__(self, password: str):
        self.password = password

    def create_temp_file(self, plaintext: str):
        f = open('temp_str.txt', 'w+')
        f.write(plaintext)
        f.close()

    def encrypt(self, plaintext: str):
        self.create_temp_file(plaintext)

        p = subprocess.Popen(['openssl', 'enc', '-aes-256-cbc', '-in', 'plaintext.txt', '-base64', '-md', 'sha1'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
        stdout, stderr = p.communicate(input='test\ntest\n')

        print(stdout)

    def to_byte_string(self, convert) -> str:
        return ''.join(['\\'+hex(b)[1:] for b in convert])
