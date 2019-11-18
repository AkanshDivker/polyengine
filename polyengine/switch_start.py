# switch_start.py
# Adding another switch statement
# Authors : Seoyeon Hwang

import string
import random

class Switch_Start:
    def __init__(self, str):
        self.string = str

    def insert_switch(self, str):
        #generate random variable
        _LENGTH = 11
        string_pool = string.ascii_letters + string.digits
        num_pool = string.digits
        var1 = random.choice(string.ascii_letters)
        for i in range(_LENGTH):
            var1 += random.choice(string_pool)

        #writing another switch statement
        first = "{int "
        case0 = "switch (0) { case 0:"
        case1 = "; case 1:"
        case2 = "; case 2:"
        case3 = "; case 3:"
        last = "; }}"

        result = str + first + var1 + "="+random.choice(num_pool)+";" + case0 + var1 + "++" + case1 + var1 + "--" + case2 + var1 + "++" + case3 + var1 + "--" + last
        return result