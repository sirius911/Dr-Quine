"""
    comment outside
"""

def write(x):
    print(x % x)

def main():
  """
    comment inside
  """
  x = '"""\n    comment outside\n"""\n\ndef write(x):\n    print(x %% x)\n\ndef main():\n  """\n    comment inside\n  """\n  x = %r\n  write(x)\n\nmain()'
  write(x)

main()
