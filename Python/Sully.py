from subprocess import call
"""
    comment
"""

def main():
  i = 5
  j = i - 1
  if i < 0:
    return
  str = 'from subprocess import call\n"""\n    comment\n"""\n\ndef main():\n  i = %d\n  j = i - 1\n  if i < 0:\n    return\n  str = %r\n  with open("Sully_%%d.py" %% i, "w") as f:\n    f.write(str %% (j, str))\n  call(["python3", "Sully_%%d.py" %% i])\n\nmain()'
  with open("Sully_%d.py" % i, "w") as f:
    f.write(str % (j, str))
  call(["python3", "Sully_%d.py" % i])

main()