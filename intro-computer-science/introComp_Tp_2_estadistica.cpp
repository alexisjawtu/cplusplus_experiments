
double media(int n, int v[])
{
       int i=0;
       int suma=0;
       while (i<n)
       {
             suma=suma+v[i];
             i++;
             }
       double p=(double)suma/n;
       return p;
}

int fmax(int n, int v[])
{
       int i=0;
       int maximo=v[0];
       while (i<n)
       {
       if (maximo<v[i]){
                        maximo=v[i];
                        }
       i++;
       }
       return maximo;
}

int fmin(int n, int v[])
{
       int k=1;
       int minimo=v[0];
       while (k<n)
       {
             if (minimo>v[k])
             {
                             minimo=v[k];
             }
             k++;
       }
       return minimo;
}


int posmax(int desde,int hasta, int v[])
{
       int posmax=hasta;
       for(int i=hasta;i<desde+1;i++)
       {
       if (v[posmax]<v[i]){
                        posmax=i;
                        }
       }
       return posmax;
}

void sort(int desde,int hasta,int v[])
{
       int j=0;
       for(int i=0;i<hasta+1;i++)
       {
       j=posmax(desde,hasta-i,v);
       int k = v[hasta-i];
       v[hasta-i] = v[j];
       v[j] = k;
       }
}

int mediana(int n,int v[])
{
       int mediana=0;
       sort(0,n,v);
       if(n%2==0)
       {
       mediana=v[(n/2)-1];
       }
       else
       {
       mediana=v[(n-1)/2] ;
       }
       return mediana;
}

int moda(int n, int v[])
{
    int i = 0;
    int moda = v[0];
    int k = 1;
    int r = 1;
    sort(0, n, v);
    while (i<n)
    {
        while (v[i] == v[i+1] && i+1<n)
        {
            k = k+1;
            i = i+1;
        }
        if (r<k)
        {
            moda = v[i];
            r = k;
            k = 1;
        }
        k = 1;
        i = i+1;
    }
    return moda;
}
