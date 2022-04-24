/*

-------------------MERGE SORT----------------------
int i=0,j=0,k=beg;
while(i < mid-beg+1 && j < end-mid) 
    if(L[i] <= R[j])
        a[k++] = L[i]
    else
        a[k++] = R[j]

while(i < mid-beg+1)
    a[k++] = L[i]
while(j < end-mid)
    a[k++] = R[j]


------------------QUICK SORT------------------------
if(first < last){
    pivot = first
    i = first
    j = last
    while(i<j){
        while(a[i] <= a[pivot] && i < last)
            i++
        while(a[j] >= a[pivot] && j >= 0)
            j--
        if(i<j)
            swap(a[i], a[j])
    }
    swap(a[j], pivot)
    quicksort(a, first, j-1)
    quicksort(a, j-1, last)
}

-------------------------HEAP SORT-------------------------------
----heapify----
large = i
L = 2i+1
R = 2i+2
if(a[L] > a[i] && L < size)
    large = L
if(a[R] > a[i] && R < size)
    large = R
if(large != i) {
    swap(a[i], a[large])
    heapify(a, size, largw)
}
----sort----
for(i= size/2 -1;i>=0 ;i--)
    heapify(a,size,i)
for(i=size-1; i>=0;i--) {
    swap(a[0],a[i])
    heapify(a, i,0)
}


------------------------INSERTION SORT--------------------------
for (i = 0; i < size; i++)
{
    j, temp = a[i];
    for (j = i - 1; temp < a[j] && j >= 0; j--)
        a[j + 1] = a[j];
    a[j + 1] = temp;
}


--------------------LEAF COUNT-------------------------
if(root == NULL)
    return 0;
if(root->left == NULL && root->right == NULL)
    return 1;
else
    return countLeafs(root->left) + countLeafs(root->right);





*/