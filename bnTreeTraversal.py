class Node:
    #节点类
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None
class Tree:
    #树类
    def __init__(self):
        self.root = None

    def add(self, data):
        # 为树加入节点
        node  = Node(data)
        if self.root is None:      #如果树为空，就对根节点赋值
            self.root = node
        else:
            myQueue = []
            treeNode = self.root
            myQueue.append(treeNode)
            while myQueue:              #对已有的节点进行层次遍历
                treeNode = myQueue.pop(0)
                if not treeNode.left:
                    treeNode.left = node
                    node.parent = treeNode
                    return
                elif not treeNode.right:
                    treeNode.right = node
                    node.parent = treeNode
                    return
                else:
                    myQueue.append(treeNode.left)
                    myQueue.append(treeNode.right)

########################## 前序遍历 #######################
#递归实现 前序遍历
def pre_order_recursion(root):
    if root is None:
        return
    print(root.data)
    pre_order_recursion(root.left)
    pre_order_recursion(root.right)

#迭代实现 前序遍历
def pre_order_iterative(root):
    stack = []
    if root is not None:
        stack.append(root)

    while stack:
        node = stack.pop()
        print(node.data)
        if node.right is not None:
            stack.append(node.right)
        if node.left is not None:
            stack.append(node.left)

########################## 中序遍历 #######################
#递归实现 中序遍历
def in_order_recursion(root):
    if root is None:
        return
    in_order_recursion(root.left)
    print(root.data)
    in_order_recursion(root.right)

#迭代实现 中序遍历
def in_order_iterative(root):
    stack = []
    def goAlongLeftBranch(root, stack):
        while root is not None:
            stack.append(root)
            root = root.left

    node = root
    # while True:
    #     goAlongLeftBranch(node, stack)
    #     if not stack:
    #         break
    #     node = stack.pop()
    #     print(node.data)
    #     node = node.right
    goAlongLeftBranch(node, stack)
    while stack:
        node = stack.pop()
        print(node.data)
        goAlongLeftBranch(node.right)

########################## 后序遍历 #######################
#递归实现 后序遍历
def post_order_recursion(root):
    if root is None:
        return
    post_order_recursion(root.left)
    post_order_recursion(root.right)
    print(root.data)


#迭代实现 后序遍历
def post_order_iterative(root):
    stack = []
    def gotoHLVFL(s):
        '''
        在以S栈顶节点为根的子树中，找到最高左侧可见叶节点,
        沿递所遇节点依次入栈
        '''
        node = s[-1]
        while node is not None:            # 自顶而下，反复检查当前节点（即栈顶)
            if node.left is not None:      # 尽可能向左
                if node.right is not None: # 若有右孩子，优先入栈
                    s.append(node.right)
                s.append(node.left)        # 然后才转至左孩子
                node = s[-1]
            else:
                s.append(node.right)       # 不得已, 才向右
                node = s[-1]
        s.pop()                             # 返回之前，弹出栈顶空节点

    if root is not None:
        stack.append(root)

    while stack:
        if stack[-1] != root.parent:
            # 若栈顶非当前节点之父（则必为其右兄），此时需
            # 在以其右兄为根的子树中，找到HLVFL
            gotoHLVFL(stack)
        root = stack.pop()
        print(root.data)



########################## 层次遍历 #######################
#队列实现层次遍历（非递归）
def level_order_iterative(root):
        if root is None:
            return
        queue = []
        node = root
        queue.append(node)
        while queue:
            node = queue.pop(0)
            print(node.data)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

#########################################################
if __name__ == '__main__':
    #主函数
    datas = list('ABCDE')
    tree = Tree()          #新建一个树对象
    for data in datas:
        tree.add(data)      #逐个加入树的节点
    '''
    PRE-ORDER:      A B D E C
    IN-ORDER:       D B E A C
    POST-ORDER:     D E B C A
    LEVEL-ORDER:    A B C D E
    '''
    print('递归实现前序遍历：')
    pre_order_recursion(tree.root)

    print('\n堆栈实现前序遍历')
    pre_order_iterative(tree.root)

    print("\n\n递归实现中序遍历：")
    in_order_recursion(tree.root)

    print("\n堆栈实现中序遍历：")
    in_order_iterative(tree.root)

    print('\n\n递归实现后序遍历：')
    post_order_recursion(tree.root)

    print('\n堆栈实现后序遍历：')
    post_order_iterative(tree.root)

    print('\n\n队列实现层次遍历：')
    level_order_iterative(tree.root)




