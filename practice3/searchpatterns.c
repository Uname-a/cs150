void
    append(Node *listA,Node *listB) //listA length must be > 0
        {
        while (tail(listA) != 0)
            {
            listA = tail(listA); //move to the next node in the list
            }
        setTail(listA,listB);
        return;
        }
 Node *
    reverseList(Node *a)
        {
        Node *items = 0;
        while (a != 0)
            {
            items = join(head(a),items);
            a = tail(a);
            }
        return items;
        }
int
    getListIndex(Node *items,int index)
        {
        while (index > 0)
            {
            items = tail(items);
            --index;
            }
        return head(items);
        }
Node *
    findInteger2(int value,Node *items)
        {
        while (items != 0)
            {
            if (head(items) == value)
                 {
                 return items;
                 }
            items = tail(items);
            }
        return 0;
        }
Node *
    getPenultimateNode(Node *items)
        {
        Node *trailing = 0;
        Node *leading = items;
        while (tail(leading) != 0) //when to stop walking
            {
            trailing = leading;
            leading = tail(leading);
            }
        return trailing;
        }
void
    insertIntegerInOrder(int value,Node *items)
        {
        Node *trailing = 0;
        Node *leading = items;
        while (...) //when to keep walking
            {
            trailing = leading;
            leading = tail(leading);
            }
        //insert new value in between trailing and leading
        ...
        }

void
    insertInOrder(int value,Node *items)
        {
        Node *trailing = 0;
        Node *leading = items;
        while (head(leading) < value) //when to keep walking
            {
            trailing = leading;
            leading = tail(leading);
            }
        //insert new value in between trailing and leading
        Node *n = newNode(value,0);
        setTail(n,leading);     //place n before leading
        setTail(trailing,n);    //place n after trailing
        }
int
    length(Node *items)
        {
        int count = 0;
        while (items != 0)                //typical list walking condition
            {
            ++count;
            items = tail(items);          //typical list walking step
            }
        }
int
    sumEvenIntegers(Node *items)
        {
        int total = 0;
        while (items != 0)
            {
            int v = head(items);
            if (v % 2 == 0)
                total += v;
            items = tail(items);
            }
        return total;
        }
Node *
    copyList(Node *items)
        {
        Node *result = 0;   //resulting list starts out empty
        Node *spot = items;
        while (spot != 0)           //walk the list
            {
            result = join(head(items),result); //add current value to result
            spot = tail(spot);                //take a step
            }
        return result;
        }
Node *
    extractEvens(Node *items)
        {
        Node *result = 0;
        while (items != 0)
            {
            int v = head(items);
            if (isEven(v))
                result = join(head(items),result);
            items = tail(items);
            }
        return result;
        }
void
    freeList(Node *items)
        {
        Node *spot;
        while(items != 0)
            {
            spot = items;
            items = tail(items);
            free(spot->value);
            free(spot);                //free the current node
            }
        }