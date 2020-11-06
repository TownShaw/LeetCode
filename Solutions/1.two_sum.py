class Solution:
    def __init__(self):
        pass
    def twoSum(self, nums, target: int):
        num_dict = {}
        for i, num in enumerate(nums):  #建立字典
            if str(num) in num_dict.keys():
                num_dict[str(num)].append(i)
            else:
                num_dict[str(num)] = [i]
        for key in num_dict.keys():
            try:
                if int(key) * 2 == target:
                    if len(num_dict[key]) == 2:
                        return num_dict[key]
                    else:
                        pass
                else:
                    index_1 = num_dict[key]
                    index_2 = num_dict[str(target - int(key))]
                return index_1 + index_2
            except:
                pass
        return None

input_list = [3, 3]
solution = Solution()
answer = solution.twoSum(input_list, 6)
print(answer)