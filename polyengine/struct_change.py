# struct.py
# Random order struct
# Authors : Dong Sung Kim

import random

class Struct:
	def __init__(self, start_index: list, end_index, source: list):
		self.start_index = start_index
		self.end_index = end_index
		self.source = source

	def struct_change(self):
		# Shuffle variable orders
		for idx1 in range(len(self.start_index)):
		    temp_code = []
		    temp_variable = self.source[self.start_index[idx1] + 1:self.end_index[idx1]]
		    temp_code = random.sample(temp_variable, self.end_index[idx1] - self.start_index[idx1] - 1)
		    for idx2 in range(self.end_index[idx1] - self.start_index[idx1] - 1):
		        self.source[self.start_index[idx1] + idx2 + 1] = temp_code[idx2]
		        