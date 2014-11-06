
void
    displayList(Node *items)
        {
        while (items != 0)
            {
            int v = head(items)
            printf("{%d}",v);
            items = tail(items); //take a step
            }
        printf("\n");
        }