import math

def main():
    l = int(input().strip())
    r = int(input().strip())
    
    segments = []
    
    cur = l
    level = 21
    seglen = 0
    nextseglen = -1
    start = 0
    end = 0
    diff = 0
    
    while cur <= r:
        
        while 22 > level > -1:
            
            if level is 0: seglen = 10
            else: seglen = 10**(2**(level-1)) #if only binary rep could be considered as int
            
            start = cur
            diff = cur % seglen
            if diff and level is 0: end = math.ceil(cur/seglen) * seglen
            
            elif diff: end = math.ceil(cur/seglen) * seglen
                
            nextseglen = seglen
            
    '''while cur <= r:
        nextlevelval = int(cur / 10)
        diff = cur - nextlevelval*10
        if diff is not 0:
            level = 0
            length = 0
            start = cur
            end = cur + 10 - diff
        else:
            for level in range(20,0,-1):
                length = 10**(2**(level-1))
                if cur % length  is 0:
                    nextlevelval = int(cur / length)
                    diff = cur - nextlevelval*length
                    start = cur
                    end = cur + length - diff'''
            
        