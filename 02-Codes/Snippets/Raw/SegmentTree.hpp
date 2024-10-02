#include <vector>
using namespace std;

template <typename T, T (*mergeFunc)(T, T, int)>
struct SegmentTree
{
   int m_size = 1;
   T m_id;
   std::vector<T> m_tree;

   SegmentTree(int size, T def) : m_size(size), m_id(def), m_tree(2 * m_size, def) {}

   void update(int pos, T val)
   {
      int depth = 0;
      for (m_tree[pos += m_size] = val; pos /= 2; depth++)
         m_tree[pos] = mergeFunc(m_tree[pos * 2], m_tree[pos * 2 + 1], depth);
   }

   T query(int qL, int qR)
   {
      T lRes = m_id, rRes = m_id;
      int depth = 0;
      for (qL += m_size, qR += m_size; qL < qR; qL /= 2, qR /= 2, depth++)
      {
         if (qL % 2)
            lRes = mergeFunc(lRes, m_tree[qL++], depth);
         if (qR % 2)
            rRes = mergeFunc(m_tree[--qR], rRes, depth);
      }
      return mergeFunc(lRes, rRes, depth);
   }
};

// query [qL, qR)
// 0-based, derived from kactl
//  SegmentTree<dataType, defaultValueToInitNodes, mergingFunction> segTree(10);

// using TreeNode = int;

// TreeNode merge(TreeNode a, TreeNode b, int depth)
// {
//    return TreeNode();
// }

// SegmentTree<TreeNode, merge>seg(n, TreeNode());
