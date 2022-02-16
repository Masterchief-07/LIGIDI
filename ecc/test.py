from Point import Point
from FieldElement import FieldElement
from unittest import TestCase

from unittest import TestSuite, TextTestRunner
def run(test):
    suite = TestSuite()
    suite.addTest(test)
    TextTestRunner().run(suite)



class ECCTest(TestCase):
    def test_on_curve(self):
        prime = 223
        a = FieldElement(0, prime)
        b = FieldElement(7, prime)
        valid_points = ((192, 105), (17,56), (1,193))
        invalid_points = ((200, 119), (42, 99))
        for x_raw, y_raw in valid_points:
            x = FieldElement(x_raw, prime)
            y = FieldElement(y_raw, prime)
            Point(x, y, a, b)
        for x_raw, y_raw in invalid_points:
            x = FieldElement(x_raw, prime)
            y = FieldElement(y_raw, prime)
            with self.assertRaises(ValueError):
                Point(x, y, a, b)

    def test_add(self):
        prime = 223
        a = FieldElement(0, prime)
        b = FieldElement(7, prime)
        points = ((170, 142, 60, 139), (17,56, 1,193, ))
        for x_raw, y_raw, x2_raw, y2_raw in points:
            x = FieldElement(x_raw, prime)
            y = FieldElement(y_raw, prime)
            x2 = FieldElement(x2_raw, prime)
            y2 = FieldElement(y2_raw, prime)
            p1 = Point(x, y, a, b)
            p2 = Point(x2, y2, a, b)
            print(p1+p2)

run(ECCTest('test_on_curve'))
run(ECCTest('test_add'))

#scalar multiplication
prime = 223
a = FieldElement(0, prime)
b = FieldElement(7, prime)
x = FieldElement(47, prime)
y = FieldElement(71, prime)
p = Point(x, y, a, b)
for s in range(1, 21):
    result = s*p
    print('{} * (47, 71) = ({}, {})'.format(s, result.x.num, result.y.num))