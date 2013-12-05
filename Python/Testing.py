def largest_prime_factor(n):
	
	largest_factor = 1
	
	while n % 2 == 0:
		largest_factor = 2
		n = n/2
	
	p = 3
	while n !=  1:
		while n% p == 0:
			largest_factor = p
			n = n/p
		p += 2
	
	return largest_factor
	
print (largest_prime_factor(600851475143))
