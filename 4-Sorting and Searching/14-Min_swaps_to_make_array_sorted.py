def minSwaps(arr):
    ans = 0
    n=len(arr)
    temp = arr.copy()
    h = {}
    temp.sort()
    for i in range(n):
        h[arr[i]] = i
    init = 0
        
    for i in range(n):
        if (arr[i] != temp[i]):
            ans += 1
            init = arr[i]
            arr[i], arr[h[temp[i]]] = arr[h[temp[i]]], arr[i]
            h[init] = h[temp[i]]
            h[temp[i]] = i
            
    return ans
arr=[2, 8, 5, 4]
print(minSwaps(arr))
