
'''
题目：
def func():
    pass

if __name__ == '__main__':
    pass


一组任务，每个任务需要时间T完成，相同任务不能相连完成，问最短需要多长时间？
如：
任务为[A、A、A、B、C]，则结果为[A、B、A、空闲、A]，需要5个单位时间



A : 3
B : 1
C : 1
A、B、A、C、A

A B
B A 空闲 A 空闲 A

A B A

'''

def array_sort(tasks):
    cnts = {}
    for task in tasks:
        if task not in cnts:
            cnts[task] = 1
        else:
            cnts[task] += 1
    # 降序排序
    sorted(cnts.items(), key=lambda x: x[1], reverse=True)
    n = len(tasks)
    ans = []
    while len(cnts) > 0:
        # 1.取数量最多的任务 task_i
        k = 0
        task_i = list(cnts)[k]
        if len(ans) == 0:
            ans.append(task_i)
            cnts[task_i] -= 1
        else:
            # 2.判断 ans[-1] == task_i, 选满足条件的第k多的任务
            # print(k, cnts,ans)
            while ans[-1] == task_i and k < len(cnts):
                task_i = list(cnts)[k]
                k += 1
            # print(ans, cnts)
            if ans[-1] == task_i:
                ans.append('空闲')
            else:
                ans.append(task_i)
                # 4. 把选中的任务k的数量减一
                cnts[task_i] -= 1
        # 5. 如果第k个任务的数量为零， del cnts[k]
        if cnts[task_i] == 0:
            del cnts[task_i]
        # 6. 如果字典大小为空
        if len(cnts) == 0:
            break
        # 7. 对字典进行重新排序
        sorted(cnts.items(), key=lambda x: x[1], reverse=True)
    print(ans)
    return len(ans)

tasks = ['A','A','A','B']
ans1 = array_sort(tasks)
print(ans1)
tasks = ['A','A','A','B','B','B','C','C']
ans1 = array_sort(tasks)
print(ans1)
tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"]
ans1 = array_sort(tasks)
print(ans1)

'''
输入：
['A','A','A','B']
['A','A','A','B','B','B','C','C']
输出：
['A', 'B', 'A', '空闲', 'A']
5
['A', 'B', 'A', 'B', 'A', 'B', 'C', '空闲', 'C']
9
'''


