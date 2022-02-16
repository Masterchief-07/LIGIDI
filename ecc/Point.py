class Point:
    def __init__(self, x, y, a, b):
        self.x, self.y, self.a, self.b = x, y, a, b 
        if self.y**2 != self.x**3 + self.a*self.x + self.b:
            raise ValueError('({}, {}) is not on the curve'.format(self.x, self.y))
    
    def __repr__(self) -> str:
        return 'Point({}, {})'.format(self.x, self.y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y and self.a == other.a and self.b == other.b
    
    def __ne__(self, other):
        return not (self == other)
    
    def __add__(self, other: object) -> object:
        if self.a != other.a and self.b != other.b:
            raise TypeError('({}, {}) are not on the same curve'.format(self, other))

        if self.x is None:
            return other
        if other.x is None:
            return self
        
        if self.x != other.x:
            s = (other.y - self.y) / (other.x - self.x)
            x = s**2 - self.x - other.x
            y = s*(self.x - x) - self.y
            return self.__class__(x, y, self.a, self.b)

        if self == other:
            s = (3*(self.x**2) + self.a) // (2*self.y)
            x = s**2 - 2*self.x
            y = s*(self.x - x) - self.y
            return self.__class__(x, y, self.a, self.b)

        if self == other and self.y == 0 * self.y:
            return self.__class__(None, None, self.a, self.b)
    
    def __mul__(self, other):
        
