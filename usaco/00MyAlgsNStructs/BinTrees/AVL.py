from math import log


class AVL:
    def __init__(self, val, left=None, right=None, num=1):
        self.val = val
        self.left = left
        self.right = right
        self.num = num
        lefth = -1
        righth = -1
        if self.left: lefth = self.left.height
        if self.right: righth = self.right.height
        self.height = max(lefth, righth) + 1
        self.balance = lefth - righth
        assert self.height < 999, "it's too deep...that's what she said"


    def updateTree(self):
        lefth = -1
        righth = -1
        if self.left: lefth = self.left.height
        if self.right: righth = self.right.height
        self.height = max(lefth, righth) + 1
        self.balance = lefth - righth


    def replace(self, new, all=False):
        self.val, self.num = new.val, new.num
        if all:
            self.val, self.left, self.right, self.num, self.balance, self.height = new.val, new.left, new.right, new.num, new.balance, new.height


    def addNew(self, new):
        if self == None:
            self = AVL(new)
            return
        if self.val == new:
            self.num += 1
        elif self.val < new:
            if self.right == None:
                self.right = AVL(new)
            else:
                self.right.addNew(new)
        elif self.val > new:
            if self.left == None:
                self.left = AVL(new)
            else:
                self.left.addNew(new)
        self.updateTree()
        if self.balance not in [-1, 0, 1]:
            # root.printMe3()
            self.balanceTree()
        # if self == root: self.printMe3()


    def deleteOld(self, n, below=-1):
        curr, parent = self.find(n, below)
        print(curr.val, parent.val)
        self.printMe3()
        if curr == parent == None:
            return
        elif parent == None:
            if curr.num > 1:
                curr.num -= 1
                return
            elif curr.left == curr.right == None:
                curr = None
            elif curr.left == None:
                curr.replace(curr.right, True)
                return
            elif curr.right == None:
                curr.replace(curr.left, True)
                return
            else:
                new = curr.right
                while new.left != None:
                    new = new.left
                curr.replace(new)
                self.deleteOld(curr.val, below)
                return
        elif curr.num > 1:
            curr.num -= 1
            return
        elif curr.left == curr.right == None:
            if parent.left == curr:
                parent.left = None
            else:
                parent.right = None
            return
        elif curr.left == None:
            if parent.left == curr:
                parent.left = curr.right
            else:
                parent.right = curr.right
            to_check = parent
        elif curr.right == None:
            if parent.left == curr:
                parent.left = curr.left
            else:
                parent.right = curr.left
            to_check = parent
        else:
            new = curr.right
            while new.left != None:
                new = new.left
            curr.replace(new)
            self.deleteOld(curr.val, below)
            return
        to_check.updateTree()
        if to_check.balance not in [-1, 0, 1]:
            # root.printMe3()
            to_check.balanceTree()


    def find(self, n, below=-1, parent=None):
        works = None
        working_parent = None
        if self == None:
            print('e')
        elif self.val > n:
            if below == 1:
                works = self
                working_parent = parent
            if self.left:
                nworks, nworking_parent = self.left.find(n, below, self)
                if nworks:
                    works, working_parent = nworks, nworking_parent
        elif self.val == n:
            works = self
            working_parent = parent
            if self.right:
                nworks, nworking_parent = self.right.find(n, below, self)
                if nworks:
                    works, working_parent = nworks, nworking_parent
        elif self.val < n:
            if below == -1:
                works = self
                working_parent = parent
            if self.right:
                nworks, nworking_parent = self.right.find(n, below, self)
                if nworks:
                    works, working_parent = nworks, nworking_parent
        # if self == root and works and working_parent:
        #     print(works.val, working_parent.val)
        # print(works, working_parent)
        return works, working_parent


    def balanceTree(self):
        if self.balance < 0:
            if self.right.balance > 0:
                self.right.balanceRight()
                self.right.updateTree()
            self.balanceLeft()
        else:
            if self.left.balance < 0:
                self.left.balanceLeft()
                self.left.updateTree()
            self.balanceRight()
        self.updateTree()


    def balanceRight(self):
        copy = AVL(self.val, self.left, self.right)
        self.val, self.left, self.right, self.num = self.left.val, self.left.left, self.left.right, self.left.num
        copy.left = self.right
        self.right = copy
        copy.updateTree()
        self.right.updateTree()


    def balanceLeft(self):
        copy = AVL(self.val, self.left, self.right, self.num)
        self.val, self.left, self.right, self.num = self.right.val, self.right.left, self.right.right, self.right.num
        copy.right = self.left
        self.left = copy
        copy.updateTree()
        self.left.updateTree()


    def printMe(self):
        res = []
        if self.left:
            res += self.left.printMe()
        res.append(self.val)
        print(self.val, self.num, self.height, self.balance)
        if self.right:
            res += self.right.printMe()
        return res

    def printMe2(self):
        todo = [[self]]
        curr = []
        while curr != todo[-1]:
            curr = todo[-1]
            res = []
            t = 0
            for i in curr:
                if i == None or i == 'n':
                    res.append('n')
                    res.append('n')
                else:
                    if i.left:
                        res.append(i.left)
                        t = 1
                    else: res.append('n')
                    if i.right:
                        res.append(i.right)
                        t = 1
                    else: res.append('n')
            if t: todo.append(res)
        return [[n if n == 'n' else str(n.val) for n in arr] for arr in todo]

    def printMe3(self):
        # use = self.printMe2()
        # for i in range(1, len(use)):
        #     tp = " " * 2**i
        #     tp += (' ' * (2**(i + 1) - 1)).join(use[len(use) - i])
        #     print(tp)
        use = self.printMe2()
        for i in range(len(use) - 1, -1, -1):
            tp = " " * (2**(i + 1))
            other = " " * (2**(i + 1))
            s = 0
            sp = ['_', ' ']
            for ind, j in enumerate(use[len(use) - i - 1]):
                # power = 0
                # ind += 1
                # ind /= 2
                # while ind // 2 == ind / 2 != 0:
                #     power += 1
                # else: power = i
                if ind == len(use[len(use) - i - 1]) - 1:
                    tp += j
                    continue
                power = i
                # if len(tp) == len(other) and int(1 + log(int(j), 10)) == 3: other += ' '
                if j == 'n':
                    tp += j + ' ' * (2**(power + 2) - 1)
                    other += sp[s] * (2**(power + 2 + 1))
                else:
                    tp += j + ' ' * (2**(power + 2) - int(1 + log(int(j), 10)))
                    other += sp[s] * (2**(power + 2) - (2 * s - 1))
                s = (s + 1) % 2
            print(other)
            print(tp)
        print('-' * 50)
    # check in deleteOld and find methods for below variable

def main():
    nums = [4, 7, 2, 3, 5, 9, 10, 11, 12, 13]

    for i in range(1, 16):
        root.addNew(i)
    root.printMe3()
    root.deleteOld(10)
    root.printMe3()
    root.addNew(10)
    root.printMe3()
    root.deleteOld(9)
    root.printMe3()
    root.addNew(9)
    root.addNew(12)
    root.printMe3()
    root.deleteOld(12)
    root.printMe3()
    root.addNew(12)
    # for j in nums:
    #     root.addNew(j)
        # root.printMe3()
    print('-' * 50)
    root.printMe3()


if __name__ == '__main__':
    root = AVL(1)
    main()
