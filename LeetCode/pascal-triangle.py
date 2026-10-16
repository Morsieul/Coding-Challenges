"""
For this solution every list member of a row was interpreted as a Block.
The idea is to create a list called pascal that's composed of other Block lists. 
The blocks are initilized with 1, because that's how every list of the problem starts. 
The while loop is used to create the number of Blocks, at the end of the process the new block is added to Pascal.
When there's only one Row the program ends right away using the initial Block with 1, but when more rows are required, it means 
that i > 0(the counting of rows in the program starts with zero, I.e numRows - 1), it's initialized a list called previous with 
the previous Block from Pascal, from there is used another loop to fill the new block, since each block starts with 1 already (in position 0)
the j variable starts with 1. For each j, the new Block will append the two elements j-1 and j from previous, these corresponds to the elements
above the current one in the triangle. When exiting the loop the final 1 is added and pascal appends the new block.
"""
class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        pascal = []
        i = 0

        while i < numRows:
            Block = [1]

            if i > 0:
                previous = pascal[i - 1]
                j = 1
            
                while(j < i):
                    Block.append(previous[j - 1] + previous[j])
                    j = j + 1

                Block.append(1)
        
            i= i + 1
            pascal.append(Block)
        
        return pascal       