t = int(input())
for _ in range(t):
    n, p, L, t = map(int, input().split())
    
    left_bound = 0
    right_bound = n
    
    while right_bound - left_bound > 1:
        mid = (right_bound + left_bound) // 2
        total_time = mid * L
        extra_time = min(mid * 2, (n + 6) // 7) * t
        total_time += extra_time
        
        if total_time < p:
            left_bound = mid
        else:
            right_bound = mid
            
    print(n - right_bound)
