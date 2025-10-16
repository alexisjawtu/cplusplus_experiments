
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
            if (maximo<v[i])
            {
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
       int posmax=desde;
       for(int i=desde + 1;i<hasta+1;i++)
       {
            if (v[posmax]<v[i])
            {
                 posmax=i;
            }
       }
       return posmax;
}

void sort(int desde,int hasta,int v[])

{

    for(int i=hasta; i > desde; i--)

    {
        int j=posmax(desde,i,v);

        int k = v[i];

        v[i] = v[j];

        v[j] = k;

    }

}

int mediana(int n,int v[])
{
       int mediana=0;
       sort(0,n-1,v);
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
    sort(0, n-1, v);
    int i = 0;

    int moda = v[0];
    int largo_moda = 1;
    while (i<n)
    {
        int largo_actual = 1;

        while (i+1 < n && v[i] == v[i+1])
        {
            largo_actual = largo_actual + 1;
            i = i+1;
        }
        if (largo_moda < largo_actual)
        {
            moda = v[i];
            largo_moda = largo_actual;
        }
        i = i+1;
    }
    return moda;
}
