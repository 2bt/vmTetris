#!/usr/bin/python


import sys


defines = {}


def apply_defs(o):
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


R = ["r%s" % x for x in "01234567"] + ["[r%s]" % x for x in "01234567"]


bin_ops = "add", "sub", "mul"
inc_ops = "inc", "dec"
jmp_ops = "jmp", "jz", "jnz"


counter		= 0
bin_cmds	= []
txt_cmds	= []
labels		= {}


for l in sys.stdin:

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
		assert w[1].isalnum()
		defines[w[1]] = w[2]
		continue

	op = w[0]
	if op == "mov":
		a = R.index(apply_defs(w[1]))
		b = apply_defs(w[2])
		if b.isdigit():
			c = num_to_code(int(b))
			bin_cmd = [ len(c), a ] + c
		else:
			bin_cmd = [ 4, a, R.index(b) ]
	elif op in bin_ops: bin_cmd = [ bin_ops.index(op) + 5, R.index(apply_defs(w[1])), R.index(apply_defs(w[2])) ]
	elif op in inc_ops: bin_cmd = [ inc_ops.index(op) + 8, R.index(apply_defs(w[1])) ]
	elif op in jmp_ops: bin_cmd = [ jmp_ops.index(op) + 10, 0, 0, w[1] ]
	elif op == "get": bin_cmd = [ 13, R.index(apply_defs(w[1])) ]
	elif op == "put": bin_cmd = [ 14 ]
	elif op == "slp": bin_cmd = [ 15 ]
	else:
		bin_cmd = []
		print "WOOT"

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
	x = x | out.pop(0) * 16
	code += chr(x)

file("code", "w").write(code)
