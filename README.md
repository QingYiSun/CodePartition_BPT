# CodePartition_BPT

## BPT算法(邱锡鹏)

### Binary Partitioning

从一个完整的句子开始BP，直到每个结点粒度为一个单词。

划分后得到一棵满二叉树，所以，一个包含n个单词的句子经划分后得到2n-1个不同粒度的结点。

### Nodes

**Token Nodes**: 叶子结点(n个)

**Span Nodes**: 内部结点(n-1个)

### Edges

**Bottom-up Fashion**: 叶子结点所在的那一层为第0层

**约减信息传输的距离**: 不直接使用树结构去构造图中的边

**Affiliated Edges**: 有向边，指向所有祖先结点(约减了span nodes和它们对应token nodes间的距离)

**Contextual Edges**: 捕捉上下文信息，在每一层，向左、向右分别找k个结点指向自己
