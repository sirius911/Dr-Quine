#comment outside

def write(x):
    print(x % x)

def main():
  #comment in main
  x = '#comment outside\n\ndef write(x):\n    print(x %% x)\n\ndef main():\n  #comment in main\n  x = %r\n  write(x)\n\nmain()'
  write(x)

main()
