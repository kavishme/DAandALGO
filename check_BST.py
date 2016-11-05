# Enter your code here. Read input from STDIN. Print output to STDOUT
""" Node is defined as
class node:
  def __init__(self, data):
      self.data = data
      self.left = None
      self.right = None
"""
def check_binary_search_tree_(root):
    if root == None:
        return True
    
    # Set current to root of binary tree, Do inorder traversal of tree
    # Check for duplicates and sort order
    current = root 
    s = []
    done = False
    datalst = []
    maxval = -1
    while(not done):
         
        if current is not None:
            s.append(current)
            current = current.left 
        else:
            if(len(s) >0 ):
                current = s.pop()
                
                if current.data in datalst or current.data <= maxval:
                    return False
                else: 
                    maxval = current.data
                
                datalst.append(current.data)
                current = current.right
                
            else:
                done = True
                
    return True

def inOrder(root):
     
    # Set current to root of binary tree
    current = root 
    s = [] # initialze stack
    done = 0
    datalst = []
     
    while(not done):
         
        # Reach the left most Node of the current Node
        if current is not None:
             
            # Place pointer to a tree node on the stack 
            # before traversing the node's left subtree
            s.append(current)
         
            current = current.left 
 
         
        # BackTrack from the empty subtree and visit the Node
        # at the top of the stack; however, if the stack is 
        # empty you are done
        else:
            if(len(s) >0 ):
                current = s.pop()
                datalst.append(current.data)
         
                # We have visited the node and its left 
                # subtree. Now, it's right subtree's turn
                current = current.right 
 
            else:
                done = 1
    
    return datalst
