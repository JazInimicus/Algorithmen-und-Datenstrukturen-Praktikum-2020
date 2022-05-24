/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <stack>


////////////////////////////////////
// Ihr Code hier:

Tree::Tree()
{
    anker = nullptr;
    NodeIDCounter = 0;
};


void Tree::addNode(string Name, int Alter, double Einkommen, int PLZ)
{
    //Rechnung nochmal hier für nodePos.
    int nodePos = Alter + PLZ + (int)Einkommen;

    //Fall: leerer Baum

    TreeNode* node = new TreeNode(NodeIDCounter, Name, Alter, Einkommen, PLZ);

    if (anker == nullptr)
    {
        anker = node;
    }
    //Fall2: nicht leerer Baum
    else
    {
        TreeNode* iterator = anker;
        while (iterator != node)
        {
            if (nodePos < iterator->getNodePosID())
            {
                // Linker Teilbaum
                if (iterator->getLeft() == nullptr)
                {
                    iterator->setLeft(node);
                }

                iterator = iterator->getLeft();

            }
            else if (nodePos > iterator->getNodePosID())
            {
                // Rechter Teilbaum
                if (iterator->getRight() == nullptr)
                {
                    iterator->setRight(node);
                }

                iterator = iterator->getRight();

            }
            else
            {
                delete node;
                return;
            }
        }

    }

    NodeIDCounter++;


};

void Tree::deleteNode(int NodePosID)                                       
{
    TreeNode* parent = nullptr;
    TreeNode* node = anker;

    // Suche nach Knoten anhand des Keys
    while (node != nullptr && node->getNodePosID() != NodePosID)
    {
        if (NodePosID < node->getNodePosID())
        {
            // Gehe nach links
            parent = node;
            node = node->getLeft();

        }
        else {
            // Gehe nach rechts
            parent = node;
            node = node->getRight();

        }
    }

    // Knoten nicht gefunden
    if (node == nullptr) return;


    // Bestimme Anzahl der Nachfolger
    if (node->getLeft() != nullptr && node->getRight() != nullptr)
    {
        // 2 Nachfolger

        // Bestimme kleinsten Node des rechten TB
        TreeNode* minorN_parent = node;
        TreeNode* minorN = minorNode(node->getRight(), minorN_parent);

        // Bereite minorN darauf vor, den Platz des Knotens einzunehmen und entferne das minorN
        minorN->setLeft(node->getLeft());
        minorN_parent->setLeft(minorN->getRight());
        if (minorN_parent != node) {
            minorN->setRight(node->getRight());
        }

        // Korrigiere Anker
        if (node == anker) anker = minorN;
        else {

            // Setze Kind des Elternknoten
            if (parent->getLeft() == node) parent->setLeft(minorN);
            else parent->setRight(minorN);
        }

    }
    else
    {
        // 0 Nachfolger (Blatt) oder 1 Nachfolger (Links/Rechts).
        TreeNode* successor = nullptr;

        if (node->getLeft() != nullptr) successor = node->getLeft();
        else if (node->getRight() != nullptr) successor = node->getRight();

        // Wenn an dieser Stelle successor == nullptr => Knoten ist Blatt,
        // andernfalls steht in successor der einzige Kindknoten

        if (node != anker)
        {
            if (parent->getLeft() == node) parent->setLeft(successor);
            else parent->setRight(successor);

        }
        else
        {
            anker = successor;
        }


    }

    // Lösche Knoten
    delete node;


};

TreeNode* Tree::minorNode(TreeNode* node, TreeNode*& parent)                
{
    if (node == nullptr) return nullptr;

    while (node->getLeft() != nullptr)
    {
        parent = node;
        node = node->getLeft();
    }

    return node;
}

bool Tree::searchNode(string Name)                                             
{
    bool found_any = false;
    std::stack<TreeNode*> stack;

    if (anker != nullptr) {
        stack.push(anker);

        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            if (node->getRight() != nullptr) stack.push(node->getRight());
            if (node->getLeft() != nullptr) stack.push(node->getLeft());

            if (node->getName() == Name) {
                if (!found_any) {
                    std::cout << "+ Fundstellen: " << std::endl;
                }

                found_any = true;
                node->print();
            }
        }
    }

    if (!found_any) {
        std::cout << "+ Nichts gefunden" << std::endl;
    }

    return found_any;

};

void Tree::printAll()                                                        
{
    std::stack<TreeNode*> stack;
    if (anker == nullptr) {
        std::cout << "Leer." << std::endl;
        return;
    }

    cout << "ID  | Name          | Alter | Einkommen      | PLZ | Pos" << endl;
    cout << "----+---------------+-------+----------------+-----+-------" << endl;

    stack.push(anker);
    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();

        if (node->getRight() != nullptr) stack.push(node->getRight());
        if (node->getLeft() != nullptr) stack.push(node->getLeft());
        std::cout << std::setw(3) << std::left << node->getNodeID() << "|"
            << std::setw(12) << std::right << node->getName() << "|"
            << std::setw(7) << std::right << node->getAlter() << "|"
            << std::setw(11) << std::right << node->getEinkommen() << "|"
            << std::setw(7) << std::right << node->getPLZ() << "|"
            << std::setw(7) << std::left << node->getNodePosID() << std::endl;
    }
};

//
////////////////////////////////////