"""
ID: 06jajun
LANG: PYTHON3
TASK: rental
"""
# * ->
from collections import deque


def main():
    fin = open ('rental.in', 'r')
    fout = open ('rental.out', 'w')

    n, m, r = [int(c) for c in fin.readline().split()]
    ans = 0
    cow_outputs = []
    for i in range(n):
        cow_outputs.append(int(fin.readline()))
    cow_outputs.sort()
    cow_outputs.reverse()
    cow_outputs = deque(cow_outputs)
    buyer_offers = []
    for i in range(m):
        buyer_offers.append(list(reversed([int(c) for c in fin.readline().split()])))
    # buyer_offers.append([0, 0])
    buyer_offers.sort()
    rental_offers = []
    for i in range(r):
        rental_offers.append(int(fin.readline()))
    # rental_offers.append(0)
    rental_offers.sort()
    b_val = -1
    r_val = rental_offers[-1]
    while cow_outputs and (b_val or r_val):
        # print(buyer_offers)
        if b_val == -1:
            curr = cow_outputs[0]
            tot = 0
            i = len(buyer_offers) - 1
            while curr and i >= 0:
                tot += buyer_offers[i][0] * min(curr, buyer_offers[i][1])
                curr -= min(curr, buyer_offers[i][1])
                i -= 1
            b_val = tot
        # print('-', b_val, r_val)
        if b_val >= r_val:
            ans += b_val
            curr = cow_outputs[0]
            while b_val:
                # print(b_val, curr, buyer_offers)
                if curr >= buyer_offers[-1][1]:
                    b_val -= buyer_offers[-1][0] * buyer_offers[-1][1]
                    curr -= buyer_offers[-1][1]
                    buyer_offers.pop()
                else:
                    b_val -= buyer_offers[-1][0] * curr
                    buyer_offers[-1][1] -= curr
            b_val -= 1
            # print(b_val)
            cow_outputs.popleft()
        else:
            ans += r_val
            cow_outputs.pop()
            rental_offers.pop()
            if rental_offers:
                r_val = rental_offers[-1]
            else:
                r_val = 0
        # print(ans)
    fout.write(str(ans))
    fout.write('\n')
    fout.close()


if __name__ == '__main__':
    main()
