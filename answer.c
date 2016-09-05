int container_max(int *l, int *r, int len);

int store = 0;

int maxArea(int* height, int heightSize) 
{
    if (NULL==height || heightSize<=1)
        return 0;
    
    store = 0;
    return container_max(&(height[0]), &(height[heightSize-1]), heightSize-1);
}

int container_max(int *l, int *r, int len)
{
    int len_tmp = len;
    int h_tmp = 0;
    int ret_tmp = 0;
    int *pos = NULL;

    if (*l == *r)
    {
        if ((ret_tmp=*l*len) > store)
            store = ret_tmp;
        if (r <= l+2)
            return store;
        return container_max(l+1, r-1, len-2);
    }
    else if (*l > *r)
    {
        pos = r;
        do
        {
            if (--pos <= l)
            {
                if ((ret_tmp=*r*len) > store)
                {
                    store = ret_tmp;
                    if (r <= l+2)
                        return store;
                    return container_max(l+1, r-1, len-2);
                }
                else
                    return store;
            }
            len_tmp--;
            h_tmp = *pos;
            if (h_tmp > *l)
                h_tmp = *l;
        }while(((*r)*len) >= (h_tmp*len_tmp));
        return container_max(l, pos, len_tmp);
    }
    else
    {
        pos = l;
        do
        {
            if (++pos >= r)
            {
                if ((ret_tmp=*l*len) > store)
                {
                    store = ret_tmp;
                    if (r <= l+2)
                        return store;
                    return container_max(l+1, r-1, len-2);
                }
                else
                    return store;
            }
            len_tmp--;
            h_tmp = *pos;
            if (h_tmp > *r)
                h_tmp = *r;
        }while(((*l)*len) >= (h_tmp*len_tmp));
        return container_max(pos, r, len_tmp);
    }
}
