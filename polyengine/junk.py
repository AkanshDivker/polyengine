# insert_junk.py
# Outputs lines of junk code in a list
# Authors : Minh Duc Nguyen

import sys
import random
import string

# change when junk library is used
JUNK_FILE_C = 'junk.c'
JUNK_FILE_CPP = 'junk.cpp'
JUNK_NUM = 3

class Junk:
    def generate_random_junk_code(self):
        number_var = random.randint(8, 20)
        variables = list()
        junk = ''

        for i in range(number_var):
            # create random variables
            varId = self.random_string(string.ascii_letters + '_', random.randint(10, 20))
            typeId = random.randint(0, 2)
            typeStr = ''
            suffix = ''
            value = ''

            if typeId == 0:
                typeStr = 'int'
                value = str(random.randint(129, 42000))
            elif typeId == 1:
                typeStr = 'char'
                value = '\'' + self.random_string(string.ascii_letters + '0123456789' + '_-+*^', 1) + '\''
            else:
                typeStr = 'char'
                suffix = '[]'
                value = '\"' + self.random_string(string.ascii_letters + ' ' + '0123456789' + '_-+*^', random.randint(20, 50)) + '\"'

            output = 'volatile ' + typeStr + ' ' + varId + suffix + ' = ' + value + ';\n'
            junk += output

            variables.append([typeId, varId, value])


        # create random code
        junk += '\n'
        for i in range(3):
            sameTypes = list()
            for elem in variables:
                if elem[0] == i:
                    sameTypes.append(elem)

            if len(sameTypes) < 3:
                continue
            else:
                var1 = random.choice(sameTypes)[1]
                var2 = random.choice(sameTypes)[1]
                var3 = random.choice(sameTypes)[1]
                output = ''
                if i == 0:
                    output += var1 + ' += ' + var2 + ' - ' + var3 + ';\n'
                elif i == 1:
                    output += var1 + ' = ' + var2 + ';\n'
                    output += var1 + ' = ' + var3 + ';\n'
                else:
                    output += var1 + '[' + str(random.randint(0, len(var1) - 2)) + ']' + ' = ' + var2 + '[' + str(random.randint(0, len(var2)) - 2) + '];\n'
                    output += var2 + '[' + str(random.randint(0, len(var2) - 2)) + ']' + ' = ' + var3 + '[' + str(random.randint(0, len(var3)) - 2) + '];\n'

                junk += output
        return junk

    def random_string(self, chars = '', length = 25):
        return ''.join(random.choice(chars) for i in range(length))

        