'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import re
 
def compress_string(text):
  first_char = text[0].upper()
  remaining_text = text[1:]
  vowels = "aeiouAEIOU"
  consonant_block = ""
  compressed_text = ""
  for char in remaining_text:
    if char not in vowels:
      consonant_block += char
    else:
      if consonant_block:
        compressed_text += str(len(consonant_block))
      consonant_block = ""
      compressed_text += char
  if consonant_block:
    compressed_text += str(len(consonant_block))
  compressed_text = re.sub(r"([aeiouAEIOU])\1+", r"\1", compressed_text)
  return first_char + compressed_text

T = int(input())
for _ in range(T):
    N = int(input())
    S = input()
    print(compress_string(S))
