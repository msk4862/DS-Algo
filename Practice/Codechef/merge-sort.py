
def merge(ar, l, m, r):
    L,R =[],[]
    for x in range(l,m+1):
        L.append(ar[x])
    for x in range(m+1, r+1):
        R.append(ar[x])
    
    n1 = len(L)
    n2= len(R)

    i, j, k = 0, 0 , l
    while i<=n1-1 and j<=n2-1:
        if L[i] >= R[j]:
            ar[k] = L[i]
            i += 1
        else:
            ar[k] = R[j]
            j += 1
        k += 1
    
    while i < n1:
        ar[k] = L[i]
        k += 1
        i += 1
    while j < n2:
        ar[k] = R[j]
        k += 1
        j += 1
    
    
def mergeSort(ar, l, r):
    if l < r:
        mid = l + (r-l)//2
        (mergeSort(ar, l, mid))
        (mergeSort(ar, mid+1, r))
        merge(ar, l, mid, r)

n = int(input())
ar = []
for _ in range(n):
    ar.append(int(input()))
mergeSort(ar, 0, len(ar)-1)
for x in ar:
    print(x)