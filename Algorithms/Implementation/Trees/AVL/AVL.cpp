#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;
struct node {
   int d;
   struct node* left;
   struct node* right;
}*r;
class avl_tree {
   public:
      int height(node* );
      int difference(node* );
      node* rr_rotat(node* );
      node* ll_rotat(node* );
      node* lr_rotat(avl*);
      node* rl_rotat(node* );
      node*  balance(node* );
      node*  insert(avl*, int);
      void show(avl*, int);
      void inorder(node* );
      void preorder(node* );
      void postorder(avl*);
      avl_tree()
{
         r = NULL;
      }
};

int avl_tree::height(node* t)
{
   int h = 0;
   if (t != NULL)
{
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}

int avl_tree::difference(node* t)
{
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}

node* avl_tree::rr_rotat(node* parent)
{
   node* t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"Right-Right Rotation";
   return t;
}

node* avl_tree::ll_rotat(node* parent)
{
   node* t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"Left-Left Rotation";
   return t;
}

node* avl_tree::lr_rotat(node* parent)
{
   node* t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}

node* avl_tree::rl_rotat(node* parent)
{
   node* t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
node* avl_tree::balance(node* t)
{
   int bal_factor = difference(t);
   if (bal_factor > 1)
{
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1)
{
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
node* avl_tree::insert(node* r, int v)
{
   if (r == NULL)
{
      r = new avl;
      r->d = v;
      r->l = NULL;
      r->r = NULL;
      return r;
   } else if (v< r->d)
{
      r->l = insert(r->l, v);
      r = balance(r);
   } else if (v >= r->d)
{
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::show(node* p, int l)
{
   int i;
   if (p != NULL)
{
      show(p->r, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->d;
         show(p->l, l + 1);
   }
}

int main()
{
   int c, i;
   avl_tree avl;
   while (1)
{
      cout << "1.Insert Element into the tree" << endl;
      cout << "2.show Balanced AVL Tree" << endl;
      cout << "3.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c)
{
         case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = avl.insert(r, i);
         break;
         case 2:
            if (r == NULL)
{
               cout << "Tree is Empty" << endl;
               break;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(r, 1);
            cout<<endl;
         break;
         case 3:
            exit(1);
         break;
         default:
            cout << "Invalid choice, please input the number of a menu option" << endl;
      }
   }
   return 0;
}
