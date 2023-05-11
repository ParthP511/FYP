# Diffie-Hellman Code


def prime_checker(p):
	# Checks If the number entered is a Prime Number or not
	if p < 1:
		return -1
	elif p > 1:
		if p == 2:
			return 1
		for i in range(2, p):
			if p % i == 0:
				return -1
			return 1


def primitive_check(g, p, L):
	# Checks If The Entered Number Is A Primitive Root Or Not
	for i in range(1, p):
		L.append(pow(g, i) % p)
	for i in range(1, p):
		if L.count(i) > 1:
			L.clear()
			return -1
		return 1


l = []
while 1:
	P = int(input("Enter P : "))
	if prime_checker(P) == -1:
		print("Number Is Not Prime, Please Enter Again!")
		continue
	break

while 1:
	G = int(input(f"Enter The Primitive Root Of {P} : "))
	if primitive_check(G, P, l) == -1:
		print(f"Number Is Not A Primitive Root Of {P}, Please Try Again!")
		continue
	break

# Private Keys
x1, x2 = int(input("Enter The Private Key Of User 1 : ")), int(
	input("Enter The Private Key Of User 2 : "))
while 1:
	if x1 >= P or x2 >= P:
		print(f"Private Key Of Both The Users Should Be Less Than {P}!")
		continue
	break

# Calculate Public Keys
y1, y2 = pow(G, x1) % P, pow(G, x2) % P

# Generate Secret Keys
k1, k2 = pow(y2, x1) % P, pow(y1, x2) % P

print(f"\nSecret Key For User 1 Is {k1}\nSecret Key For User 2 Is {k2}\n")

if k1 == k2:
	print("Keys Have Been Exchanged Successfully")
else:
	print("Keys Have Not Been Exchanged Successfully")



# 67	20	2 7 11 12 13 18 20 28 31 32 34 41 44 46 48 50 51 57 61 63
# 71	24	7 11 13 21 22 28 31 33 35 42 44 47 52 53 55 56 59 61 62 63 65 67 68 69
# 73	24	5 11 13 14 15 20 26 28 29 31 33 34 39 40 42 44 45 47 53 58 59 60 62 68
# 79	24	3 6 7 28 29 30 34 35 37 39 43 47 48 53 54 59 60 63 66 68 70 74 75 77
# 83	40	2 5 6 8 13 14 15 18 19 20 22 24 32 34 35 39 42 43 45 46 47 50 52 53 54 55 56 57 58 60 62 66 67 71 72 73 74 76 79 80
# 89	40	3 6 7 13 14 15 19 23 24 26 27 28 29 30 31 33 35 38 41 43 46 48 51 54 56 58 59 60 61 62 63 65 66 70 74 75 76 82 83 86
# 97	32	5 7 10 13 14 15 17 21 23 26 29 37 38 39 40 41 56 57 58 59 60 68 71 74 76 80 82 83 84 87 90 92
# 101	40	2 3 7 8 11 12 15 18 26 27 28 29 34 35 38 40 42 46 48 50 51 53 55 59 61 63 66 67 72 73 74 75 83 86 89 90 93 94 98 99