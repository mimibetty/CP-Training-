def compress_string(s):
    n = len(s)
    
    # Function to find the longest repeated substring
    def find_repeated_substring(s):
        length = len(s)
        for size in range(length // 2, 0, -1):
            for i in range(length - size):
                substring = s[i:i+size]
                count = s.count(substring, i)
                if count > 1:
                    return substring, count
        return None, 0
    
    # Main compression logic
    def compress(s):
        if len(s) <= 1:
            return s
        
        substring, count = find_repeated_substring(s)
        
        if count > 1:
            compressed_part = f"{count}({substring})"
            s = s.replace(substring * count, compressed_part, 1)
            return compress(s)
        else:
            return s
    
    return compress(s)

# Example usage
input_string = "abababaaaaa"
output = compress_string(input_string)
print(output)  # Output should be "2(3(ab)c5(a))"