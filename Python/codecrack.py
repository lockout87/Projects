alpha1 = {
	"a" : 1,
	"b" : 2,
	"c" : 3,
	"d" : 4,
	"e" : 5,
	"f" : 6,
	"g" : 7,
	"h" : 8,
	"i" : 9,
	"j" : 10,
	"k" : 11,
	"l" : 12,
	"m" : 13,
	"n" : 14,
	"o" : 15,
	"p" : 16,
	"q" : 17,
	"r" : 18,
	"s" : 19,
	"t" : 20,
	"u" : 21,
	"v" : 22,
	"w" : 23,
	"x" : 24,
	"y" : 25,
	"z" : 26
	}
script = "map"
empty = []


for i in script:
	if i != "(" and i != ")" and i != " " and i != "." and i != "'":
		final = alpha1[i] + 2
		if final > 26:
			final += -26
		for let, num in alpha1.items():
			if final == num:
				empty.append(let)
	else:
		empty.append(i)
print("".join(empty))