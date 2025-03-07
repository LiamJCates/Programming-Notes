Complete Binary Trees

    A complete binary tree is a binary tree that satisfies two properties. First, in a complete binary tree, every level, except possibly the last, is completely filled. Second, all nodes appear as far left as possible. In a complete binary tree Tn , there are exactly n nodes and level r of T can have at most 2r nodes.
    A complete binary tree can be represented in an array in the following approach. If root node is stored at index i, its left, and right children are stored at indices 2*i+1, 2*i+2 respectively.
