#include "list.h"

List::List()
{
    head.next = head.previous = 0;
}

void List::initialize()
{
    head.next = head.previous = 0;
}

int List::size()
{
    ListItem *temp = head.next;
    int counter = 0;

    while (temp)
    {
        temp = temp->next;
        ++counter;
    }

    return counter;
}

bool List::empty()
{
    return size() == 0;
}

ListItem *List::back()
{
    ListItem *temp = head.next;
    if (!temp)
        return nullptr;

    while (temp->next)
    {
        temp = temp->next;
    }

    return temp;
}

void List::push_back(ListItem *itemPtr)
{
    ListItem *temp = back();
    if (temp == nullptr)
        temp = &head;
    temp->next = itemPtr;
    itemPtr->previous = temp;
    itemPtr->next = nullptr;
}

void List::pop_back()
{
    ListItem *temp = back();
    if (temp)
    {
        temp->previous->next = nullptr;
        temp->previous = temp->next = nullptr;
    }
}

ListItem *List::front()
{
    return head.next;
}

void List::push_front(ListItem *itemPtr)
{
    ListItem *temp = head.next;
    if (temp)
    {
        temp->previous = itemPtr;
    }
    head.next = itemPtr;
    itemPtr->previous = &head;
    itemPtr->next = temp;
}

void List::pop_front()
{
    ListItem *temp = head.next;
    if (temp)
    {
        if (temp->next)
        {
            temp->next->previous = &head;
        }
        head.next = temp->next;
        temp->previous = temp->next = nullptr;
    }
}

void List::insert(int pos, ListItem *itemPtr)
{
    if (pos == 0)
    {
        push_front(itemPtr);
    }
    else
    {
        int length = size();
        if (pos == length)
        {
            push_back(itemPtr);
        }
        else if (pos < length)
        {
            ListItem *temp = at(pos);

            itemPtr->previous = temp->previous;
            itemPtr->next = temp;
            temp->previous->next = itemPtr;
            temp->previous = itemPtr;
        }
    }
}

void List::erase(int pos)
{
    if (pos == 0)
    {
        pop_front();
    }
    else
    {
        int length = size();
        if (pos < length)
        {
            ListItem *temp = at(pos);

            temp->previous->next = temp->next;
            if (temp->next)
            {
                temp->next->previous = temp->previous;
            }
        }
    }
}

void List::erase(ListItem *itemPtr)
{
    ListItem *temp = head.next;

    while (temp && temp != itemPtr)
    {
        temp = temp->next;
    }

    if (temp)
    {
        temp->previous->next = temp->next;
        if (temp->next)
        {
            temp->next->previous = temp->previous;
        }
    }
}
ListItem *List::at(int pos)
{
    ListItem *temp = head.next;

    for (int i = 0; (i < pos) && temp; ++i, temp = temp->next)
    {
    }

    return temp;
}

int List::find(ListItem *itemPtr)
{
    int pos = 0;
    ListItem *temp = head.next;
    while (temp && temp != itemPtr)
    {
        temp = temp->next;
        ++pos;
    }

    if (temp && temp == itemPtr)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}