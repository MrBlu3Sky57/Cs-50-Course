
def search(k):
    n = [x for x in range(1, 101)]

    while(len(n) > 0):
        i = int(len(n)/2)
        print(i)
        print(n)
 
        if n[i] == k:
            print("Found")
            return
        elif n[i] > k:
            n = [x for x in range(n[0], n[i])]
         
        elif n[i] < k:
            n = [x for x in range(n[i + 1], n[-1] + 1)]
        else:
            print("Not Found")
            return
search(60)