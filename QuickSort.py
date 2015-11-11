#############################################
#To implement QuickSort
############################################
def QuickSort(data, leftIndex, rightIndex):
    if(leftIndex < rightIndex ):
        int p = partition(data, leftIndex, rightIndex)
        QuickSort( data, leftIndex, p)
        QuickSort( data, p+1, rightIndex)

def Partition(data, leftIndex, rightIndex):

