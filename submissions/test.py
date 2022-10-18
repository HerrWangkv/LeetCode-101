class A:
    def __init__(self, x):
        self.x = x
    
    def __add__(self, other):
        return A(self.x + other.x)
    def __str__(self):
        return str(self.x)
a = A(5)
b = A(6)
print(a+b)