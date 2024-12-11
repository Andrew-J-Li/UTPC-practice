package Graphs;

import java.util.Stack;

public class SplayTree {
    private TreeNode root;

    private class TreeNode {
        private TreeNode parent, left, right;
        private int val;

        public TreeNode(TreeNode parent, int val) {
            this.parent = parent;
            this.val = val;
        }
    }
    
    public void insert(int val) {
        if (root == null) {
            root = new TreeNode(null, val);
            return;
        }

        TreeNode curr = root;
        addNode(curr, val);
    }

    private void addNode(TreeNode curr, int val) {
        if (curr.val == val) {
            return;
        }

        if (val > curr.val) {
            if (curr.right == null) {
                curr.right = new TreeNode(curr, val);
                splay(curr.right);
            } else {
                addNode(curr.right, val);
            }
        } else {
            if (curr.left == null) {
                curr.left = new TreeNode(curr, val);
                splay(curr.left);
            } else {
                addNode(curr.left, val);
            }
        }
    }

    private void splay(TreeNode curr) {
        if (curr == root) return;
        if (curr.parent == root) {
            if (root.left == curr) {
                rotateRight(curr.parent);
            } else {
                rotateLeft(curr.parent);
            }
            return;

        } else if (curr == curr.parent.left) {
            if (curr.parent == curr.parent.parent.left) {
                rotateRight(curr.parent.parent);
                rotateRight(curr.parent);
            } else {
                rotateRight(curr.parent);
                rotateLeft(curr.parent);
            }

        } else if (curr == curr.parent.right) {
            if (curr.parent == curr.parent.parent.right) {
                rotateLeft(curr.parent.parent);
                rotateLeft(curr.parent);
            } else {
                rotateLeft(curr.parent);
                rotateRight(curr.parent);
            }
        }

        splay(curr);
    }
    
    private void rotateRight(TreeNode root) {
        boolean changeRoot = false;
        if (this.root == root) {
            changeRoot = true;
        }

        TreeNode newRoot = root.left;
        root.left = root.left.right;
        if (root.left != null) root.left.parent = root;
        newRoot.right = root;
        newRoot.parent = root.parent;

        if (root.parent != null) {
            if (root.parent.left == root) root.parent.left = newRoot;
            else root.parent.right = newRoot;
        }

        root.parent = newRoot;
        if (changeRoot) this.root = newRoot;
    }

    private void rotateLeft(TreeNode root) {
        boolean changeRoot = false;
        if (this.root == root) {
            changeRoot = true;
        }

        TreeNode newRoot = root.right;
        root.right = root.right.left;
        if (root.right != null) root.right.parent = root;
        newRoot.left = root;
        newRoot.parent = root.parent;

        if (root.parent != null) {
            if (root.parent.left == root) root.parent.left = newRoot;
            else root.parent.right = newRoot;
        }

        root.parent = newRoot;
        if (changeRoot) this.root = newRoot;
    }

    public void remove(int val) {
        if (root == null) return;

        TreeNode victim = find(this.root, val);
        TreeNode leftRoot = victim.left;
        TreeNode rightRoot = victim.right;

        TreeNode curr = leftRoot;
        while (curr.right != null) {
            curr = curr.right;
        }

        leftRoot.parent = null;
        root = leftRoot;
        splay(curr);
        curr.right = rightRoot;
        rightRoot.parent = curr;
    }

    private TreeNode find(TreeNode curr, int val) {
        if (val == curr.val) {
            splay(curr);
            return curr;
        }
        if (val < curr.val) {
            if (curr.left == null) {
                splay(curr);
                return null;
            } else return find(curr.left, val);
        } else {
            if (curr.right == null) {
                splay(curr);
                return null;
            } else return find(curr.right, val);
        }
    }


    @Override
    public String toString() {
        StringBuilder rslt = new StringBuilder();
        if (root == null) return "";
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> tabs = new Stack<>();
        stack.add(root);
        tabs.add(0);
        
        while (!stack.isEmpty()) {
            TreeNode currNode = stack.pop();
            int currTabs = tabs.pop();
            rslt.append("\t".repeat(currTabs));

            rslt.append(currNode.val + "\n");
    
            if (currNode.right != null) {
                stack.add(currNode.right);
                tabs.add(currTabs + 1);
            }

            if (currNode.left != null) {
                stack.add(currNode.left);
                tabs.add(currTabs + 1);
            }
        }

        return rslt.toString();
    }

    public static void main(String[] args) {
        SplayTree st = new SplayTree();
        st.insert(1);
        System.out.println(st);

        st.insert(2);
        System.out.println(st);

        st.insert(3);
        System.out.println(st);

        st.insert(4);
        System.out.println(st);

        st.insert(5);
        System.out.println(st);

        st.insert(6);
        System.out.println(st);

        st.insert(7);
        System.out.println(st);

        st.find(st.root, 1);
        System.out.println(st);

        st.remove(3);
        System.out.println(st);
    }
}