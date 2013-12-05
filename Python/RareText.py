f = open("textblock.txt")
read = f.read()
import re
# create a character:frequency dictionary
cf_dic = {}
print ("".join(re.findall('[a-z]', read)))
for char in read.lower():
    cf_dic[char] = cf_dic.get(char, 0) + 1
for key in cf_dic:
	print (key, cf_dic[key])
print ("Characters sorted by ASCII number:")
# create a sorted list of keys
key_list = sorted(cf_dic.keys())
for key in key_list:
    # don't show space and newline
    if key not in " \n":
        # associate the value with the key
        print (key, cf_dic[key])
print()
print ("Characters sorted by frequency:")
# convert cf_dic to list of (k, v) tuples with cf_dic.items()
# flip tuple elements to (v, k) using list comprehension
# then sort list of tuples (order is v,k), highest v first
value_key = sorted([(v, k) for k, v in cf_dic.items()], reverse=True)
for vk in value_key:
    # don't show space and newline
    if vk[1] not in " \n":
        print(vk[1], vk[0])
print()
print ("Characters sorted by frequency (method 2):")
# using list of (k, v) tuples, operator.itemgetter() and sorted()
# establish sort key: index of tuple element key = 0, value = 1
import operator
index = operator.itemgetter(1)
# create list of (k, v) tuples from dictionary
key_value1 = cf_dic.items()
# sort list of (k, v) tuples by v, highest v first
key_value2 = sorted(key_value1, key=index, reverse=True)
for kv in key_value2:
    # don't show space and newline
    if kv[0] not in " \n":
        print (kv[0], kv[1])
		
f.close()