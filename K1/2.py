def multiplication_table(n): # a)
    table = []
    for i in range(1, n):
        rows = []
        for j in range(1, n):
            rows.append((i*j)%n)
        table.append(rows)
    return table

def rows_output(row, row_num):
    str = "{:<8}".format(row_num)
    for i in row:
        str += "{:<8}".format(i)
    return str

def output(n):
    table = multiplication_table(n)
    for i in range(len(table)):
        print(rows_output(table[i], i + 1))
    return table

def inverse_table(table):
    tab = []
    for i in range(len(table)):
        for j in range(len(table)):
            if table[i][j] == 1:
                tab.append((i+1, j+1))
    return tab

def brute_force_inverse(a, b):
    for n in range(b):
        if(a*n)%b == 1:
            return n
    return None

if __name__ == "__main__":
    print("\n\nTask a:")
    table = output(12)

    print("\n\nTask b:")
    print(f"Multiplicative inverse entries: {inverse_table(table)}")

    print("\n\nTask c:")
    table = output(11)
    print("")
    print(f"Multiplicative inverse entries for Z11: {inverse_table(table)}")

    print("\n\nTask d:")
    a = 11
    b = 29
    print(f"The multiplicative inverse of 11 mod(29) is: {brute_force_inverse(a, b)}")