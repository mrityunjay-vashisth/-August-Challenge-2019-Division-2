t = input()
while t:
	n = raw_input()
	res = int(n[0])
	for i in range(1, len(n), 1):
		res ^= int(n[i])
	if res:
		print "WIN"
	else:
		print "LOSE"
	t -= 1