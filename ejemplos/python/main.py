import ctypes

sha1lib = ctypes.CDLL("../../libsha1.so")

input = b"Hola Mundo!"
sha1lib.sha1_hash.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
output = ctypes.create_string_buffer(40 + 1)

sha1lib.sha1_hash(input, output)
input = input.decode("utf-8")
output = output.value.decode("utf-8")

print(f"String: {str(input)}")
print(f"SHA-1 hash: {output}")
