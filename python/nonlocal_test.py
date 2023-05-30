

a = 10  # a1 当前模块全局变量
def outer2():
    a = 9 # a2 outer2作用域局部变量
    print(a) # a2 9,还未被a3改变
    def outer1():
        print(a) # a2 9,在outer1中没找到局部变量a，则寻找外层(outer2)变量a2(还未被a3改变)
        def inner():
            nonlocal a
            a = 0  # a3 既是inner局部变量，又是再外层outer2作用域变量
            print(a)  # a3 0, 找到inner局部变量a3
        inner()  # inner()函数结束，a3作为外层变量(outer2局部变量)被保留成为a2
        print(a)  # a2 0,在outer1中没找到局部变量a，则寻找外层(outer2)变量a2(被a3改变)
    outer1()
    print(a) # a2 0, 在outer1中找到outer1局部变量a2(被a3改变)
outer2()
print(a)  # a1 10，在当前模块全局作用域中找到了a1

# https://cloud.tencent.com/developer/article/2133304

from functools import cache

@cache
def fib(n):
    print('fib', n)
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)
fib(20)
print('-' * 100)
fib(12)  # 上一步计算20时已经计算过了，这里只是查找记录
print('-' * 100)
fib.cache_clear()  # 清除缓存，这里只是看看效果，实际使用时一般不会用到
fib(12)  # 已清楚缓存，从新计算

'''
output:
fib 20
fib 19
fib 18
fib 17
fib 16
fib 15
fib 14
fib 13
fib 12
fib 11
fib 10
fib 9
fib 8
fib 7
fib 6
fib 5
fib 4
fib 3
fib 2
fib 1
fib 0
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
fib 12
fib 11
fib 10
fib 9
fib 8
fib 7
fib 6
fib 5
fib 4
fib 3
fib 2
fib 1
fib 0
'''
