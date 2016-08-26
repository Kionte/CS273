#Part 1
nums = [1,2,3,4,5,6]
oddNums = [x for x in nums if x % 2 == 1]
if oddNums > 5:
    print oddNums.lower()
else:
    print oddNums
oddNumsPlusOne = [x+1 for x in nums if x % 2 ==1]
if oddNums > 5:
    print oddNums.lower()
else:
    print oddNums

#part 2
nums = [x.lower() if x > 5 else x.upper() for x in nums]
print nums 
