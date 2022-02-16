class FieldElement:
    def __init__(self, num, prime):
        if num>=prime or num < 0:
            error = "Num {} not in the field range 0 to {}".format(num, prime-1)
            raise ValueError(error)
        self.num = num
        self.prime = prime
    
    def __repr__(self) -> str:
        return 'fieldElement_{}({})'.format(self.prime, self.num)
    
    def __eq__(self, other: object) -> bool:
        if other is None: return False
        return self.num == other.num and self.prime == other.prime
    
    def __ne__(self, other: object) -> bool:
        return not(self == other)
    
    def __add__(self, other: object) -> object:
        if self.prime != other.prime: raise TypeError("prime num a different")
        return FieldElement((self.num+other.num)%self.prime, self.prime)
    
    def __sub__(self, other: object) -> object:
        if self.prime != other.prime: raise TypeError("prime num a different")
        return FieldElement((self.num-other.num)%self.prime, self.prime)
    
    def __mul__(self, other: object) -> object:
        if self.prime != other.prime: raise TypeError("prime num a different")
        return FieldElement((self.num*other.num)%self.prime, self.prime)
    
    def __pow__(self, exponent) -> object:
        n = exponent % (self.prime - 1)
        num = pow(self.num, n, self.prime)
        return FieldElement(num, self.prime)

    def __neg__(self) -> object:
        return FieldElement((-self.num)%self.prime, self.prime)
    
    def __truediv__(self, other):
        if self.prime != other.prime:
            raise TypeError('Cannot divide two numbers in different Fields')
        # use fermat's little theorem:
        # self.num**(p-1) % p == 1
        # this means:
        # 1/n == pow(n, p-2, p)
        # We return an element of the same class
        p = self * other**-1
        return p