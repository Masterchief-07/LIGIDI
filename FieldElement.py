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
    
    def __pow__(self, other: object) -> object:
        if self.prime != other.prime: raise TypeError("prime num a different")
        return FieldElement((self.num**other.num)%self.prime, self.prime)

    def __neg__(self) -> object:
        return FieldElement((-self.num)%self.prime, self.prime)
    

    
a = FieldElement(7,13)
b = FieldElement(6,13)
c = a+b
d = a-b
print(a==b)
print(a!=b)
print(a==a)

print(c)
print(-c)
print(d)
print(-d)

print(FieldElement(44, 57) + FieldElement(33, 57))
print(FieldElement(9, 57) - FieldElement(29, 57))

print(FieldElement(17, 57) + FieldElement(42, 57) + FieldElement(49, 57))
print(FieldElement(52, 57) - FieldElement(30, 57) - FieldElement(38, 57))

print(FieldElement(95, 97) * FieldElement(45, 97) * FieldElement(31, 97))
print(FieldElement(17, 97) * FieldElement(13, 97) * FieldElement(19, 97) * FieldElement(44, 97))
print(FieldElement(12, 97) ** FieldElement(77, 97))
