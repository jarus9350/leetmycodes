// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* parent;
// };


class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> parentsP;
        parentsP.insert(p);
        while (p){
            if (p->parent) parentsP.insert(p->parent);
            p = p->parent;
        }

        if (parentsP.find(q) != parentsP.end()){
                return q;
        }

        while (q){
            if (q->parent){
                if (parentsP.find(q->parent) != parentsP.end()){
                    return q->parent;
                }
            }
            q = q->parent;
        }

        return nullptr;


        
    }
};