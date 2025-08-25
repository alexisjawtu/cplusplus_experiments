def mean():
    total = 0
    length = 0
    def _mean(nr):
        nonlocal total, length
        total += nr
        length += 1
        return total / length
    return _mean


current_mean = mean()

print(current_mean(3))
print(current_mean(4))
print(current_mean(5))
print(current_mean(6))
print(current_mean(7))
print(current_mean(8))
