void inorder(struct node *p)
{ if(p!=NULL)
{ inorder(p-&gt;left);
printf(&quot;%d &quot;,p-&gt;data);
inorder(p-&gt;right);
}
}
Struct node
{ struct node *left;
Int data;
Struct node *right;
}

ROOT50
