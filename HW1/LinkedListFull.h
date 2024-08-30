#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T element;     // Element contained in the node
    Node<T> *next; // Pointer to the next node

    Node() // No-arg constructor
    {
        next = NULL;
    }

    Node(T element) // Constructor
    {
        this->element = element;
        next = NULL;
    }
};

template <typename T>
class LinkedList
{
public:
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void addFirst(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;

        if (tail == NULL)
            tail = head;
    }
    void addLast(T element)
    {
        if (tail == NULL)
        {
            head = tail = new Node<T>(element);
        }
        else
        {
            tail->next = new Node<T>(element);
            tail = tail->next;
        }

        size++;
    }
    T getFirst() const
    {
        if (size == 0)
            cout << ("Index out of range");
        else
            return head->element;
    }
    T getLast() const
    {
        if (size == 0)
            cout << ("Index out of range");
        else
            return tail->element;
    }
    T removeFirst()
    {
        if (size == 0)
            cout << ("No elements in the list");
        else
        {
            Node<T> *temp = head;
            head = head->next;
            size--;
            T element = temp->element;
            delete temp;
            return element;
        }
    }

    /**
     * @brief remove the element of the last node in the linked list
     *
     * @param cur, Node<T>*
     *
     * @return the element of removed node
     *
     * Time Complexity: O(n), because the fct need to go through the list to set the second last node to be a new tail
     *                  O(1), only there is 1 or less element in the list
     *
     */
    T removeLast(Node<T>* cur) {
        if (cur->next->next == nullptr) {
            T element = tail->element;
            delete tail;
            tail = cur;
            tail->next = nullptr;
            size--;
            return element;
        }

        return removeLast(cur->next);
    }

    /**
     * @brief remove the element of the last node in the linked list
     *
     * @param none
     *
     * @return the element of removed node
     *
     * Time Complexity: O(n), because the fct need to go through the list to set the second last node to be a new tail
     *                  O(1), only for adding into the front or the end of the list
     *
     */
    T removeLast()
    {
        if (size == 0)
            cout << ("No elements in the list");
        else if (size == 1)
        {
            Node<T> *temp = head;
            head = tail = NULL;
            size = 0;
            T element = temp->element;
            delete temp;
            return element;
        }
        else
        {
            Node<T>* temp = head;
            return removeLast(temp);
        }
    }

    /**
     * @brief add a new node with provided element to specific position in the list
     *
     * @param index, int; element, T; cur, Node<T>*
     *
     * @return none
     *
     * Time Complexity: O(n), because the fct need to go through the list to the specific position
     *
     */
    void add(int index, T element, Node<T>* cur) {
        if (index == 1) {
            Node<T>* temp = new Node<T>(element);
            temp->next = cur->next;
            cur->next = temp;
            size++;
        } else {
            add(index--, element, cur->next);
        }
    }

    /**
     * @brief add a new node with provided element to specific position in the list
     *
     * @param index, int; element, T
     *
     * @return none
     *
     * Time Complexity: O(n), because the fct need to go through the list to the specific position
     *
     */
    void add(int index, T element)
    {
        if (index == 0)
            addFirst(element);
        else if (index >= size)
            addLast(element);
        else if (index == 1) {
            Node<T>* temp = new Node<T>(element);
            temp->next = head->next;
            head->next = temp;
            size++;
        } else
        {
            Node<T>* temp = new Node<T>(element);
            add(index, element, temp);
        }
    }

    /**
     * @brief clear up all the node in the list
     *
     * @param cur, Node<T>*
     *
     * @return none
     *
     * Time Complexity: O(n), because the fct need to go through the whole list
     *
     */
    void clear(Node<T>* cur) {
        if (size == 1) {
            size--;
            delete tail;
            tail = nullptr;
        } else {
            size--;
            clear(cur->next);
            delete cur;
            cur = nullptr;
        }
    }

    /**
     * @brief clear up all the node in the list
     *
     * @param none
     *
     * @return none
     *
     * Time Complexity: O(n), because the fct need to go through the whole list
     *
     */
    void clear()
    {
        if (size == 0)
            cout << "No elements in the list" << endl;
        else if (size == 1) {
            delete head;
            head = nullptr;
            size--;
        }
        else
            clear(head);
    }

    /**
     * @brief finds whether a specific element is in the list
     *
     * @param element, T; cur, Node<T>*
     *
     * @return whether a specific element is in the list
     *
     * Time Complexity: O(n), because the fct need to go through the whole list
     *
     */
    bool contains(T element, Node<T>* cur) {

        if (cur == nullptr)
            return false;

        if (cur->element == element)
            return true;

        return contains(element, cur->next);
    }

    /**
     * @brief finds whether a specific element is in the list
     *
     * @param element, T
     *
     * @return whether a specific element is in the list
     *
     * Time Complexity: O(n), because the fct need to go through the whole list
     *
     */
    bool contains(T element)
    {
        if (head == nullptr)
            return false;

        Node<T>* temp = head;
        return contains(element, temp);
    }

    T get(int index) const
    {
        if (index < 0 || index > size - 1)
            cout << ("Index out of range");

        Node<T> *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;

        return current->element;
    }
    int indexOf(T element) const
    {
        // Implement it in this exercise
        Node<T> *current = head;
        for (int i = 0; i < size; i++)
        {
            if (current->element == element)
                return i;
            current = current->next;
        }

        return -1;
    }
    bool isEmpty() const
    {
        return head == NULL;
    }
    int lastIndexOf(T element) const
    {
        int lastIndex = -1;
        Node<T> *current = head;
        for (int i = 0; i < size; i++)
        {
            if (current->element == element)
                lastIndex = i;
            current = current->next;
        }

        return lastIndex;
    }

    int getSize() const
    {
        return size;
    }
    T remove(int index)
    {
        if (index < 0 || index >= size)
            cout << ("Index out of range");
        else if (index == 0)
            return removeFirst();
        else if (index == size - 1)
            return removeLast();
        else
        {
            Node<T> *previous = head;

            for (int i = 1; i < index; i++)
            {
                previous = previous->next;
            }

            Node<T> *current = previous->next;
            previous->next = current->next;
            size--;
            T element = current->element;
            delete current;
            return element;
        }
    }
    T set(int index, T element)
    {
        if (index < 0 || index >= size)
            cout << ("Index out of range");

        Node<T> *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        T oldElement = current->element;
        current->element = element;
        return oldElement;
    }

    /**
     * @brief print all elements in the list
     *
     * @param cur, Node<T>*
     *
     * @return none
     *
     * Time Complexity: O(n), because the fct need to go through the whole list
     *
     */
    void Show(Node<T>* cur) {

        cout << cur->element;

        if (cur->next != nullptr) {
            cout << " -> ";
            Show(cur->next);
        }
        else
            cout << endl;
    }

    /**
     * @brief print all elements in the list
     *
     * @param none
     *
     * @return none
     *
     * Time Complexity: O(n), because the fct need to go through the whole list
     *
     */
    void Show()
    {
        if (size == 0)
            cout << "No elements in the list" << endl;
        else if (size == 1)
            cout << head->element << endl;
        else {
            Node<T> *temp = head;
            Show(temp);
        }
    }

private:
    Node<T> *head, *tail;
    int size;
};

#endif
