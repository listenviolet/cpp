with open("test.txt", "r") as f:
	str = f.readline()
	# print(str)
	str = str.split()
	print(len(str))