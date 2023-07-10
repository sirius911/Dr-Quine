from subprocess import call
"""
    comment
"""

def main():
  i = 5
  j = i - 1

  str = 'from subprocess import call\n"""\n    comment\n"""\n\ndef main():\n  i = %d\n  j = i - 1\n\n  str = %r\n  with open("Sully_%%d.py" %% i, "w") as f:\n    f.write(str %% (j, str))\n  if i > 0:\n      call(["python3", "Sully_%%d.py" %% i])\n\nmain()'
  with open("Sully_%d.py" % i, "w") as f:
    f.write(str % (j, str))
  if i > 0:
      call(["python3", "Sully_%d.py" % i])

main()