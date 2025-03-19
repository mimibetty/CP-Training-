from itertools import product

def evaluate_expression(s, ops):
    expression = []
    for i, op in enumerate(ops):
        expression.append(s[i])
        expression.append(op)
    expression.append(s[-1])
    
    # Join to form the expression string
    expr_str = ''.join(expression)
    
    # Evaluate the expression with precedence rules
    return eval(expr_str)

def find_minimum_result(n, s):
    if n == 2:
        return int(s)
    
    operators = ['+', '*']
    min_result = float('inf')
    
    # Generate all combinations of n-2 operators (+ or *)
    for ops in product(operators, repeat=n-2):
        result = evaluate_expression(s, ops)
        min_result = min(min_result, result)
    
    return min_result

def main():
    import sys
    sys.stdin = open("input.txt", "r")
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        s = data[index + 1]
        index += 2
        
        result = find_minimum_result(n, s)
        results.append(result)
    
    for result in results:
        print(result)


if __name__ == "__main__":
    main()