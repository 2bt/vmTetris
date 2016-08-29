#!/usr/bin/python


import sys


defines = {}


def subst(o):
	while 1:
		if o in defines:
			o = defines[o]
			continue
		if o[0] == "[" and o[-1] == "]" and o[1:-1] in defines:
			o = "[" + defines[o[1:-1]] + "]"
			continue
		return o


def num_to_code(n):
	c = []
	while 1:
		c = [n % 16] + c
		n /= 16
		if n == 0: break
	return c


R = ["r%d" % x for x in range(8)]
R += ["[%s]" % r for r in R]


bin_ops = "add", "sub", "mul"
mon_ops = "inc", "dec"
jmp_ops = "jmp", "jz", "jnz"


counter		= 0
bin_cmds	= []
txt_cmds	= []
labels		= {}


for l in sys.stdin:
	print l[:-1]

	l = l.strip()
	c = l.find("#")
	if c >= 0: l = l[:c]
	if l == "": continue

	w = l.split()

	# label
	if w[0][-1] == ":":
		labels[w[0][:-1]] = counter
		w.pop(0)
		if not w: continue

	# define
	if w[0] == "define":
		assert w[1][0].isalnum()
		defines[w[1]] = w[2]
		continue

	op = w[0]
	if op == "mov":
		a = R.index(subst(w[1]))
		b = subst(w[2])
		if b.isdigit():
			c = num_to_code(int(b))
			assert len(c) < 3
			bin_cmd = [ len(c), a ] + c
		else:
			bin_cmd = [ 3, a, R.index(b) ]
	elif op in bin_ops: bin_cmd = [ bin_ops.index(op) + 4, R.index(subst(w[1])), R.index(subst(w[2])) ]
	elif op in mon_ops: bin_cmd = [ mon_ops.index(op) + 7, R.index(subst(w[1])) ]
	elif op in jmp_ops: bin_cmd = [ jmp_ops.index(op) + 9, 0, 0, w[1] ]
	elif op == "get": bin_cmd = [ 12, R.index(subst(w[1])) ]
	elif op == "put": bin_cmd = [ 13 ]
	elif op == "rnd": bin_cmd = [ 14 ]
	elif op == "slp": bin_cmd = [ 15 ]
	else:
		print "WOOT"
		bin_cmd = [ int(op) ]

	counter += len(bin_cmd)
	bin_cmds += [ bin_cmd ]
	txt_cmds += [ "%-20s" % " ".join("%-5s" % x for x in w) ]




# apply labels
counter = 0
out = []

for txt, c in zip(txt_cmds, bin_cmds):
	if c[-1] in labels:
		c = [c[0]] + ([0, 0, 0] + num_to_code(labels[c[-1]]))[-3:]

	print txt, "| %03x:" % counter, " ".join("%x" % c for c in c)
	counter += len(c)
	out += c


out += [0]
code = ""
while len(out) > 1:
	x = out.pop(0)

	# one nibble per byte for easy debugging
	x = x | out.pop(0) * 16
	code += chr(x)

file("code", "w").write(code)
