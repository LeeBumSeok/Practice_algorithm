package gold5;

import java.io.*;
import java.util.*;

class Node {
    int data;
    Node parent;
    ArrayList<Node> child = new ArrayList<>();

    Node(int data) {
        this.data = data;
    }
}


class Tree {
    public Node root;
    int leaf = 0;

    public void insert(Node node) {
        node.parent.child.add(node);
    }

    public void remove(Node node) {
        for(Iterator<Node> itr = node.parent.child.iterator(); itr.hasNext();){
            if(itr.next() == node) {
                itr.remove();
            }
        }
    }

    public void leafCount(Node node) {
        if (!node.child.isEmpty()) {
            for(Node nd : node.child) {
                leafCount(nd);
            }
        }
        else {
            leaf++;
        }
    }
}

public class tree_1068 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int RN = Integer.parseInt(br.readLine());

        ArrayList<Integer> nodeParent = new ArrayList<>();
        while(st.hasMoreTokens()) {
            nodeParent.add(Integer.parseInt(st.nextToken()));
        }

        ArrayList<Node> nodeList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            nodeList.add(new Node(i));
        }

        Tree tree = new Tree();

        for(int i = 0; i < nodeParent.size(); i++) {
            if(nodeParent.get(i) == -1) {
                nodeList.get(i).parent = null;
                tree.root = nodeList.get(i);
            }
            else {
                nodeList.get(i).parent = nodeList.get(nodeParent.get(i));
                tree.insert(nodeList.get(i));
            }
        }

        if(nodeList.get(RN).parent == null) {
            System.out.println(0);
        }
        else {
            tree.remove(nodeList.get(RN));
            tree.leafCount(tree.root);
            System.out.println(tree.leaf);
        }
    }
}