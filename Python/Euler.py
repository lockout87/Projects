number = 600851475143
highest = 0
for i in range(1, number, 2):
	check = True
	if i %100000000 == 0:
		print ("Still working")
	if i > number/2:
		break
	if number % i == 0:
		for j in range(3, i, 2):
			print(i,j)
			if i % j == 0:
				check = False
			if check == False:
				break;
		if check == True:
			highest = i
print(highest)