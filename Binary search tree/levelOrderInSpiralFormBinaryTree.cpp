>>Traversal of binary tree in spiral form or Zig Zag Level Order traversal is same

>>recursive
/* Worst case time complexity of the above method is O(n^2). Worst case occurs in case of skewed trees.
*/
void wrapper(root)
{ //wrapper starts
int h=height(root);
int flag=false;

   for(i=1;i<=h;i++)
   {
    fun(root,flag,level);
    flag=!flag;
   }

}// wrapper ends

void fun(root,flag,level) //fun starts
{
    if(!root)
        return;

    if(level==1)
   cout<<root->key;
else
    if(level>1)
{
    if(flag)
    {
        fun(root->right,flag,level-1);
        fun(root->left,flag,level-1);
    }
    else
    {
        fun(root->left,flag,level-1);
        fun(root->right,flag,level-1);


    }
}

} //fun ends
//--------------------------------------------------------------------------------------------------

>>iterative :O(n) time and space, using two stacks
