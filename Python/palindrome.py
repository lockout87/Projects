lN = 101
lP = 0
for i in range (100, lN):
	for l in range (100,lN):
		N = l*i
		N_string = str(N)
		N_S_length = int(len(N_string))
		check = True
		m = 1
		print (N)
		print (N_string)
		print (N_S_length, type(N_S_length))
		print (N_string[0], N_string[N_S_length - 1])
		if N_S_length % 2 == 0:
			for m in N_S_length / 2:
				if N_string[m-1] != N_string[N_S_length - m]:
					check = False
				else:
					check = True
				if check == False:
					break
			if check == True:
				lP = N
		else:
			while True:
				if N_string[m-1] != N_string[N_S_length - m]:
					check = False
				else:
					check = True
				if check == False or m > (N_S_length + 1)/2:
					break		
				m += 1
				print (m)
			if check == True:
				lP = N

print (lP)