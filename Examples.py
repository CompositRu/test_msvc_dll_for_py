from Matrix import Matrix

# Exampe 1

try:
    m = Matrix([2, 2, 2])
    m.fill([1, 2, 3, 4, 5, 6, 7]) # need 8 values for 2x2x2 matrix
except Exception as e:
    print( e )

# Exampe 2

try:
    m1 = Matrix([2, 2])
    m1.fill([1, 2, 3, 4])

    m2 = Matrix([2, 2])
    m2.fill([5, 6, 7, 8])

    m3 = m1 + m2
    m3.print()
except Exception as e:
    print( e )

# Exampe 3

try:
    m1 = Matrix([3, 3])
    m1.fill([1, 2, 3, 4, 5, 6, 7, 8, 9])

    m2 = Matrix([3, 1])
    m2.fill([1, 2, 3])

    m3 = m1 * m2
    m3.print()
except Exception as e:
    print( e )