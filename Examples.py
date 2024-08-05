from Matrix import Matrix

# m1 = Matrix([2, 2, 2])
# m1.fill([5, 6, 7, 8, 1, 2, 3, 4])
# m1.print()

# try:
#     m1 = Matrix([2, 2, 2])
#     m1.fill([5, 6, 7, 8, 1, 2, 3])
#     m1.print()
# except Exception as e:
#     print( e )


# m2 = Matrix([2, 4])
# m2.fill([5, 6, 7, 8, 1, 2, 3, 4])
# m2.print()

m1 = Matrix([2, 2])
m1.fill([1, 2, 3, 4])
m2 = Matrix([2, 2])
m2.fill([5, 6, 7, 8])
m3 = m1 + m2
m1.print()
m2.print()
m3.print()