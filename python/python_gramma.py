'''
1.python基础语法
    1.基本数据类型
        int
        float
        str
        tuple(不可变类型)
    2.引用数据类型
        list
        set
        dict
            底层是hash表来关联Key和value,字典数据是无序，查找和插入速度极快
            （1）创建dict
                a = dict() 或者 a = {}
            (2) 插入一个字段
                a[key] = value, 其中，key是不可变数据类型
            (3) 访问
                通过[]
                遍历 items() 同时获取k,v。 .keys() 获取所有的key, .values() 获取所有的value
                for key,val in d_list:
                    print(key,val)
            (4) 删除key-value
                del a[key]  如果key不存在，将报告KeyError的错误
                a.pop(key) 没有返回值，key不存在的话就不会出错
                用popitem方法删除字典中的最后一个键
                注意，不能一边遍历一边删除！！

                dict_demo10 = {'name': '码农飞哥', 'age': 18, 'height': 185, 'width': 100}
                # 删除键值对
                del dict_demo6['height']
                print('删除键height对之后的结果=', dict_demo6)
                # pop()方法和popitem()方法
                dict_demo10.pop('width')
                print('pop方法调用删除键width之后结果=', dict_demo10)
                dict_demo10 = {'name': '码农飞哥', 'age': 18, 'height': 185, 'width': 100}
                dict_demo10.popitem()
                print('popitem方法调用之后结果=', dict_demo10)

            (5) 修改 a[key] = value1
            (6) 判断key是否存在，用in 或者not in运算符
            (7) 列表与字典的转化
                dict3=dict([[1,"a"],[2,"c"],[3,"c"]]) -> {1: 'a', 2: 'c', 3: 'c'}
                列表与元组的转换
                dict4=dict(((1,"a"),(2,"b"),(3,"c")))
                list(dict3)
            (8) 排序
                按key排序 sorted(d.items(), key=lambda x:x[0], reverse=True), reverse=True降序
                按值排序 sorted(d.items(), key=lambda x:x[1], reverse=True), reverse=False升序
                例如：
                d = {"a":1 , "b":3, "c":2}
                d1 = sorted(d.items(), key=lambda x:x[0], reverse=True) #按值降序排列
                d2 = dict([('a', 1), ('c', 2), ('b', 3)])
                d2   {'a': 1, 'c': 2, 'b': 3}

    3.容器的增删改查接口
        list
        dict/defaultdict
        set
            s.add(x)
        stack
            a = [1,2,3,4,5]
            出栈：a.pop()
            入栈：a.append()
        deque
            a = [1,2,3,4,5]
            出队：a.pop(0)
            入队：a.append(6)
        heap
            import heapq
            主要操作，
                (1)入堆 a = []，默认是小顶堆, heapq.heappush(a,1),heapq.heappush(a,2),heapq.heappush(a,3)
                    建立大根堆
                    a = []
                    for i in [1, 5, 20, 18, 10, 200]:
                        heapq.heappush(a,-i)  #每次push时给元素加一个负号使得之前的最大值变成最小值(默认小根堆），取堆顶元素时使用-i
                    print(list(map(lambda x:-x,a)))
                (2)获取堆顶元素并出堆，x = heapq.heappop(a);  1
                (3)调整堆 a = [1, 5, 20, 18, 10, 200], 将a转化为小根堆顶，heapq.heapify(a)
        Counter
    4. 函数
        内置函数
            双下滑线
        匿名函数lambda
        map
        filter
2.numpy的使用接口

3.基础算法总结

4.数学总结

5.leetcode总结

6.linux命令

7.git使用

8.项目总结

9.把最近的东西先总结一遍， 用markdown形式总结记录
'''