'''
加油站

'''

class Solution:

    # 遍历每个点作为起点
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)

        i = 0
        while i < n:
            sum_gas = 0
            sum_cost = 0
            cnt = 0
            while cnt < n:
                j = (i+cnt)%n
                sum_gas += gas[j]
                sum_cost += cost[j]
                if sum_cost > sum_gas:
                    break
                cnt += 1
            if cnt == n:
                return i
            else:
                i = i+cnt+1
        return -1


    # 一次遍历
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        acc_gas = 0
        acc_cost = 0
        start = 0
        n = len(gas)
        for i in range(n):
            # 这个为什么累计量
            acc_gas += gas[i]
            acc_cost += cost[i]
            if acc_gas < acc_cost:
                start = i + 1
                acc_gas = 0
                acc_cost = 0
        return -1 if acc_gas < acc_cost else start

    # 我的解答
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        start_list = []
        for i in range(n):
            diff = gas[i] - cost[i]
            if diff >= 0:
                start_list.append(i)
        # 最容易想到的解法是：从头到尾遍历每个加油站，并检查以该加油站为起点，最终能否行驶一周
        for start in start_list:
            k = 0
            left = 0
            for i in range(n):
                left += + gas[(start + n) % n] - cost[(start + n) % n]
                # print((start+n)%n,left)
                if left >= 0:
                    start = (start + 1) % n
                    k += 1

            if k == n:
                return start
        return -1

'''
51min
需要二刷
'''