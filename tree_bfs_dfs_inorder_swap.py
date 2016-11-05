'''
Swap operation: Given a tree and a integer, K, we have to swap the subtrees of all the nodes who are at depth h, where h ∈ [K, 2K, 3K,...].

You are given a tree of N nodes where nodes are indexed from [1..N] and it is rooted at 1. You have to perform T swap operations on it, and after each swap operation print the inorder traversal of the current state of the tree.

Input Format 
First line of input contains N, number of nodes in tree. Then N lines follow. Here each of ith line (1 <= i <= N) contains two integers, a b, where a is the index of left child, and b is the index of right child of ith node. -1 is used to represent null node. 
Next line contain an integer, T. Then again T lines follows. Each of these line contains an integer K.

Output Format 
For each K, perform swap operation as mentioned above and print the inorder traversal of the current state of tree.

Constraints 
1 <= N <= 1024 
1 <= T <= 100 
1 <= K <= N 
Either a = -1 or 2 <= a <= N 
Either b = -1 or 2 <= b <= N 
Index of (non-null) child will always be greater than that of parent.

Sample Input #00

3
2 3
-1 -1
-1 -1
2
1
1
Sample Output #00

3 1 2
2 1 3
Sample Input #01

5
2 3
-1 4
-1 5
-1 -1
-1 -1
1
2
Sample Output #01

4 2 1 5 3
Sample Input #02

11
2 3
4 -1
5 -1
6 -1
7 8
-1 9
-1 -1
10 11
-1 -1
-1 -1
-1 -1
2
2
4
Sample Output #02

2 9 6 4 1 3 7 5 11 8 10
2 6 9 4 1 3 7 5 10 8 11
Explanation

**[s] represents swap operation is done at this depth.

Test Case #00: As node 2 and 3 has no child, swapping will not have any effect on it. We only have to swap the child nodes of root node.

    1   [s]       1    [s]       1   
   / \      ->   / \        ->  / \  
  2   3 [s]     3   2  [s]     2   3
Test Case #01: Swapping child nodes of node 2 and 3 we get

    1                  1  
   / \                / \ 
  2   3   [s]  ->    2   3
   \   \            /   / 
    4   5          4   5  
Test Case #02: Here we perform swap operations at the nodes whose depth is either 2 and 4 and then at nodes whose depth is 4.

         1                     1                          1             
        / \                   / \                        / \            
       /   \                 /   \                      /   \           
      2     3    [s]        2     3                    2     3          
     /      /                \     \                    \     \         
    /      /                  \     \                    \     \        
   4      5          ->        4     5          ->        4     5       
  /      / \                  /     / \                  /     / \      
 /      /   \                /     /   \                /     /   \     
6      7     8   [s]        6     7     8   [s]        6     7     8
 \          / \            /           / \              \         / \   
  \        /   \          /           /   \              \       /   \  
   9      10   11        9           11   10              9     10   11 
'''

import sys

sys.setrecursionlimit(15000)

class Node:
    def __init__(self, index = 1, left = -1, right = -1):
        self.index = index
        self.left = left
        self.right = right

def traverseAndSwap(node, curlevel, level):
    if(curlevel % level is 0):
        temp = node.left
        node.left = node.right
        node.right = temp
    if(node.left is not -1):
        traverseAndSwap(node.left, curlevel+1, level)
    if(node.right is not -1):
        traverseAndSwap(node.right, curlevel+1, level)

def inorder(root):
    if root is -1:
        return
    inorder(root.left)
    print(root.index, end=' ')
    inorder(root.right)
    
def main():
    #read number of nodes and create root node
    nodes = int(input().strip())
    #print(nodes)
    root = Node()
    queue = [root]
    
    #create tree
    for n in range(nodes):
        left, right = map(int, input().strip().split(' '))
        #print(left,right)
        cur = None
        if len(queue):
            cur = queue[0]
            del queue[0]
        if left is not -1:
            cur.left = Node(left)
            queue.append(cur.left)
        if right is not -1:
            cur.right = Node(right)
            queue.append(cur.right)
    
    #read number of swaps
    swaps = int(input().strip())
    
    #inorder(root)
    for s in range(swaps):
        level = int(input().strip())
        traverseAndSwap(root, 1, level)
        inorder(root)
        print()
    
if __name__ == '__main__':
    main()
    