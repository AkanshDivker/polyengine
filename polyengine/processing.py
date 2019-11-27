# processing.py
# Checking tags and rewrite file
# Authors : Dong Sung Kim, Seoyeon Hwang

import sys
import re
import junk as j
import switch_start as ss
import struct_order as st_change
# string part
from util.encryption import Encryption


class Processing:
    def __init__(self, file: str):
        self.file = file
        self.key = 'test'

    def process(self):
        files = open(self.file)
        line = files.readlines()
        files.close()

        # Tag names
        struct_start = '[order_variable]'
        struct_end = '[/order_variable]'
        switch_start = re.compile('case.*:$')
        junk_start = '[/junk]'
        n_string = re.compile('^#')
        y_string = re.compile('".*"')

        # Preprocessing
        line_process = [word.rstrip() for word in line]
        line_process = [word.lstrip() for word in line_process]

        # Find tags
        struct_start_index = []
        struct_end_index = []
        switch_index = []
        junk_index = []
        string_index = []

        for idx in range(len(line_process)):
            m = switch_start.search(line_process[idx])
            n_s = n_string.search(line_process[idx])
            y_s = y_string.search(line_process[idx])
            if line_process[idx] == struct_start:
                struct_start_index.append(idx)
            elif line_process[idx] == struct_end:
                struct_end_index.append(idx)
            elif m != None:
                switch_index.append(idx)
            elif line_process[idx] == junk_start:
                junk_index.append(idx)
            elif n_s == None and y_s != None:
                string_index.append(idx)

        index_list = {'struct_start_index': struct_start_index, 'struct_end_index': struct_end_index,
                      'switch_index': switch_index, 'junk_index': junk_index}

        # Check tags and print error
        if len(struct_start_index) != len(struct_end_index):
            print(
                "There is no '[order_variable]' or '[/order_variable]'. Please check your code.")
            sys.exit()

        # Change variables
        order = st_change.Struct_order(
            struct_start_index, struct_end_index, line_process)
        order.struct_change()

        # Remove tags and rewrite file
        for idx in struct_start_index:
            line_process[idx] = ''
        for idx in struct_end_index:
            line_process[idx] = ''
        for idx in switch_index:
            tmp = ss.Switch_Start(line_process[idx])
            line_process[idx] = tmp.insert_switch(line_process[idx])
        for idx in junk_index:
            tmp = j.Junk()
            line_process[idx] = tmp.generate_random_junk_code()
        for idx in string_index:
            tmp = y_string.search(line_process[idx])
            tmp2 = line_process[idx][tmp.start():tmp.end()]

            tmp2 = tmp2.strip('"')
            encryption = Encryption(self.key)
            encrypted_string = encryption.encrypt(tmp2)
            byte_string = encryption.to_byte_string(
                encrypted_string.encode('utf-8'))
            
            print(tmp2)
            print(encrypted_string)
            print(encryption.encrypt(encrypted_string))
            print(byte_string)

            line_process[idx] = line_process[idx][:tmp.start(
            )] + " PolyEngine::Decrypt(\"" + byte_string + "\") " + line_process[idx][tmp.end():]
            #print(line_process[idx])

        # Rewrite file
        initialize_include = '#include "PolyEngine.h"\n#define POLY_ENGINE_KEY ' + \
            '"' + self.key + '"\n'
        #initialize_include = ''

        file = open(self.file, 'w')
        file.write(initialize_include)
        for text in line_process:
            file.write(text + '\n')
        file.close()
