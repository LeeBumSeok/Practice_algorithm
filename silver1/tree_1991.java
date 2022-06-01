package silver1;

import java.io.*;

interface BinNode {
    public char element();

    public char setElement(char item);

    public BinNode left();

    public BinNode right();

    public void setLeft(BinNode n);

    public void setRight(BinNode n);
}

class INode implements BinNode {
    private char data;
    private BinNode l, r;

    public INode(char data, BinNode l, BinNode r) {
        this.data = data;
        this.l = l;
        this.r = r;
    }

    @Override
    public char element() {
        return data;
    }

    @Override
    public char setElement(char item) {
        return this.data = item;
    }

    @Override
    public BinNode left() {
        return l;
    }

    @Override
    public BinNode right() {
        return r;
    }

    @Override
    public void setLeft(BinNode n) {
        this.l = n;
        
    }

    @Override
    public void setRight(BinNode n) {
        this.r = n;
        
    }
}

class Tree {
    public BinNode root;

    public void insert(char data, char l, char r) {
        if(root == null) {
            root = new INode(data, null, null);

            if(l != '.') {
                root.setLeft(new INode(l, null, null));
            }
            if(r != '.') {
                root.setRight(new INode(r, null, null));
            }
        }
        else {
            find(data, l, r, root);
        }
    }

    public void find(char data, char l, char r, BinNode rt) {
        if(rt == null) {
            return;
        }
        if(rt.element() == data) {
            if(l != '.') {
                rt.setLeft(new INode(l, null, null));
            }
            if(r != '.') {
                rt.setRight(new INode(r, null, null));
            }
        }
        else {
            find(data, l, r, rt.left());
            find(data, l, r, rt.right());
        }
        
    }

    public static void preorder(BinNode rt) {
        if (rt == null) return;
        System.out.print(rt.element());

        preorder(rt.left());
        preorder(rt.right());
    }

    public static void inorder(BinNode rt) {
        if (rt == null) return;

        inorder(rt.left());
        System.out.print(rt.element());
        inorder(rt.right());
    }

    public static void postorder(BinNode rt) {
        if (rt == null) return;

        postorder(rt.left());
        postorder(rt.right());
        System.out.print(rt.element());
    }
}

public class tree_1991 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Tree tree = new Tree();

        for(int i = 0; i < N; i++) {
            char[] node;
            node = br.readLine().replaceAll(" ", "").toCharArray();
            tree.insert(node[0], node[1], node[2]);
        }

        Tree.preorder(tree.root);
        System.out.println();
        Tree.inorder(tree.root);
        System.out.println();
        Tree.postorder(tree.root);
        
        br.close();
    }
}
