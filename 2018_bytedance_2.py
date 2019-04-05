n = input()
arr = input()
arr = arr.split()
arr = [int(i) for i in arr]
# print(arr)
arr = sorted(arr)
arr.reverse()
print(arr)
res = 0

for sub in range(1, len(arr) + 1, 1):
	tmp = arr[:sub]
	Min = tmp[-1]
	Sum = sum(tmp)
	tmp_res = Min * Sum
	if tmp_res > res:
		res = tmp_res

print(res)
print(81 * (87 + 81 + 81))
print(59 * (87 + 81 + 81 + 59))