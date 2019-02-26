import ctypes
import os
d = os.path.abspath(os.path.dirname(__file__))
d += "/libarr.so"
lib = ctypes.CDLL(d)

_prime_arr = lib.prime_arr
_prime_arr.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)

_copy_arr = lib.copy_arr
_copy_arr.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)

def prime_arr(nums):
	src_len = len(nums)
	src = (ctypes.c_int * src_len)(*nums)
	_prime_arr(src, src_len)
	return src

def copy_arr(nums, nums_res, k):
	src_len = len(nums)
	res_len = len(nums_res)
	n_res = (ctypes.c_int)(0)
	src = (ctypes.c_int * src_len)(*nums)
	res = (ctypes.c_int * res_len)(*nums_res)
	_copy_arr(src, src_len, res, n_res, k)
	arr_res = []
	for i in range(n_res.value):
		arr_res.append(res[i])

	return arr_res

n = int(input("Input length of array 1: "))
arr1 = [0] * n
arr1 = list(prime_arr(arr1))
print("Array full of simple numbers: ")
print(arr1)

arr2 = list(map(int, input("Input array 2(with spaces): ").split()))
k = int(input("Input k: "))
arr3 = [0] * 2 * len(arr2)
arr3 = copy_arr(arr2, arr3, k)
print(list(arr3))